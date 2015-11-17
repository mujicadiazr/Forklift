#ifndef CAM_H
#define CAM_H

#include "includeUnix/glut.h"
class Light;

class Cam
{
    GLdouble m_X;
    GLdouble m_Y;
    GLdouble m_Z;
    GLdouble m_angleY;
    GLdouble m_angleX;

    Light *l;
public:
    Cam();
    void setUp();
    void zoomOut();
    void zoomIn();
    void goLeft();
    void goRight();
    void goUp();
    void goDown();
    void resetPosition();
};

#endif // CAM_H
