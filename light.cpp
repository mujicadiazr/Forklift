#include "light.h"
#include "includeUnix/glut.h"

Light::Light()
{
}

void Light::setUp(float x, float y, float z, float w)
{
//    //Luz

    LuzAmbiental1();
     LuzAmbiental2();
     LuzAmbiental3();
    LuzAmbiental4();

//    LuzFoco1();
//      LuzFoco2();
//       LuzFoco3();
//     LuzFoco4();

}


void Light::LuzFoco1()
{
    glEnable(GL_LIGHTING);

    GLfloat att=0.5f;                                     //--Atenuacion
    GLfloat cutoff=90.0f;                                 //--Apertura
    GLfloat exponent=40.0f;                               //--Intensidad
    GLfloat spotDir[] = { -1.0f,-1.0f, 0.0f };                //--Direccion
    GLfloat lightPos[] = { 10,10,0, 1.0f };               //--Posicion

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

//    glEnable(GL_COLOR_MATERIAL);   //Activar la opción
//    glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
//        glPushMatrix();
//        glColor3f(1,1,0.23);
//            glScalef(1,1,0.2);
//            glTranslatef(-0.58,1.38,0);
//            glutSolidSphere(0.2,50,100);
//        glPopMatrix();
//   glDisable(GL_COLOR_MATERIAL);
}

void Light::LuzFoco2()
{
    glEnable(GL_LIGHTING);

    GLfloat att=0.5f;                                     //--Atenuacion
    GLfloat cutoff=90.0f;                                 //--Apertura
    GLfloat exponent=40.0f;                               //--Intensidad
    GLfloat spotDir[] = { 1.0f, 1.0f, 0.0f };                //--Direccion
    GLfloat lightPos[] = { -10,-10,0, 0.0f };     //--Posicion

                            ///  R     G    B      A
    GLfloat ambientLight[] = { 0.7578f, 0.7578f, 0.7578f, 0.7578f };
    GLfloat diffuseLight[] = { 0.7578f, 0.7578f, 0.7578f, 0.7578f };
    GLfloat specularLight[] = { 0.7578f, 0.7578f, 0.7578f, 0.7578f };

    glLightfv(GL_LIGHT5, GL_AMBIENT, ambientLight);
    glLightfv(GL_LIGHT5, GL_DIFFUSE, diffuseLight);
    glLightfv(GL_LIGHT5, GL_SPECULAR, specularLight);
    glLightfv(GL_LIGHT5, GL_POSITION, lightPos);
    glLightfv(GL_LIGHT5, GL_SPOT_DIRECTION, spotDir);
//    glLightf(GL_LIGHT5, GL_SPOT_EXPONENT, exponent);
    glLightf(GL_LIGHT5, GL_SPOT_CUTOFF, cutoff);
//    glLightf( GL_LIGHT5 , GL_LINEAR_ATTENUATION, att );

    glEnable(GL_LIGHT5);

//    glEnable(GL_COLOR_MATERIAL);   //Activar la opción
//    glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
//        glPushMatrix();
//        glColor3f(1,1,0.23);
//            glScalef(1,1,0.2);
//            glTranslatef(0.58,1.38,0);
//            glutSolidSphere(0.2,50,100);
//        glPopMatrix();
//   glDisable(GL_COLOR_MATERIAL);
}

void Light::LuzFoco3()
{
    glEnable(GL_LIGHTING);

    GLfloat att=0.5f;                                     //--Atenuacion
    GLfloat cutoff=90.0f;                                 //--Apertura
    GLfloat exponent=40.0f;                               //--Intensidad
    GLfloat spotDir[] = { 0.0f, -1.0f, 1.0f };                //--Direccion
    GLfloat lightPos[] = { 0.0,10,-10, 1.0f };     //--Posicion

                            ///  R     G    B      A
    GLfloat ambientLight[] = { 0.7578f, 0.7578f, 0.7578f, 0.7578f };
    GLfloat diffuseLight[] = { 0.7578f, 0.7578f, 0.7578f, 0.7578f };
    GLfloat specularLight[] = { 0.7578f, 0.7578f, 0.7578f, 0.7578f };

    glLightfv(GL_LIGHT6, GL_AMBIENT, ambientLight);
    glLightfv(GL_LIGHT6, GL_DIFFUSE, diffuseLight);
    glLightfv(GL_LIGHT6, GL_SPECULAR, specularLight);
    glLightfv(GL_LIGHT6, GL_POSITION, lightPos);
    glLightfv(GL_LIGHT6, GL_SPOT_DIRECTION, spotDir);
//    glLightf(GL_LIGHT6, GL_SPOT_EXPONENT, exponent);
    glLightf(GL_LIGHT6, GL_SPOT_CUTOFF, cutoff);
//    glLightf( GL_LIGHT6 , GL_LINEAR_ATTENUATION, att );

    glEnable(GL_LIGHT6);

//    glEnable(GL_COLOR_MATERIAL);   //Activar la opción
//    glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
//        glPushMatrix();
//        glColor3f(1,1,0.23);
//            glScalef(0.2,1,1);
//            glTranslatef(0.0,1.38,-0.58);
//            glutSolidSphere(0.2,50,100);
//        glPopMatrix();
//   glDisable(GL_COLOR_MATERIAL);
}

