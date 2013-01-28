#ifndef DATAMANAGER_H
#define DATAMANAGER_H

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <QList>
#include <QVector>
#include <QColor>
#include <QSettings>

#include "../DataBase/database.h"
#include "../SEGY/showslice.h"

class ShowTrace;
class ShowSlice;

struct REEL;
struct TRACE;
struct SEGYHEAD;
struct Surface
{
    int x,y,z;
    float value;
};

enum SeisType{WaveLine,WaveArea,Gray,Colors};

struct MapSetting
{
    //��ͼ��������
    int Min_XLine,Max_XLine;    //XLine�������Сֵ
    int Min_YLine,Max_YLine;    //YLine�������Сֵ
    int XInterval,YInterval;    //X,YLine�ĸ���֮��ļ��
    float XScale,YScale;        //X,Y�����ϵ����ű���
    int size_Receiver;          //�첨���С��ѡ��뾶
    QColor color_Receiver;      //�첨����ɫ
    QColor color_Receiver_Selected; //ѡ�񵽵ļ첨�����ɫ
};

struct SeisSetting
{
    //�����������
    float dx,dy;                //X�����ϵļ����Zʱ���ϵļ��
    float sample_interval;      //ʱ��������
    float XScale,YScale;        //������X�����T��������ű���
    float gain;                 //��������

    int lx,ly;                  //������߽���ϱ߽�ļ��
    int grid_XInterval,grid_YInterval;//���������ߵļ��
    QColor color_grid;          //�����ߵ���ɫ
    SeisType seisType;          //����������Ʒ�ʽ
    QColor color_Line;          //���滮�ߵ���ɫ
    int width_Line;             //���滮�ߵ��߿�
    QColor color_Area;          //���α�����������ɫ
};

class DataManager
{
public:
    DataManager();
    ~DataManager();
    void ReadSEGYData();
    void GetSurface(int ztime);

    void setMemory();       //��������ռ�
    bool setDataBase();     //�������ݿ�
    void setDefaultValues();//����Ĭ��ֵs
    bool InitFile();

    //��д��Ŀ�����ļ�
    void ReadSetting();
    void WriteSetting();

public:
    QSqlQuery query;
    QString filename;   //���������ļ�
    QString dbname;        //���ݿ��ļ�
    FILE* filesegy;

    REEL* Reel;     //�������ݾ�ͷ��Ϣ
    SEGYHEAD *segyHead;//�������ݵ�ͷ��Ϣ


    //��������
    QList<Surface> surface;
    QList<ShowSlice*> Total_Slices;
    int Current_Slice_Index;
    //ShowSlice* Current_Slice;   //��ǰ��ʾ�ĵ�������

    //��ͼ����
    MapSetting  *mapset;
    SeisSetting *seisset;

};

#endif // DATAMANAGER_H
