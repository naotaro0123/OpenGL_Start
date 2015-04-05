#include "glwidget.h"
#include <GLUT/glut.h>
#include "QDebug"

GLWidget::GLWidget(QWidget *parent) :
    QGLWidget(parent)
{
    connect(&timer, SIGNAL(timeout()),this, SLOT(updateGL()));
    // タイマーの開始、間隔を16ms(≒60fps)に設定
    timer.start(16);
}

// 初期化処理
void GLWidget::initializeGL(){
//    glClearColor(0.2, 0.2, 0.2, 1);
    glEnable(GL_DEPTH_TEST);        // デプステスト（前後関係を有効にする）
//    glEnable(GL_LIGHT0);            // 光源の定義（OpenGLでは8個まで指定可能）
//    glEnable(GL_LIGHTING);          // 照明モデルの有効
//    glEnable(GL_COLOR_MATERIAL);    // 色設定をマテリアル設定として使用するようにする
};

// 描画処理
void GLWidget::paintGL(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        glTranslatef(0.0f, 0.0f, -20.0f);
        glRotatef(30.0, 0.0, 1.0, 0.0);
        glRotatef(15.0, 1.0, 0.0, 0.0);

    // Cube Make
    glBegin(GL_QUADS);
        // front
        glColor3f(1.0,0.0,0.0);
        glVertex3f(1.0,1.0,1.0);
        glVertex3f(-1.0,1.0,1.0);
        glVertex3f(-1.0,-1.0,1.0);
        glVertex3f(1.0,-1.0,1.0);
        // back
        glColor3f(0.0, 1.0, 0.0);
        glVertex3f(1.0,1.0,-1.0);
        glVertex3f(-1.0,1.0,-1.0);
        glVertex3f(-1.0,-1.0,-1.0);
        glVertex3f(1.0,-1.0,-1.0);
        // top
        glColor3f(0.0, 0.0, 1.0);
        glVertex3f(-1.0,1.0,1.0);
        glVertex3f(1.0,1.0,1.0);
        glVertex3f(1.0,1.0,-1.0);
        glVertex3f(-1.0,1.0,-1.0);
        // bottom
        glColor3f(0.0, 1.0, 1.0);
        glVertex3f(1.0,-1.0,-1.0);
        glVertex3f(1.0,-1.0,-1.0);
        glVertex3f(-1.0,-1.0,-1.0);
        glVertex3f(-1.0,-1.0,1.0);
        // right
        glColor3f(1.0, 0.0, 1.0);
        glVertex3f(1.0,1.0,1.0);
        glVertex3f(1.0,-1.0,1.0);
        glVertex3f(1.0,-1.0,-1.0);
        glVertex3f(1.0,1.0,-1.0);
        // left
        glColor3f(1.0, 1.0, 0.0);
        glVertex3f(-1.0,1.0,1.0);
        glVertex3f(-1.0,-1.0,1.0);
        glVertex3f(-1.0,-1.0,-1.0);
        glVertex3f(-1.0,1.0,-1.0);

    glEnd();
};

// リサイズ処理
void GLWidget::resizeGL(int w, int h){
    glViewport(0,0, (GLint)w, (GLint)h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-1.0,1.0,-1.0,1.0,5.0,30.0);
    glMatrixMode(GL_MODELVIEW);
};