void Light::LuzFoco4()
{
    glEnable(GL_LIGHTING);

    GLfloat att=0.5f;                                     //--Atenuacion
    GLfloat cutoff=90.0f;                                 //--Apertura
    GLfloat exponent=40.0f;                               //--Intensidad
    GLfloat spotDir[] = { 0.0f, 1.0f, 1.0f };                //--Direccion
    GLfloat lightPos[] = { 0.0,-10,-10, 1.0f };     //--Posicion

                            ///  R          G        B      A
    GLfloat ambientLight[] = { 0.7578f, 0.7578f, 0.7578f, 0.7578f };
    GLfloat diffuseLight[] = { 0.7578f, 0.7578f, 0.7578f, 0.7578f };
    GLfloat specularLight[] = { 0.7578f, 0.7578f, 0.7578f, 0.7578f };

    glLightfv(GL_LIGHT7, GL_AMBIENT, ambientLight);
    glLightfv(GL_LIGHT7, GL_DIFFUSE, diffuseLight);
    glLightfv(GL_LIGHT7, GL_SPECULAR, specularLight);
    glLightfv(GL_LIGHT7, GL_POSITION, lightPos);
    glLightfv(GL_LIGHT7, GL_SPOT_DIRECTION, spotDir);
//    glLightf(GL_LIGHT7, GL_SPOT_EXPONENT, exponent);
    glLightf(GL_LIGHT7, GL_SPOT_CUTOFF, cutoff);
//    glLightf( GL_LIGHT7 , GL_LINEAR_ATTENUATION, att );

    glEnable(GL_LIGHT7);

//    glEnable(GL_COLOR_MATERIAL);   //Activar la opción
//    glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
//        glPushMatrix();
//        glColor3f(1,1,0.23);
//            glScalef(0.2,1,1);
//            glTranslatef(0.0,1.38,0.58);
//            glutSolidSphere(0.2,50,100);
//        glPopMatrix();
//   glDisable(GL_COLOR_MATERIAL);
}

void Light::LuzAmbiental1()
{
    glEnable(GL_LIGHTING);

    GLfloat att=0.3f;                                     //--Atenuacion
    GLfloat cutoff=90.0f;                                 //--Apertura
    GLfloat exponent=50.0f;                               //--Intensidad
    GLfloat spotDir[] = { 0.0f, 1.0f, -1.0f };                //--Direccion
    GLfloat lightPos[] = { 0.0f, -10.0f, 10.0f, 1.0f };     //--Posicion

                            //  R     G    B      A
//        GLfloat ambientLight[4] = {1.0, 1.0, 1.0, 0.0};
//        GLfloat diffuseLight[4] = {1.0, 1.0, 1.0, 0.0};
//        GLfloat specularLight[4] = {1.0, 1.0, 1.0, 0.0};

    GLfloat ambientLight[] = { 0.7578f, 0.7578f, 0.7578f, 0.7578f };
    GLfloat diffuseLight[] = { 0.7578f, 0.7578f, 0.7578f, 0.7578f };
    GLfloat specularLight[] = { 0.7578f, 0.7578f, 0.7578f, 0.7578f };

    glLightfv(GL_LIGHT1, GL_AMBIENT, ambientLight);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, diffuseLight);
    glLightfv(GL_LIGHT1, GL_SPECULAR, specularLight);

    glLightfv(GL_LIGHT1, GL_POSITION, lightPos);
    glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, spotDir);
//    glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, exponent);
    glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, cutoff);
//    glLightf( GL_LIGHT1 , GL_CONSTANT_ATTENUATION, att );

    glEnable(GL_LIGHT1);
}

