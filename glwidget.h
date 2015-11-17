#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QGLWidget>
class Cam;
class Forklift;
class Light;
class TGA;

class GLWidget : public QGLWidget
{
    Q_OBJECT

public:
    GLWidget(QWidget *parent = 0);


protected:
    void initializeGL();
    void paintGL();
    void resizeGL(int width, int height);
//    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void keyPressEvent(QKeyEvent *event);


private:
    void drawBox();
    void drawInfo();

public slots:
    void update();

private:
    Light *m_light;
    Cam *m_camera;
    Forklift* m_forklift;
    TGA *m_tga;


};

#endif // GLWIDGET_H
