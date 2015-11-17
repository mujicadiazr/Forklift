#ifndef LIGHT_H
#define LIGHT_H

class Light
{


public:
    Light();
    void setUp(float x=0, float y=0, float z=0, float w=1);
    void  LuzAmbiental1();
     void LuzAmbiental2();
    void  LuzAmbiental3();
     void LuzAmbiental4();

     void LuzFoco1();
    void  LuzFoco2();
     void LuzFoco3();
     void LuzFoco4();
};

#endif // LIGHT_H
