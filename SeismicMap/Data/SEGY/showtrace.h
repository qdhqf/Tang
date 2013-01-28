#ifndef SHOWTRACE_H
#define SHOWTRACE_H

#include "segy.h"

class ShowTrace
{
    //������𵥵���������
public:
    ShowTrace(int Idx);
    ShowTrace(int Idx,FILE* fp, SEGYHEAD* segyhead,long pos);
    ~ShowTrace();
    void LoadTrace(int Idx , FILE* fp, SEGYHEAD* segyhead, long pos);
public:
    int Index;
    TRACE *trace;
    float *data;
    float X,Y;        //XY����
};

#endif // SHOWTRACE_H
