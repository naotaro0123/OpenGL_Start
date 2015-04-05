#include "glwidget.h"
#include "QDebug"
#include "QMouseEvent"

const GLfloat vertex[] = {-0.9, 0.9, 0.9, 0.9, 0, -0.9};
GLboolean isLine = GL_FALSE;

GLWidget::GLWidget(QWidget *parent) :
    QGLWidget(parent)
{
}

void GLWidget::initializeGL()
{
}

void GLWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(2, GL_FLOAT, 0, vertex);
    glDrawArrays((isLine == GL_TRUE ? GL_LINE_LOOP : GL_POLYGON), 0, 3);
    glFlush();

}

void GLWidget::resizeGL(int w, int h)
{
}

void GLWidget::mousePressEvent(QMouseEvent *event)
{
    qDebug() << "mousePressEvent";
    // マウス左ボタンをクリックした場合
    if(event->buttons() & Qt::LeftButton)
    {
        qDebug() << "LeftButton";
    }
}

void GLWidget::mouseMoveEvent(QMouseEvent *event)
{
    qDebug() << "mouseMoveEvent";
    //　マウスポインタ位置
    qDebug() << event->globalPos();
}

void GLWidget::mouseReleaseEvent(QMouseEvent *event)
{
    qDebug() << "mouseReleaseEvent";
}
