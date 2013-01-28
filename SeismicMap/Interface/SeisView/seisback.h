#ifndef SEISBACK_H
#define SEISBACK_H

#include <QtGui>
#include <QGraphicsItem>
#include "seisview.h"

class SeisBack : public QGraphicsItem
{
public:
    SeisBack(ShowSlice *slice, DataManager *dm);
    ~SeisBack();
private:
    DataManager *dm;
    ShowSlice *slice;
    int Num_Trace;      //��ǰ�ܵ���
    int Num_HNS;        //��������
    float dt;
    int dx,dy;
    int Width,Height;
    int X_interval,Y_interval;

private:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void drawGrid(QPainter *painter);       //��������
    void drawLabel(QPainter *painter);      //���Ʊ�ǩ�̶�
};

#endif // SEISBACK_H
