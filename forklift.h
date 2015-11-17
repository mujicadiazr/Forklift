#ifndef FORKLIFT_H
#define FORKLIFT_H

#include <QObject>

class ObjScene;
class Model_OBJ;
class material;

enum WheelType {
    rueda_delantera_derecha,
    rueda_delantera_izquierda,
    rueda_trasera_derecha,
    rueda_trasera_izquierda
};

class Forklift : public QObject
{
    Q_OBJECT

    ObjScene *m_chassis;
    ObjScene *m_wheels[4];
    ObjScene *m_arm;
    ObjScene *m_siren;

    material *m_material;

    double m_translationVelocity;
    double m_rotationVelocity;
    bool m_focoOn;
    float m_focoDiretion;

public slots:
    void rotateFoco();

public:
    Forklift();

    void run();
    void back();

    void load();
    void draw();

    void upArm();
    void downArm();
    void Foco();
    void toogleFoco();

};

#endif // FORKLIFT_H
