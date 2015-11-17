#include "glwidget.h"
#include "cam.h"
#include "forklift.h"
#include "light.h"
#include "tga.h"

#include <QTimer>
#include <QDebug>
#include <QKeyEvent>

GLWidget::GLWidget(QWidget *parent) :
    QGLWidget(QGLFormat(QGL::SampleBuffers), parent)
{
    m_camera = new Cam();
    m_forklift = new Forklift();
    m_light = new Light();
    m_tga = new TGA();

    QTimer *timer = new QTimer(this);

    timer->setInterval(30);
    timer->start();
    connect(timer,SIGNAL(timeout()),SLOT(update()));
}

void GLWidget::initializeGL()
{
    //Cargo los modelos del montacargas
    m_forklift->load();

    glShadeModel(GL_SMOOTH);

    glClearColor(0,0,0,0.5);

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

    //Texturas
    if (m_tga->LoadTGA(&m_tga->textures[0],"../forklift/grass.tga"))
        qDebug() << "Cargo la textura";

    /* Aquí ajustamos algunos parámetros de la textura, concretamente los filtros de magnificación y mignificación*/
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    /*Como quiero pegar la imagen sobre el polígono*/
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S , GL_REPEAT );
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T , GL_REPEAT );
    glTexEnvi(GL_TEXTURE_ENV_MODE, GL_TEXTURE_ENV_MODE, GL_REPLACE);


    //m_light->setUp();

    glDepthFunc(GL_LEQUAL);
}

void GLWidget::paintGL()
{
    glClearColor(0.0, 0.3, 0.0, 1);

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();



    drawInfo();
    m_camera->setUp();

    m_light->setUp();

    m_forklift->draw();

    drawBox();

    glFlush();

}


void GLWidget::resizeGL(int width, int height)
{
    glViewport(0, 0 ,width, height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //Pespective projection
    gluPerspective(80.0, width/height, 1, 200);
}

void GLWidget::mouseMoveEvent(QMouseEvent *event)
{

}

void GLWidget::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {
    case Qt::Key_Escape:
        exit(0);
        break;

    case Qt::Key_F:
        if(isFullScreen()){
            showNormal();
        }
        else{
            showFullScreen();
        }
        break;
    case Qt::Key_W:  //Ir pa alante
        m_camera->zoomIn();
        break;
    case Qt::Key_S:  //Ir pa atras
        m_camera->zoomOut();
        break;
    case Qt::Key_A:  //Ir a la izquierda
        m_camera->goLeft();
        break;
    case Qt::Key_D: //Ir a la derecha
        m_camera->goRight();
        break;
    case Qt::Key_Q:  //Ir a arriba
        m_camera->goUp();
        break;
    case Qt::Key_E: //Ir a abajo
        m_camera->goDown();
        break;
    case Qt::Key_O: //Corre pa alante
        m_forklift->run();
        break;
    case Qt::Key_L: //Corre pa atras
        m_forklift->back();
        break;
    case Qt::Key_I: //Levanta brazo
        m_forklift->upArm();
        break;
    case Qt::Key_K: //Baja brazo
        m_forklift->downArm();
        break;
    case Qt::Key_C: //Enciende/Apaga el foco
        m_forklift->toogleFoco();
        break;


    case Qt::Key_R:
        m_camera->resetPosition();
        break;

    default:
        break;
    }


    QGLWidget::keyPressEvent(event);
}

void GLWidget::drawBox()
{

    glDisable(GL_CULL_FACE);



    glEnable(GL_TEXTURE_2D);
    glBegin ( GL_QUADS );

    // Front Face
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-7.0f, 0.0f,  -1.0f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f( -5.0f, 0.0f,  -1.0f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f( -5.0f,  2.0f,  -1.0f);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-7.0f,  2.0f,  -1.0f);
    // Back Face
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-7.0f, 0.0f, -1.0f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(-7.0f,  2.0f, -1.0f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f( -5.0f,  2.0f, -1.0f);
    glTexCoord2f(0.0f, 1.0f); glVertex3f( -5.0f, 0.0f, -1.0f);
    // Top Face
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-7.0f,  2.0f, -1.0f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(-7.0f,  2.0f,  1.0f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f( -5.0f,  2.0f,  1.0f);
    glTexCoord2f(0.0f, 1.0f); glVertex3f( -5.0f,  2.0f, -1.0f);
    // Bottom Face
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-7.0f, 0.0f, -1.0f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f( -5.0f, 0.0f, -1.0f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f( -5.0f, 0.0f,  1.0f);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-7.0f, 0.0f,  1.0f);
    // Right face
    glTexCoord2f(0.0f, 0.0f); glVertex3f( -5.0f, 0.0f, -1.0f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f( -5.0f,  2.0f, -1.0f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f( -5.0f,  2.0f,  1.0f);
    glTexCoord2f(0.0f, 1.0f); glVertex3f( -5.0f, 0.0f,  1.0f);
    // Left Face
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-7.0f, 0.0f, -1.0f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(-7.0f, 0.0f,  1.0f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(-7.0f,  2.0f,  1.0f);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-7.0f,  2.0f, -1.0f);

    glEnd();
    glDisable(GL_TEXTURE_2D);
    glEnable(GL_CULL_FACE);
}

void GLWidget::drawInfo()
{
    renderText(10,10,QString("Camera controls:"),QFont("Courier",11,4));
    renderText(10,20,QString("-----------------"),QFont("Courier",9,2));
    renderText(10,30,QString("Zoom In:  W"),QFont("Courier",9,2));
    renderText(10,40,QString("Zoom Out: S"),QFont("Courier",9,2));
    renderText(10,50,QString("Rotate right: D"),QFont("Courier",9,2));
    renderText(10,60,QString("Rotate left: A"),QFont("Courier",9,2));
    renderText(10,70,QString("Rotate up: Q"),QFont("Courier",9,2));
    renderText(10,80,QString("Rotate down: E"),QFont("Courier",9,2));

    renderText(10,110,QString("Forklift controls:"),QFont("Courier",11,4));
    renderText(10,120,QString("-----------------"),QFont("Courier",9,2));
    renderText(10,130,QString("Run:  O"),QFont("Courier",9,2));
    renderText(10,140,QString("Back: L"),QFont("Courier",9,2));

    renderText(10,170,QString("Arm controls:"),QFont("Courier",11,4));
    renderText(10,180,QString("-----------------"),QFont("Courier",9,2));
    renderText(10,190,QString("Put Up Arm:  I"),QFont("Courier",9,2));
    renderText(10,200,QString("Put Down Arm: K"),QFont("Courier",9,2));

}

void GLWidget::update()
{
    updateGL();
}
