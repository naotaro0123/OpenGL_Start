#include "mainwindow.h"
#include <QApplication>
#include <GLUT/glut.h>

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    QApplication a(argc, argv);
    MainWindow w;
    w.resize(500,400);
    w.show();

    return a.exec();
}
