#ifndef MAPITEM_H
#define MAPITEM_H

#include <QtGui>
#include <QGraphicsItem>
#include "mapview.h"

class DataManager;
class MapItem : public QGraphicsItem
{
public:
    MapItem(DataManager *DM);
private:
    int Width,Height;   //�����Ŀ�Ⱥ͸߶�
    int X_Max,X_Min,Y_Max,Y_Min;
    int Interval;       //������
private:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void drawMap(QPainter *painter);        //���Ƶ�ͼ�߽�
    void drawGrid(QPainter *painter);       //���Ƶ�ͼ����
    void drawLabel(QPainter *painter);      //��������
};

#endif // MAPITEM_H
