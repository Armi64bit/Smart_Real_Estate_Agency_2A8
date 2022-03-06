#include "partners.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QString>

PARTNERS::PARTNERS(){
    this->ID_PAR=0;
    this->NUM_SUB=0;
     this->NAME_PAR="";
     this->TYPE_PAR="";
     this->DURATION_PAR="";
     this->CONTRACT_LANGUAGE_PAR="";

}
PARTNERS::PARTNERS( int ID_PAR,int NUM_SUB,QString NAME_PAR,QString TYPE_PAR,QString DURATION_PAR,QString CONTRACT_LANGUAGE_PAR)
{this->ID_PAR=ID_PAR;
   this->NUM_SUB=NUM_SUB;
    this->NAME_PAR=NAME_PAR;
    this->TYPE_PAR=TYPE_PAR;
    this->DURATION_PAR=DURATION_PAR;
    this->CONTRACT_LANGUAGE_PAR=CONTRACT_LANGUAGE_PAR;

}
bool PARTNERS::add()
{
    QSqlQuery query;
        //QString id_par = QString::number(id_par);
            query.prepare("INSERT INTO PARTNERS (ID_PAR,NUM_SUB, NAME_PAR, TYPE_PAR,DURATION_PAR,CONTRACT_LANGUAGE_PAR) "
                          "VALUES (:ID_PAR,:NUM_SUB, :NAME_PAR,:TYPE_PAR,:DURATION_PAR, :CONTRACT_LANGUAGE_PAR)");
            query.bindValue(":ID_PAR",ID_PAR);
              query.bindValue(":NUM_SUB",NUM_SUB);
              query.bindValue(":NAME_PAR",NAME_PAR);
              query.bindValue(":TYPE_PAR",TYPE_PAR);
             query.bindValue(":DURATION_PAR",DURATION_PAR);
             query.bindValue(":CONTRACT_LANGUAGE_PAR",CONTRACT_LANGUAGE_PAR);

        if(!query.exec()){
            qDebug()<<"not added";
        }
        return true;
}

QSqlQueryModel * PARTNERS::read()
{   QSqlQueryModel *model=new QSqlQueryModel();
         model->setQuery("SELECT * FROM PARTNERS");
         model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_PAR"));
         model->setHeaderData(1,Qt::Horizontal,QObject::tr("NUM_SUB"));
         model->setHeaderData(2,Qt::Horizontal,QObject::tr("NAME_PAR"));
         model->setHeaderData(3,Qt::Horizontal,QObject::tr("TYPE_PAR"));
         model->setHeaderData(4,Qt::Horizontal,QObject::tr("DURATION_PAR"));
         model->setHeaderData(5,Qt::Horizontal,QObject::tr("CONTRACT_LANGUAGE_PAR"));

return model;
}

QSqlQueryModel*  PARTNERS ::read_id()
{QSqlQueryModel *model=new QSqlQueryModel();

model->setQuery("select ID_PAR from PARTNERS");
model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_PAR"));
return model;
}
QSqlQueryModel * PARTNERS::read1()
{   QSqlQueryModel *model=new QSqlQueryModel();
         model->setQuery("SELECT * FROM PARTNERS");
         return model;
}
bool PARTNERS::dell(int ID_PAR)
{
    QSqlQuery query;
    query.prepare("DELETE FROM PARTNERS where ID_PAR=:ID_PAR");
    query.bindValue(":ID_PAR",ID_PAR);
return query.exec();
}


bool PARTNERS::update(int ID_PAR)
{

    QSqlQuery  query;
query.prepare("UPDATE PARTNERS SET ID_PAR=:ID_PAR,NUM_SUB=:NUM_SUB,NAME_PAR=:NAME_PAR,TYPE_PAR=:TYPE_PAR,DURATION_PAR=:DURATION_PAR,CONTRACT_LANGUAGE_PAR=:CONTRACT_LANGUAGE_PAR WHERE ID_PAR=:ID_PAR");
query.bindValue(":ID_PAR",ID_PAR);
query.bindValue(":NUM_SUB",NUM_SUB);
query.bindValue(":NAME_PAR",NAME_PAR);
query.bindValue(":TYPE_PAR",TYPE_PAR);
query.bindValue(":DURATION_PAR",DURATION_PAR);
query.bindValue(":CONTRACT_LANGUAGE_PAR",CONTRACT_LANGUAGE_PAR);

return query.exec();
}



