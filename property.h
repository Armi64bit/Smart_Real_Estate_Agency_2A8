#ifndef PROPERTY_H
#define PROPERTY_H
#include <QString>
#include <QtSql>
#include <QtSql>
#include <QtSql/QtSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtDebug>
class Property
{
public:
    void setID(QString n);
    void setType(QString n);
    void setPrice(QVariant n);
    void setDescription(QString n);
    void setLng(QVariant lng);
    void setLat(QVariant lat);
    QString get_ID();
    QString get_Type();
    QVariant get_Price();
    QVariant get_longitude();
    QVariant get_latitude();

    Property();
    Property(QString ID,QString Type,QVariant longitude,QVariant latitude,QVariant Price,QVariant ID_BUY,QVariant ID_SEL,QString Video,QString Description,QString Image);
    bool addProperty();
    bool delete_Property(int id_prop);
    bool update();
    QSqlQueryModel * read();
 QSqlQueryModel * read_buyer();
 QSqlQueryModel * read_seller();
 QSqlQueryModel * sort_type();
 QSqlQueryModel * find_id(int code);
 QSqlQueryModel * sort_ID();
     QSqlQueryModel * sort_Price();
     QSqlQueryModel * find_type(QString code);
     QSqlQueryModel * find_price(int code);

private:
    QString ID,Type,Description,Video,Image;
    QVariant longitude,latitude,ID_BUY,ID_SEL,Price;
};

#endif // PROPERTY_H
