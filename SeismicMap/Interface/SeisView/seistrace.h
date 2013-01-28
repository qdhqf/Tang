#ifndef SEISTRACE_H
#define SEISTRACE_H

#include <QtGui>
#include <QGraphicsItem>
#include "seisview.h"

class ShowTrace;

class SeisTrace : public QGraphicsItem
{
public:
    SeisTrace(ShowTrace *Trace, SeisSetting *setseis);
    ~SeisTrace();
private:
    int M;              //�õ��ĵ������ݸ���
    int Start_MutTime;  //��ʼ�г�ʱ��
    int End_MutTime;    //��ֹ�г�ʱ��
    int Width,Height;   //�����Ŀ�Ⱥ͸߶�
    float dx,dy;
    bool isDraw;
    ShowTrace* trace;
    SeisSetting *seisset;

    QList<float> *data;

private:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void draw_WaveArea(QPainter *painter);
    
};

#endif // SEISTRACE_H
