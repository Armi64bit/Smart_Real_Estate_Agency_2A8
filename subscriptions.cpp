#include "subscriptions.h"
#include "mainwindow.h"
#include "connection.h"
#include <QString>
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include <QTableView>
#include <iostream>
#include <fstream>

using namespace std;
subscriptions::subscriptions()
{
    num_sub=0;
    type_sub="";
    duration_sub="";
    price_sub=0;
    idBuy=0;
    s_date="";
    e_date="";
}


subscriptions::subscriptions(int num_sub,QString type_sub,QString duration_sub,float price_sub,int idBuy,QString s_date,QString e_date)
{
    this->num_sub=num_sub;
    this->type_sub=type_sub;
    this->duration_sub=duration_sub;
    this->price_sub=price_sub;
    this->idBuy=idBuy;
    this->s_date=s_date;
    this->e_date=e_date;
    //
}

int subscriptions::getnum()
{
    return num_sub;
}

QString subscriptions::gettype()
{
    return type_sub;
}

QString subscriptions::getduration()
{
    return duration_sub;
}

float subscriptions::getprice()
{
    return price_sub;
}

int subscriptions::getidBuy()
{
    return idBuy;
}

QString subscriptions::getsdate()
{
    return s_date;
}

QString subscriptions::getedate()
{
    return e_date;
}

void subscriptions::setnum(int num_sub)
{
    this->num_sub=num_sub;
}

void subscriptions::settype(QString type_sub)
{
     this->type_sub=type_sub;
}

void subscriptions::setduration(QString duration_sub)
{
    this->duration_sub=duration_sub;
}

void subscriptions::setprice(float price_sub)
{
    this->price_sub=price_sub;
}

void subscriptions::setidBuy(int idBuy)
{
    this->idBuy=idBuy;
}

void subscriptions::setsdate(QString s_date)
{
    this->s_date=s_date;
}

void subscriptions::setedate(QString e_date)
{
    this->e_date=e_date;
}

bool subscriptions::add()
{
    QSqlQuery query;
    QString num_sub_string=QString::number(num_sub);
    QString price_sub_string=QString::number(price_sub);
    QString idbuy_string=QString::number(idBuy);
          query.prepare("INSERT INTO SUBSCRIPTIONS (num_sub, type_sub, duration_sub, price_sub,id_buyer,s_date,e_date) " "VALUES (:num_sub, :type_sub, :duration_sub, :price_sub, :idBuy, :s_date, :e_date)");
          query.bindValue(":num_sub",num_sub_string);
          query.bindValue(":type_sub", type_sub);
          query.bindValue(":duration_sub", duration_sub);
          query.bindValue(":price_sub",price_sub_string);
          query.bindValue(":idBuy",idbuy_string);
          query.bindValue(":s_date",s_date);
          query.bindValue(":e_date",e_date);

         return query.exec();
}

QSqlQueryModel* subscriptions::read()
{
    QSqlQueryModel* model=new QSqlQueryModel();
          model->setQuery("SELECT * FROM SUBSCRIPTIONS");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("Number"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("Type"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("Duration"));
          model->setHeaderData(3, Qt::Horizontal, QObject::tr("Price"));
          model->setHeaderData(4, Qt::Horizontal, QObject::tr("id_Buyer"));
          model->setHeaderData(5, Qt::Horizontal, QObject::tr("Start_date"));
          model->setHeaderData(6, Qt::Horizontal, QObject::tr("End_date"));
    return model;
}

bool subscriptions::deleteS(int num_sub)
{
    QSqlQuery query;
          query.prepare("DELETE FROM SUBSCRIPTIONS WHERE num_sub=:num_sub");
          query.bindValue(":num_sub",num_sub);
         return query.exec();
}

bool subscriptions::update(int num_sub)
{
    QSqlQuery query;
    QString num_sub_string=QString::number(num_sub);
    QString price_sub_string=QString::number(price_sub);
    query.prepare("UPDATE SUBSCRIPTIONS SET type_sub=:type_sub,duration_sub=:duration_sub,price_sub=:price_sub,s_date=:s_date,e_date=:e_date WHERE num_sub=:num_sub");
    query.bindValue(":num_sub",num_sub_string);
    query.bindValue(":type_sub", type_sub);
    query.bindValue(":duration_sub", duration_sub);
    query.bindValue(":price_sub",price_sub_string);
    query.bindValue(":s_date",s_date);
    query.bindValue(":e_date",e_date);
    return query.exec();
}

//affichage
QSqlQueryModel* subscriptions::read_id()
{
     QSqlQueryModel *model=new QSqlQueryModel();
     model->setQuery("select NUM_SUB from subscriptions");
     return model;
}

//id buyer
QSqlQueryModel* subscriptions::read_buyer()
{
     QSqlQueryModel *model=new QSqlQueryModel();
     model->setQuery("select id_buy from buyers");
     return model;
}

//tris
QSqlQueryModel * subscriptions::sort_id()
{
    QSqlQueryModel * model= new QSqlQueryModel();
        model->setQuery("select * from SUBSCRIPTIONS order by num_sub");
        return model;
}
QSqlQueryModel * subscriptions::sort_type()
{
    QSqlQueryModel * model= new QSqlQueryModel();
        model->setQuery("select * from SUBSCRIPTIONS order by upper(type_sub)");
        return model;
}
QSqlQueryModel * subscriptions::sort_price()
{
    QSqlQueryModel * model= new QSqlQueryModel();
        model->setQuery("select * from SUBSCRIPTIONS order by price_sub");
        return model;
}

//recherches
void subscriptions::cleartable(QTableView *table)
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->clear();
    table->setModel(model);
}

