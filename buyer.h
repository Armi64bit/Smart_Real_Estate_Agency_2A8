#ifndef BUYER_H
#define BUYER_H
#include <QString>
#include <QtSql>
#include <QtSql>
#include <QtSql/QtSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtDebug>
class buyer
{
public:
   buyer ();
   buyer (int,QString ,QString ,QString ,QString ,int  ,QString,int);
   int getID_BUY(){return id_buy;}
   QString getLASTNAME_BUY(){return lastname_buy;}
   QString getNAME_BUY(){return name_buy;}
   QString getADRESS_BUY(){return adress_buy;}
   QString getREQUEST_BUY(){return request_buy;}
   int getNUM_BUY(){return num_buy;}
   QString getMAIL_BUY(){return mail_buy;}
   void setID_BUY(int id){this->id_buy=id;}
   void setLASTNAME_BUY(QString l){lastname_buy=l;}
   void setNAME_BUY(QString n){name_buy=n;}
   void setADRESS_BUY(QString a){adress_buy=a;}
   void setREQUEST_BUY(QString r){request_buy=r;}
   void setNUM_BUY(int num){this->num_buy=num;}
   void setMAIL_BUY(QString m){mail_buy=m;}
  bool addbuyer ();
  QSqlQueryModel* read();
  QSqlQueryModel* read1();
  QSqlQueryModel* read_id();
  bool supprimer(int);
  bool update(int);  //authentification
  bool read_info(int);
   QSqlQueryModel * read_agent();
private:
  int id_buy,num_buy,id_agent;
   QString lastname_buy, name_buy, adress_buy,request_buy,mail_buy;
};
#endif // PROPERTY_H
