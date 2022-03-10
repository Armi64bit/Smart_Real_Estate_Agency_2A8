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
    void setPrice(QString n);
    void setDescription(QString n);
    void setLng(QVariant lng);
    void setLat(QVariant lat);
    QString get_ID();
    QString get_Type();
    QString get_Price();
    QVariant get_longitude();
    QVariant get_latitude();

    Property();
    Property(QString ID,QString Type,QVariant longitude,QVariant latitude,QString Price,QVariant ID_BUY,QVariant ID_SEL);
    bool addProperty(Property P);
    bool delete_Property(int id_prop);
    bool update(Property P);
    QSqlQueryModel * read();
 QSqlQueryModel * read_buyer();
 QSqlQueryModel * read_seller();
private:
    QString ID,Type,Price,Description;
    QVariant longitude,latitude,ID_BUY,ID_SEL;
};

#endif // PROPERTY_H
