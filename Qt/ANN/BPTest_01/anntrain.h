#ifndef ANNTRAIN_H_
#define ANNTRAIN_H_
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <cmath>
#include <fstream>


const double PI = 3.1415926;
class ANNTrain
{
public:
    ANNTrain();
    ~ANNTrain();

public: //BP�������������
    int input_Num;  //�����ڵ����
    int hide_Num;   //���ز�ڵ����
    int output_Num; //�����ڵ����
    int Max_LoopNum;//���ѭ������
    double Error_Min;   //ѵ����С���

    double NN_Learn_hide,NN_Learn_output;    //Ȩֵѧϰ��
    double NN_Learn_Bhide,NN_Learn_Boutput;  //��ֵѧϰ��
    double Move_hide,Move_output;   //�������
    double **V_input,**W_input;   //�����Ȩֵ����

    double *X,*Y,*O,*D;
    double *b1,*b2;      //��ֵ
    bool is_Data;       //�ж��������Ƿ���ֵ
    double Error;

public://�ӿں���
    void InitNet(int input, int hide, int output);  //��ʼ������
    void set_hideLearnRatio(double learn);          //��������ѧϰ��
    void set_outputLearnRatio(double learn);        //�����ѧϰ��
    void set_hideThresholdRation(double learn);     //���㷧ֵѧϰ��
    void set_outputThresholdRation(double learn);   //����㷧ֵѧϰ��
    void set_hideMove(double move);                 //�������㶯������
    void set_outputMove(double move);               //���������Ķ�������
    void set_MinError(double error);                //����ѵ�����
    void set_MaxLoopNum(int Num);                   //�������ѭ������


    bool BP_Train01(double **x, double **d, int TrainSample);//��׼LMS
    bool BP_Train02(double **x, double **d, int TrainSample);//�����淶��LMS�㷨
    void BP_Count(double *x, double *d);            //�źż���
    void Output_Weight();
    bool OutPutfile_Weigh(const char* filename);        //���Ȩֵ
    bool Loadfile_Weigh(const char* filename);          //����Ȩֵ

private://��غ���
    void Clear_Weigh();     //���Ȩֵ
    void Init_Weigh();      //��ʼ��Ȩֵ




};

#endif // ANNTRAN_H