QSqlQueryModel* subscriptions::find_num(int code)
{
    QSqlQuery query ;
       QSqlQueryModel* model=new QSqlQueryModel();
       query.prepare("select * from SUBSCRIPTIONS where num_sub =:code");
       query.bindValue(":code",code);
       query.exec();
       model->setQuery(query);
    return model;
}

QSqlQueryModel* subscriptions::find_type(QString code2)
{
    QSqlQuery query ;
       QSqlQueryModel* model=new QSqlQueryModel();
    //   QString code22;
       query.prepare("select * from SUBSCRIPTIONS where type_sub =:code2");
       query.bindValue(":code2",code2);
       query.exec();
       model->setQuery(query);
    return model;
}

QSqlQueryModel* subscriptions::find_startDate(QString code3)
{
    QSqlQuery query ;
       QSqlQueryModel* model=new QSqlQueryModel();
       query.prepare("select * from SUBSCRIPTIONS where s_date =:code3");
       query.bindValue(":code3",code3);
       query.exec();
       model->setQuery(query);
    return model;
}

//Recherche avancée
void subscriptions::findNum(QTableView *table, int x)
{
      QSqlQueryModel *model=new QSqlQueryModel();
      QSqlQuery *query =new QSqlQuery;
      query->prepare("select * from SUBSCRIPTIONS where regexp_like(num_sub,:num_sub);");
      query->bindValue(":num_sub",x);

      if(x==0)
      {
          query->prepare("select * from SUBSCRIPTIONS;");
      }
      query->exec();
      model->setQuery(*query);
      table->setModel(model);
      table->show();
}
void subscriptions::findType(QTableView *table, QString x)
{
      QSqlQueryModel *model=new QSqlQueryModel();
      QSqlQuery *query =new QSqlQuery;
      query->prepare("select * from SUBSCRIPTIONS where regexp_like(type_sub,:type_sub);");
      query->bindValue(":type_sub",x);

      if(x==0)
      {
          query->prepare("select * from SUBSCRIPTIONS;");
      }
      query->exec();
      model->setQuery(*query);
      table->setModel(model);
      table->show();
}
void subscriptions::findStartDate(QTableView *table, QString x)
{
      QSqlQueryModel *model=new QSqlQueryModel();
      QSqlQuery *query =new QSqlQuery;
      query->prepare("select * from SUBSCRIPTIONS where regexp_like(s_date,:s_date);");
      query->bindValue(":s_date",x);

      if(x==0)
      {
          query->prepare("select * from SUBSCRIPTIONS;");
      }
      query->exec();
      model->setQuery(*query);
      table->setModel(model);
      table->show();
}

float subscriptions::read_price()
{
    float x;
     QSqlQueryModel *model=new QSqlQueryModel();
     QSqlQuery *query =new QSqlQuery;
     query->prepare("select price_sub from SUBSCRIPTIONS where (num_sub=45) ;");
     query->bindValue(":price_sub",x);
     return x;
}

QString subscriptions::read_sdate()
{
    QString x;
     QSqlQueryModel *model=new QSqlQueryModel();
     QSqlQuery *query =new QSqlQuery;
     query->prepare("select s_date from SUBSCRIPTIONS where num_sub=5) ;");
     query->bindValue(":s_date",x);
     return x;

}

void subscriptions::statistique(QVector<double>* ticks,QVector<QString> *labels)
{
    QSqlQuery q;
    int i=0;
    q.exec("SELECT upper(type_sub) FROM subscriptions group BY upper(type_sub) order by (upper(type_sub)) asc;");
    while (q.next())
    {
        QString identifiant = q.value(0).toString();
        i++;
        *ticks<<i;
        *labels <<identifiant;
    }
}
void subscriptions::historique(QString x,QString val1,QString val2,QString val3,QString val4,QString val5,QString val6,QString val7)
{
QFile file("Historique.txt");
if (file.open(QIODevice::Append | QIODevice::Text))
{
    QTextStream ecriture(&file);
    ecriture<< x << "Number "+val1 << " Type "+val2 << " Duration "+val3 << " bn "+val4 << " Duration "+val5 << " Duration "+val6 << " Duration "+val7 << endl;
    file.close();
}
}

void subscriptions::historique2(QString message)
{
    QFile file("Historique.txt");
    if (file.open(QIODevice::Append | QIODevice::Text))
    {
       QTextStream ecriture(&file);
       ecriture << message << endl;
       file.close();
    }
}
