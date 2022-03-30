#ifndef SUBSCRIPTIONS_H
#define SUBSCRIPTIONS_H
#include <QString>
#include <QSqlQueryModel>
#include "mainwindow.h"
#include <QTableView>

class subscriptions
{
public:
    subscriptions();
    subscriptions(int,QString,QString,float,int,QString,QString);
    int getnum();
    QString gettype();
    QString getduration();
    float getprice();
    int getidBuy();
    QString getsdate();
    QString getedate();
    void setnum(int);
    void settype(QString);
    void setduration(QString);
    void setprice(float);
    void setidBuy(int);
    void setsdate(QString);
    void setedate(QString);
    bool add();
    QSqlQueryModel* read();// RETOUR TAB d'une requete(query) de type sql
    bool deleteS(int);
    bool update(int);
    QSqlQueryModel* read_id();
    QSqlQueryModel* read_buyer();
    QSqlQueryModel * sort_id();
    QSqlQueryModel * sort_type();
    QSqlQueryModel * sort_price();
    void cleartable(QTableView*);
    QSqlQueryModel * find_num(int);
    QSqlQueryModel * find_type(QString);
    QSqlQueryModel * find_startDate(QString);
    void findNum(QTableView *table, int x);
    void findType(QTableView *table, QString x);
    void findStartDate(QTableView *table, QString x);
    float read_price();
    QString read_sdate();
void statistique(QVector<double>* ticks,QVector<QString> *labels);



private:

    int num_sub,idBuy,code;
    QString type_sub, duration_sub,s_date,e_date,code2,code3;
    float price_sub;


};

#endif // SUBSCRIPTIONS_H
