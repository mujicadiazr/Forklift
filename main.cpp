#include "glwidget.h"
#include <QApplication>
#include "includeUnix/glut.h"


int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    GLWidget w;
    w.show();
    
    return a.exec();
}
