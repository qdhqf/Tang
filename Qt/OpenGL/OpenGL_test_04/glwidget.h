#ifndef GLWIDGET_H
#define GLWIDGET_H
#include <QtGui>
#include <QTimer>
#include <QtOpenGL>
#include <GL/glu.h>
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glext.h>
#ifdef Q_WS_X11
#include <GL/glx.h>
#endif
#define GL_FOG_COORDINATE_SOURCE_EXT	0x8450					// ��GLEXT.H�õ���ֵ
#define GL_FOG_COORDINATE_EXT		0x8451
typedef void (APIENTRY * PFNGLFOGCOORDFEXTPROC) (GLfloat coord);		// ���������꺯����ԭ��

class GLWidget : public QGLWidget
{
    Q_OBJECT

public:
    GLWidget(QWidget *parent = 0);
    ~GLWidget();

protected:
    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();

    //The timer,Keyboard and mouse event
    void timerEvent(QTimerEvent *);
    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);
    void mouseDoubleClickEvent(QMouseEvent *);
    void wheelEvent(QWheelEvent *e);
    void keyPressEvent(QKeyEvent *e);

private:
    bool getExtensions();
    void setLight();//���ù���
    void setFog();  //������
    void setRotate();
    void Go_init();     //�ص���ʼ״̬
    void Draw_Arrows();
    void Draw();
    void VolumeFog();

//Define the global variables of the program
private:
    PFNGLFOGCOORDFEXTPROC glFogCoordfEXT;
    GLfloat xRot,yRot,zRot,zoom;
    GLfloat xSpeed,ySpeed;
    GLfloat scale;
    QPoint lasPos;
    int t;

    GLuint theTorus;
};

#endif // GLWIDGET_H
