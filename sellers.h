#ifndef SELLER_H
#define SELLER_H
#include <QString>
#include <QSqlQueryModel>
#include <QTableView>
class Seller
{
public:
    Seller();
    Seller(int,QString,QString,QString,int,QString);
    int getid_sel();
    QString getlastname_sel();
    QString getname_sel();
    QString getadress_sel();
    int getnum_sel();
    QString getmail_sel();
    void setid_sel(int);
    void setlastname_sel(QString);
    void setname_sel(QString);
    void setadress_sel(QString);
    void setnum_sel(int);
    void setmail_sel(QString);
    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int);
    bool modifier(int);
    QSqlQueryModel* read_id();
    QSqlQueryModel * sort_name();
    QSqlQueryModel * sort_id();
    QSqlQueryModel * sort_adress();
    QSqlQueryModel * find_id(int);
    QSqlQueryModel * find_name(QString);
    QSqlQueryModel * find_adress(QString);
    void cleartable (QTableView *table);
    void search_id(QTableView *table, int x);
    void search_name(QTableView *table, QString x);
    void search_adress(QTableView *table, QString x);
    QSqlQueryModel* read_id_buy();
private:
    int id_sel;
    QString lastname_sel;
    QString name_sel;
    QString adress_sel;
    int num_sel;
    QString mail_sel;



};

#endif // SELLER_H
