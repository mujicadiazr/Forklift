#include "material.h"
#include "GL/gl.h"


material::material()
{
}

void material::chassis() //Oro
{
    GLfloat vAmbient[4] = {1.00, 0.50, 0.00, 0.00};
    GLfloat vDiffuse[4] = {1.00, 0.50, 0.00, 0.00};
    GLfloat vSpecular[4] = {1.00, 0.50, 0.00, 0.00};
    GLfloat vEmission[4] = {1.00, 0.50, 0.00, 0.00};
    GLfloat vShininess = 10;
    glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT,vAmbient);
    glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,vDiffuse);
    glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,vSpecular);
    glMaterialfv(GL_FRONT_AND_BACK,GL_EMISSION,vEmission);
    glMaterialf(GL_FRONT_AND_BACK,GL_SHININESS,vShininess);

}

void material::wheel() //
{

    GLfloat vAmbient[4] = {0.18, 0.00, 0.00, 0.00};
    GLfloat vDiffuse[4] = {0.00, 0.00, 1.00, 0.00};
    GLfloat vSpecular[4] = {0.09, 0.00, 0.00, 1.00};
    GLfloat vEmission[4] = {0.00, 0.00, 0.00, 0.00};

//    GLfloat vAmbient[4] = {0.2, 0.2, 0.2, 1.0};
//    GLfloat vDiffuse[4] = {0.8, 0.8, 0.8, 1};
//    GLfloat vSpecular[4] = {0.09, 0.9, 0.9, 1.00};
//    GLfloat vEmission[4] = {0.00, 0.00, 0.00, 0.00};

    GLfloat vShininess = 10;
    glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT,vAmbient);
    glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,vDiffuse);
    glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,vSpecular);
    glMaterialfv(GL_FRONT_AND_BACK,GL_EMISSION,vEmission);
    glMaterialf(GL_FRONT_AND_BACK,GL_SHININESS,vShininess);
}

void material::arm()
{
    GLfloat vAmbient[4] = {0.18, 0.00, 0.00, 0.00};
    GLfloat vDiffuse[4] = {0.00, 0.00, 1.00, 0.00};
    GLfloat vSpecular[4] = {0.09, 0.00, 0.00, 1.00};
    GLfloat vEmission[4] = {0.00, 0.00, 0.00, 0.00};

//    GLfloat vAmbient[4] = {0.2, 0.2, 0.2, 1.0};
//    GLfloat vDiffuse[4] = {0.8, 0.8, 0.8, 1};
//    GLfloat vSpecular[4] = {0.09, 0.9, 0.9, 1.00};
//    GLfloat vEmission[4] = {0.00, 0.00, 0.00, 0.00};

    GLfloat vShininess = 10;
    glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT,vAmbient);
    glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,vDiffuse);
    glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,vSpecular);
    glMaterialfv(GL_FRONT_AND_BACK,GL_EMISSION,vEmission);
    glMaterialf(GL_FRONT_AND_BACK,GL_SHININESS,vShininess);
}
void material::siren()
{

    GLfloat vAmbient[4] = {0.20, 0.20, 0.20, 1.00};
    GLfloat vDiffuse[4] = {0.80, 0.80, 0.80, 1.00};
    GLfloat vSpecular[4] = {0.00, 0.00, 0.00, 1.00};
    GLfloat vEmission[4] = {0.00, 0.00, 0.00, 1.00};
    GLfloat vShininess = 10;

    glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT,vAmbient);
    glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,vDiffuse);
    glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,vSpecular);
    glMaterialfv(GL_FRONT_AND_BACK,GL_EMISSION,vEmission);
    glMaterialf(GL_FRONT_AND_BACK,GL_SHININESS,vShininess);
}
