#include "sellers.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
Seller::Seller()
{
id_sel=0; lastname_sel=" "; name_sel=" "; adress_sel=" "; num_sel=0; mail_sel=" ";
}

Seller::Seller(int id_sel,QString lastname_sel,QString name_sel,QString adress_sel,int num_sel,QString mail_sel)
{this->id_sel=id_sel; this->lastname_sel=lastname_sel; this->name_sel=name_sel; this->adress_sel=adress_sel; this->num_sel=num_sel; this->mail_sel=mail_sel;}
int Seller::getid_sel(){return id_sel;}
QString Seller::getlastname_sel(){return lastname_sel;}
QString Seller::getname_sel(){return name_sel;}
QString Seller::getadress_sel(){return adress_sel;}
int Seller::getnum_sel(){return num_sel;}
QString Seller::getmail_sel(){return mail_sel;}
void Seller::setid_sel(int id_sel){this->id_sel=id_sel;}
void Seller::setlastname_sel(QString lastname_sel){this->lastname_sel=lastname_sel;}
void Seller::setname_sel(QString name_sel){this->name_sel=name_sel;}
void Seller::setadress_sel(QString adress_sel){this->adress_sel=adress_sel;}
void Seller::setnum_sel(int num_sel){this->num_sel=num_sel;}
void Seller::setmail_sel(QString mail_sel){this->mail_sel=mail_sel;}
bool Seller::ajouter()
{


   QString id_string= QString::number(id_sel);
   QString num_string= QString::number(num_sel);
   QSqlQuery query;
         query.prepare("INSERT INTO SELLERS (id_sel, lastname_sel, name_sel, adress_sel, num_sel, mail_sel)"
                       "VALUES (:id, :forename, :surname, :adress, :num, :mail)");
         query.bindValue(":id", id_string);
         query.bindValue(":forename", lastname_sel );
         query.bindValue(":surname", name_sel);
         query.bindValue(":adress", adress_sel);
         query.bindValue(":num", num_string);
         query.bindValue(":mail", mail_sel);

         return query.exec();


}
bool Seller::supprimer(int id_sel)
{
    QSqlQuery query;
          query.prepare(" Delete from SELLERS where id_sel=:id_sel ");
          query.bindValue(0, id_sel);

          return query.exec();
}

QSqlQueryModel* Seller::afficher()
{
  QSqlQueryModel* model=new QSqlQueryModel();

  model->setQuery("SELECT * FROM SELLERS");
       model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_sel"));
       model->setHeaderData(1, Qt::Horizontal, QObject::tr("lastname_sel"));
       model->setHeaderData(2, Qt::Horizontal, QObject::tr("name_sel"));
       model->setHeaderData(3, Qt::Horizontal, QObject::tr("adress_sel"));
       model->setHeaderData(4, Qt::Horizontal, QObject::tr("num_sel"));
       model->setHeaderData(5, Qt::Horizontal, QObject::tr("mail_sel"));


  return model;
}
 bool Seller::modifier(int id_sel)
{

    QSqlQuery  query;
    QString res = QString::number(id_sel);
    QString tes = QString::number(num_sel);
query.prepare("UPDATE SELLERS SET lastname_sel=:lastname,name_sel=:name,adress_sel=:adress,num_sel=:num,mail_sel=:mail WHERE id_sel=:id");
query.bindValue(":id",res);
query.bindValue(":lastname",lastname_sel);
query.bindValue(":name",name_sel);
query.bindValue(":adress",adress_sel);
query.bindValue(":num",tes);
query.bindValue(":mail",mail_sel);
return query.exec();
}
 QSqlQueryModel*  Seller ::read_id()
 {QSqlQueryModel *model=new QSqlQueryModel();
 model->setQuery("select ID_SEL from SELLERS");
 model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_SEL"));
 return model;
 }