void Light::LuzAmbiental2()
{
    glEnable(GL_LIGHTING);

    GLfloat att=0.3f;                                     //--Atenuacion
    GLfloat cutoff=90.0f;                                 //--Apertura
    GLfloat exponent=50.0f;                               //--Intensidad
    GLfloat spotDir[] = { -1.0f, 0.0f, -1.0f };                //--Direccion
    GLfloat lightPos[] = { 10.0f, 0.0f, 10.0f, 1.0f };     //--Posicion

                            ///  R     G    B      A
    GLfloat ambientLight[] = { 0.7578f, 0.7578f, 0.7578f, 0.7578f };
    GLfloat diffuseLight[] = { 0.7578f, 0.7578f, 0.7578f, 0.7578f };
    GLfloat specularLight[] = { 0.7578f, 0.7578f, 0.7578f, 0.7578f };

    glLightfv(GL_LIGHT0, GL_AMBIENT, ambientLight);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuseLight);
    glLightfv(GL_LIGHT0, GL_SPECULAR, specularLight);
    glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
    glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, spotDir);
//    glLightf(GL_LIGHT0, GL_SPOT_EXPONENT, exponent);
    glLightf(GL_LIGHT0, GL_SPOT_CUTOFF, cutoff);
//    glLightf( GL_LIGHT0 , GL_CONSTANT_ATTENUATION, att );

    glEnable(GL_LIGHT0);
}

void Light::LuzAmbiental3()
{
    glEnable(GL_LIGHTING);

    GLfloat att=0.3f;                                     //--Atenuacion
    GLfloat cutoff=90.0f;                                 //--Apertura
    GLfloat exponent=50.0f;                               //--Intensidad
    GLfloat spotDir[] = { -1.0f, 0.0f, 1.0f };                //--Direccion
    GLfloat lightPos[] = { 10.0f, 0.0f, -10.0f, 1.0f };     //--Posicion

                            ///  R     G    B      A
    GLfloat ambientLight[] = { 0.7578f, 0.7578f, 0.7578f, 0.7578f };
    GLfloat diffuseLight[] = { 0.7578f, 0.7578f, 0.7578f, 0.7578f };
    GLfloat specularLight[] = { 0.7578f, 0.7578f, 0.7578f, 0.7578f };

    glLightfv(GL_LIGHT2, GL_AMBIENT, ambientLight);
    glLightfv(GL_LIGHT2, GL_DIFFUSE, diffuseLight);
    glLightfv(GL_LIGHT2, GL_SPECULAR, specularLight);
    glLightfv(GL_LIGHT2, GL_POSITION, lightPos);
    glLightfv(GL_LIGHT2, GL_SPOT_DIRECTION, spotDir);
//    glLightf(GL_LIGHT2, GL_SPOT_EXPONENT, exponent);
    glLightf(GL_LIGHT2, GL_SPOT_CUTOFF, cutoff);
//    glLightf( GL_LIGHT2 , GL_CONSTANT_ATTENUATION, att );

    glEnable(GL_LIGHT2);
}

void Light::LuzAmbiental4()  //poste emo
{
    glEnable(GL_LIGHTING);

    GLfloat att=5;                                     //--Atenuacion
    GLfloat cutoff=90.0f;                                 //--Apertura
    GLfloat exponent=50.0f;                               //--Intensidad
    GLfloat spotDir[] = { 1.0f, 1.0f, -1.0f };                //--Direccion
    GLfloat lightPos[] = { -10.0f, 0.0f, 10.0f, 1.0f };     //--Posicion

                            ///  R     G    B      A
    GLfloat ambientLight[] = { 0.7578f, 0.7578f, 0.7578f, 0.7578f };
    GLfloat diffuseLight[] = { 0.7578f, 0.7578f, 0.7578f, 0.7578f };
    GLfloat specularLight[] = { 0.7578f, 0.7578f, 0.7578f, 0.7578f };

    glLightfv(GL_LIGHT3, GL_AMBIENT, ambientLight);
    glLightfv(GL_LIGHT3, GL_DIFFUSE, diffuseLight);
    glLightfv(GL_LIGHT3, GL_SPECULAR, specularLight);
    glLightfv(GL_LIGHT3, GL_POSITION, lightPos);
    glLightfv(GL_LIGHT3, GL_SPOT_DIRECTION, spotDir);
//    glLightf(GL_LIGHT3, GL_SPOT_EXPONENT, exponent);
    glLightf(GL_LIGHT3, GL_SPOT_CUTOFF, cutoff);
//    glLightf( GL_LIGHT3 , GL_CONSTANT_ATTENUATION, att );

    glEnable(GL_LIGHT3);
}

