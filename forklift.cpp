#include "forklift.h"
#include "includeUnix/glut.h"
#include "objscene.h"
#include "model_obj.h"
#include "material.h"

#include <QTimer>

float moveArm = 0;
float translate = 0;
float rotate = 15;
float WHEEL_RATIO = 1.25;
float sirenDiretion = -1;

Forklift::Forklift()
{
    m_chassis = new ObjScene();
    m_arm = new ObjScene();
    m_siren = new ObjScene();
    m_material = new material();

    m_focoOn = false;
    m_focoDiretion = -1;

    m_rotationVelocity = 0;
    m_translationVelocity = 0;

    for (int i=0; i<4; ++i)
        m_wheels[i] = new ObjScene();

    QTimer *timer = new QTimer();

    timer->setInterval(100);
    timer->start();
    QObject::connect(timer,SIGNAL(timeout()),SLOT(rotateFoco()));
}

void Forklift::run()
{
    translate += 1;
    rotate = translate / WHEEL_RATIO;

}

void Forklift::back()
{
    translate -= 1;
    rotate = translate / WHEEL_RATIO;
}

void Forklift::load()
{
    m_chassis->load(":OBJ/cuerpo.obj");
    m_arm->load(":OBJ/brazo.obj");
    m_siren->load(":OBJ/cono.obj");

    m_wheels[rueda_trasera_izquierda]->load(":OBJ/rueda_trasera_izquierda.obj");
    m_wheels[rueda_trasera_derecha]->load(":OBJ/rueda_trasera_derecha.obj");
    m_wheels[rueda_delantera_izquierda]->load(":OBJ/rueda_delantera_izquierda.obj");
    m_wheels[rueda_delantera_derecha]->load(":OBJ/rueda_delantera_derecha.obj");
}

void Forklift::draw()
{
    glPushMatrix();
    //glLoadIdentity();
      glTranslated(translate,0,0);

        //m_material->chassis();
        m_chassis->draw();

        //m_material->siren();
        if (m_focoOn)
            Foco();
        m_siren->draw();

//        /m_material->arm();
        glPushMatrix();
            glTranslated(0,moveArm,0);
             m_arm->draw();
        glPopMatrix();

        for (int i=0; i<4; ++i) {
            //m_material->wheel();
            glRotated(rotate,0,0,1);
            rotate = 0;
            m_wheels[i]->draw();
        }

        glPopMatrix();
}

void Forklift::upArm()
{
    if (moveArm < 2)
        moveArm += 1;
}

void Forklift::downArm()
{
    if (moveArm > -2)
        moveArm -= 1;
}

void Forklift::Foco()
{
    GLfloat att=0.5f;                                     //--Atenuacion
    GLfloat cutoff=10.0f;                                 //--Apertura
    GLfloat exponent=40.0f;                               //--Intensidad
    GLfloat spotDir[] = { 0,0,m_focoDiretion };                //--Direccion
    GLfloat lightPos[] = { 1.0,7.0,0.0,1.0 };               //--Posicion

                            ///  R     G    B      A
    GLfloat ambientLight[] = { 0.7578f, 0.7578f, 0.7578f, 0.7578f };
    GLfloat diffuseLight[] = { 0.7578f, 0.7578f, 0.7578f, 0.7578f };
    GLfloat specularLight[] = { 0.7578f, 0.7578f, 0.7578f, 0.7578f };

    glLightfv(GL_LIGHT4, GL_AMBIENT, ambientLight);
    glLightfv(GL_LIGHT4, GL_DIFFUSE, diffuseLight);
    glLightfv(GL_LIGHT4, GL_SPECULAR, specularLight);
    glLightfv(GL_LIGHT4, GL_POSITION, lightPos);
    glLightfv(GL_LIGHT4, GL_SPOT_DIRECTION, spotDir);
//    glLightf(GL_LIGHT4, GL_SPOT_EXPONENT, exponent);
    glLightf(GL_LIGHT4, GL_SPOT_CUTOFF, cutoff);
    //glLightf( GL_LIGHT4 , GL_LINEAR_ATTENUATION, att );

    glEnable(GL_LIGHT4);

}

void Forklift::toogleFoco()
{
    if (m_focoOn)
        m_focoOn = false;
    else
        m_focoOn = true;
}


void Forklift::rotateFoco()
{
    m_focoDiretion += 0.1;
    if (m_focoDiretion == 1)
        m_focoDiretion = -1;
}
