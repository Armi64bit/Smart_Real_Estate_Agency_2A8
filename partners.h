#ifndef PARTNERS_H
#define PARTNERS_H
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QString>
#include <Qtableview.h>


class PARTNERS
{
private:
    int NUM_SUB,ID_PAR;
    QString NAME_PAR,TYPE_PAR,DURATION_PAR,CONTRACT_LANGUAGE_PAR;

public:
    PARTNERS();
    PARTNERS(int,int,QString,QString,QString,QString);
    QSqlQueryModel * sort_name_ag();
QSqlQueryModel * sort_id();
QSqlQueryModel * sort_lg();
void rechercher_name(QTableView *table, QString x);
void rechercher_id(QTableView *table, int x);

void cleartable(QTableView * table );

    //getters
    QString getname(){return  NAME_PAR;}
    QString gettype(){return  TYPE_PAR;}
    QString getduration(){return  DURATION_PAR;}
    QString getlang(){return  CONTRACT_LANGUAGE_PAR;}
    int getnumsub(){return  NUM_SUB;}
    int getid(){return  ID_PAR;}

    //setters

    void getname(QString NAME_PAR){this->NAME_PAR=NAME_PAR;}
    void gettype(QString TYPE_PAR){this->TYPE_PAR=TYPE_PAR;}
    void getduration(QString DURATION_PAR){this->DURATION_PAR= DURATION_PAR;}
    void getlang(QString CONTRACT_LANGUAGE_PAR){  this->CONTRACT_LANGUAGE_PAR=CONTRACT_LANGUAGE_PAR;}
    void getnumsub(int NUM_SUB){this->NUM_SUB=NUM_SUB;}
    void getid(int ID_PAR){this->ID_PAR=ID_PAR;}

  //fn de base
    bool add();
    QSqlQueryModel * display();
    bool del(int);
QSqlQueryModel*  read_id();
QSqlQueryModel * read1(int);
bool dell(int);
QSqlQueryModel * read();
bool update(int );
QSqlQueryModel * sort_name();
void rechercher(QTableView *table, int x);

};

#endif // PARTNERS_H
