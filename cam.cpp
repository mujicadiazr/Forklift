#include "cam.h"
#include "light.h"

const double ZOOM_VALUE = 1;
const double MOVE_ANGLE = 5;


Cam::Cam()
{
    m_X = 0;
    m_Y = 0;
    m_Z = -20;
    l = new Light();
}

void Cam::setUp()
{
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    //gluLookAt(m_X,m_Y,m_Z,0,0,0,0,1,0);
    glTranslated(m_X,m_Y,m_Z);
    glRotated(m_angleY,0,1,0);
    glRotated(m_angleX,1,0,0);

//    glPushMatrix();
//        //glRotated(5,1,0,0);
//        l->setUp(m_X,m_Y,m_Z,0);
//    glPopMatrix();

}

void Cam::zoomOut()
{
    m_Z -= ZOOM_VALUE;
}

void Cam::zoomIn()
{
    m_Z += ZOOM_VALUE;
}

void Cam::goLeft()
{
    m_angleY -= MOVE_ANGLE;
    if(m_angleY == 360) m_angleY = 0;
}

void Cam::goRight()
{
    m_angleY += MOVE_ANGLE;
    if(m_angleY == 360) m_angleY = 0;
}

void Cam::goUp()
{
    m_angleX += MOVE_ANGLE;
    if(m_angleY == 360) m_angleY = 0;
}

void Cam::goDown()
{
    m_angleX -= MOVE_ANGLE;
    if(m_angleY == 360) m_angleY = 0;
}


void Cam::resetPosition()
{
    m_Z = -20;
    m_X = 0;
    m_Y = 0;
}
