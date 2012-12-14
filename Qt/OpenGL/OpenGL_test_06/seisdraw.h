#ifndef SEISDRAW_H
#define SEISDRAW_H
#include <QList>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include "segy.h"

typedef struct
{
    //������ά�۲�ϵͳ
    int Start_T,Start_X,Start_Y;    //��ʼ����ֵ��С
    int End_T,End_X,End_Y;          //��ֹ����ֵ��С
    int Interval_T,Interval_X,Interval_Y;   //ͼ����ʾʱ������ļ����С
    float hdt;           //����ʱ����(ms)
}SEIS_CUBE;

class Seis_Trace
{
    //���浥����������
public:
    Seis_Trace();
    Seis_Trace(int x, int y, int start_time,int end_time, int N, float* in_data);
    ~Seis_Trace();
public:
    void SetPos(int x,int y);
    void SetTime(int start_time, int end_time);
    void SetData(int N,float* in_data);
public:
    //������������
    int X,Y;//�õ����������ڹ۲�ϵͳ�е�XY����
    int Start_Time,End_Time;  //��ǰ�ĵ������ݵĿ�ʼ������ʱ��
    int N;      //N������������
    float *data;//��������
};

class Seis_Slice
{
    Seis_Slice();
    Seis_Slice(int Idx);
    ~Seis_Slice();
    //�������õ�������
    int Index;      //��ǰ����ı��

};

#endif // SEISDRAW_H
