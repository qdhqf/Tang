#ifndef DATABASE_H
#define DATABASE_H

#include <QDebug>
#include <QtSql/qsql.h>
#include <QtSql/QSqlError>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QList>
#include <QObject>
#include <QTime>
#include <QFile>
#include <QDataStream>

#include "../SEGY/segy.h"

bool createConnection_MySql();
bool createConnection_Sqlite(QString dbname);
void disConnection_Mysql();
void disConnection_Sqlite();

bool db_loadSEGYHead(QString filename);                    //����segy�������ݵ�ͷ��Ϣ
bool db_selectXLine(int xline,QList<int> *fpsize);         //����X Line��,fpsize�ļ�ָ��λ������
bool db_selectYLine(int yline,QList<int> *fpsize);         //����Y Line��,fpsize�ļ�ָ��λ������


void mysqlTestLoad();
void mysqlTestSelect();
void mysqlTestUpdate();


#endif // DATABASE_H
