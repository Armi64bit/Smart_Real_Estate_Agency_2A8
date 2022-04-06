#include "property.h"
#include <QPushButton>

#include <QMessageBox>
#include <QtSql>
Property::Property()
{
ID="";
Type="";
Price="";
longitude=0;
latitude=0;

}
Property::Property(QString ID,QString type,QVariant longitude,QVariant latitude,QVariant Price,QVariant ID_BUY,QVariant ID_SEL,QString Video,QString Description)
{
    this->ID=ID;
    this->Type=type;

    this->latitude=latitude;
    this->longitude=longitude;
    this->Price=Price;
    this->ID_BUY=ID_BUY;
    this->ID_SEL=ID_SEL;
    this->Video=Video ;
    this->Description=Description;
}
void Property::setID(QString n){ID=n;}
void Property::setType(QString n){Type=n;}
void Property::setPrice(QVariant n){Price=n;}
void Property::setDescription(QString n){Price=n;}
void Property::setLng(QVariant n){longitude=n;}
void Property::setLat(QVariant n){latitude=n;}
bool Property::addProperty(Property P)
{


     QSqlQuery query;
     QString map="map";
      qDebug()<<"not added";





     query.prepare("INSERT INTO PROPERTIES (ID_PROP,TYPE_PROP,LOCALISATION_LNG,LOCALISATION_LAT,PRICE_PROP,ID_BUY,ID_SEL,MAP,VIDEO,DESCRIPTION) VALUES (?,?,?,?,?,?,?,?,?,?)");
     query.addBindValue(P.ID);
     query.addBindValue(P.Type);
    // query.addBindValue(Description);
     query.addBindValue(P.longitude);
     query.addBindValue(P.latitude);

       query.addBindValue(P.Price);
      query.addBindValue(P.ID_BUY);
      query.addBindValue(P.ID_SEL);
      query.addBindValue(map);
      query.addBindValue(P.Video);
      query.addBindValue(P.Description);

     if(!query.exec())
     {
         qDebug()<<"not added";
     }
  return true ;
}
bool Property::update(Property P)
{

    QSqlQuery  query;

query.prepare("UPDATE PROPERTIES SET TYPE_PROP=:type,LOCALISATION_LNG=:lng,LOCALISATION_LAT=:lat,PRICE_PROP=:price,ID_BUY=:id_buy,ID_SEL=:id_sel WHERE ID_PROP=:id");
query.bindValue(":id",P.ID);
query.bindValue(":type",P.Type);
query.bindValue(":lng",P.longitude);
query.bindValue(":lat",P.latitude);
query.bindValue(":price",P.Price);
query.bindValue(":id_buy",P.ID_BUY);
query.bindValue(":id_sel",P.ID_SEL);
return query.exec();
}
QSqlQueryModel * Property::read()
{   QSqlQueryModel *model=new QSqlQueryModel();
         model->setQuery("SELECT * FROM PROPERTIES");
         model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_PROP"));
         model->setHeaderData(1,Qt::Horizontal,QObject::tr("TYPE_PROP"));
         model->setHeaderData(2,Qt::Horizontal,QObject::tr("LOCALISATION_LNG"));
         model->setHeaderData(3,Qt::Horizontal,QObject::tr("LOCALISATION_LAT"));
         model->setHeaderData(4,Qt::Horizontal,QObject::tr("PRICE_PROP"));
         model->setHeaderData(5,Qt::Horizontal,QObject::tr("ID_BUY"));
         model->setHeaderData(6,Qt::Horizontal,QObject::tr("ID_SEL"));
          model->setHeaderData(7,Qt::Horizontal,QObject::tr("Map localisation"));
           model->setHeaderData(8,Qt::Horizontal,QObject::tr("Video"));

return model;
}
QSqlQueryModel * Property::read_buyer()
{   QSqlQueryModel *model=new QSqlQueryModel();
         model->setQuery("SELECT * FROM BUYERS");


return model;
}
QSqlQueryModel * Property::read_seller()
{   QSqlQueryModel *model=new QSqlQueryModel();
         model->setQuery("SELECT * FROM SELLERS");

return model;
}
bool Property::delete_Property(int id_prop)
{
    QSqlQuery query;
    QString res = QString::number(id_prop);
    query.prepare("DELETE FROM PROPERTIES where id_prop=:id");
    query.bindValue(":id",res);
return query.exec();

}

//////////////////tri et recherche
 QSqlQueryModel * Property::sort_ID(){
QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from PROPERTIES order by ID_PROP");
    return model;
}
QSqlQueryModel * Property::sort_type(){
    QSqlQueryModel * model= new QSqlQueryModel();
        model->setQuery("select * from PROPERTIES order by lower(TYPE_PROP) ");
        return model;
}

QSqlQueryModel * Property::sort_Price(){
    QSqlQueryModel * model= new QSqlQueryModel();
        model->setQuery("select * from PROPERTIES ORDER BY PRICE_PROP ASC");
        return model;
}
///recherche
QSqlQueryModel * Property::find_id(int code)
{
    QSqlQuery query ;
    QSqlQueryModel* model=new QSqlQueryModel();
   query.prepare("select * from PROPERTIES where ID_PROP =:code");
    query.bindValue(":code",code);
    query.exec();
    model->setQuery(query);
return model;
}
QSqlQueryModel * Property::find_type(QString code)
{
    QSqlQuery query ;
    QSqlQueryModel* model=new QSqlQueryModel();
   query.prepare("select * from PROPERTIES where TYPE_PROP =:code");
    query.bindValue(":code",code);
    query.exec();
    model->setQuery(query);
return model;
}
QSqlQueryModel * Property::find_price(int code)
{
    QSqlQuery query ;
    QSqlQueryModel* model=new QSqlQueryModel();
   query.prepare("select * from PROPERTIES where PRICE_PROP =:code");
    query.bindValue(":code",code);
    query.exec();
    model->setQuery(query);
return model;
}


QString Property::get_ID(){return ID;}
QVariant Property::get_Price(){return Price;}
QString Property::get_Type(){return Type ;}
