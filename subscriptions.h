#ifndef SUBSCRIPTIONS_H
#define SUBSCRIPTIONS_H
#include <QString>
#include <QSqlQueryModel>

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

private:
    int num_sub,idBuy;
    QString type_sub, duration_sub,s_date,e_date;
    float price_sub;


};

#endif // SUBSCRIPTIONS_H
