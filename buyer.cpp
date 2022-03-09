#include"buyer.h"
#include<QMessageBox>
#include<QtSql>
#include<QComboBox>
#include <QtSql/QtSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QString>
buyer::buyer(){
    id_buy=0;
    lastname_buy="";
    name_buy="";
    adress_buy="";
            request_buy="";
    num_buy=0;
    mail_buy="";
}
buyer::buyer(int id_buy, QString lastname_buy , QString name_buy , QString adress_buy , QString request_buy , int num_buy , QString mail_buy, int id_agent)
{
  this->id_buy=id_buy;
  this->lastname_buy=lastname_buy;
    this->name_buy=name_buy;
    this->adress_buy=adress_buy;
    this->request_buy=request_buy;
    this->num_buy=num_buy;
    this->mail_buy=mail_buy;
    this->id_agent=id_agent;
}
bool buyer::addbuyer( )
{
    QSqlQuery query;
    QString res = QString::number(id_buy);
    QString tes = QString::number(num_buy);

       /* QString id_string=QString::number(id);
         QString lastname_string=QString::number(lastname);
          QString name_string=QString::number(name);
           QString adress_string=QString::number(adress);
            QString request_string=QString::number(request);
             QString num_string=QString::number(num);
              QString mail_string=QString::number(mail);*/
        query.prepare("INSERT INTO BUYERS (ID_BUY,LASTNAME_BUY,NAME_BUY,ADRESS_BUY,REQUEST_BUY,NUM_BUY,MAIL_BUY,CIN_AG) VALUES(:id, :lastname, :name,:adress,:request,:num,:mail,:id_agent)");
          query.bindValue(":id",res);
          query.bindValue(":lastname",lastname_buy);
          query.bindValue(":name",name_buy);
          query.bindValue(":adress",adress_buy);
         query.bindValue(":request",request_buy);
         query.bindValue(":num",tes);
         query.bindValue(":mail",mail_buy);
         query.bindValue(":id_agent",id_agent);
    if(!query.exec()){
        qDebug()<<"not added";
    }
    return true;
}


QSqlQueryModel * buyer::read()
{   QSqlQueryModel *model=new QSqlQueryModel();
         model->setQuery("SELECT * FROM BUYERS");
         model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_BUY"));
         model->setHeaderData(1,Qt::Horizontal,QObject::tr("LASTNAME_BUY"));
         model->setHeaderData(2,Qt::Horizontal,QObject::tr("NAME_BUY"));
         model->setHeaderData(3,Qt::Horizontal,QObject::tr("ADRESS_BUY"));
         model->setHeaderData(4,Qt::Horizontal,QObject::tr("REQUEST_BUY"));
         model->setHeaderData(5,Qt::Horizontal,QObject::tr("NUM_BUY"));
         model->setHeaderData(6,Qt::Horizontal,QObject::tr("MAIL_BUY"));
return model;
}
QSqlQueryModel*  buyer ::read_id()
{QSqlQueryModel *model=new QSqlQueryModel();
model->setQuery("select ID_BUY from BUYERS");
model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_BUY"));
return model;
}
QSqlQueryModel * buyer::read1()
{   QSqlQueryModel *model=new QSqlQueryModel();
         model->setQuery("SELECT * FROM BUYERS");
         return model;
}
bool buyer::supprimer(int id_buy)
{
    QSqlQuery query;
    QString res = QString::number(id_buy);
    query.prepare("DELETE FROM BUYERS where id_buy=:id");
    query.bindValue(":id",res);
return query.exec();
}
bool buyer::update(int idRech)
{

    QSqlQuery  query;
    QString res = QString::number(idRech);
    QString tes = QString::number(num_buy);
query.prepare("UPDATE BUYERS SET lastname_buy=:lastname,name_buy=:name,adress_buy=:adress,request_buy=:request,num_buy=:num,mail_buy=:mail WHERE id_buy=:idRech");
query.bindValue(":idRech",res);
query.bindValue(":lastname",lastname_buy);
query.bindValue(":name",name_buy);
query.bindValue(":adress",adress_buy);
query.bindValue(":request",request_buy);
query.bindValue(":num",tes);
query.bindValue(":mail",mail_buy);
return query.exec();
}
bool buyer::read_info(int id){
    QSqlQuery query;
    QString res = QString::number(id);
query.prepare("select * from buyers where ID_BUY=:id");
return query.exec();
}
QSqlQueryModel * buyer::read_agent()
{   QSqlQueryModel *model=new QSqlQueryModel();
         model->setQuery("SELECT * FROM AGENTS");


return model;
}
