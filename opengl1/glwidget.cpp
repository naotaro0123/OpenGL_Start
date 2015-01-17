#include "glwidget.h"
#include <GLUT/glut.h>

GLWidget::GLWidget(QWidget *parent) :
    QGLWidget(parent)
{
    connect(&timer, SIGNAL(timeout()),this, SLOT(updateGL()));
    // タイマーの開始、間隔を16ms(≒60fps)に設定
    timer.start(16);
}

// 初期化処理
void GLWidget::initializeGL(){
    glClearColor(0.2, 0.2, 0.2, 1);
    glEnable(GL_DEPTH_TEST);        // デプステスト（前後関係を有効にする）
    glEnable(GL_LIGHT0);            // 光源の定義（OpenGLでは8個まで指定可能）
    glEnable(GL_LIGHTING);          // 照明モデルの有効
    glEnable(GL_COLOR_MATERIAL);    // 色設定をマテリアル設定として使用するようにする
};

// 描画処理
void GLWidget::paintGL(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    // 表示物を回転させる
    glRotatef(0.5, 1, 1, 1);
    // ワイヤーフレームでポット表示
//    glutWireTeapot(0.6);
    // ポットの塗りつぶし色指定
    glColor3f(1,0.6, 0);
    // ソリッドでポット表示
    glutSolidTeapot(0.6);
};

// リサイズ処理
void GLWidget::resizeGL(int w, int h){
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45,(float)w/h, 0.01, 100.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0, 0, 5,
              0, 0, 0,
              0, 1, 0);
};
