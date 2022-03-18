#ifndef AGENT_H
#define AGENT_H
#include <QString>
#include <QtSql>
#include <QtSql>
#include <QtSql/QtSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtDebug>
#include <QTableView>
class agent
{
public:
     agent ();
     agent(int ,QString , QString , int ,QString    , QString , QString  ,QString  ,QString );

     int     getcin_ag(){return cin_ag;}
     QString getlastname_ag(){ return lastname_ag ;}
     QString getname_ag(){return name_ag ;}
     int     getnum_ag(){return num_ag;}
     QString getmail_ag(){return mail_ag;}
     QString getadress(){return adress_ag;}
     QString getfunction_ag(){return function_ag;}
     QString getlogin_ag(){return  login_ag;}
     QString getpassword_ag(){return password_ag;}
     // setters



     void setcin_ag(int cin_ag ){this->cin_ag=cin_ag;}
     void setlastname_ag(QString lastname_ag ){this->lastname_ag=lastname_ag;}
     void setname_ag (QString  name_ag){this->name_ag=name_ag;}
     void setnum_ag(int num_ag ){this->num_ag=num_ag;}
     void setmail_ag(QString mail_ag){this->mail_ag=mail_ag;}
     void setadress_ag(QString adress_ag){this->adress_ag=adress_ag;}
     void setfunction_ag(QString function_ag ){this->function_ag=function_ag;}
     void setlogin_ag(QString login_ag ){this->login_ag=login_ag;}
     void setpassword_ag(QString password_ag ){this->password_ag=password_ag;}


 bool ajouter();
 bool supprimer(int);
 QSqlQueryModel * afficher();
 bool modifier(int);
 QSqlQueryModel * afficher_id();
 QSqlQueryModel * sort_cin_ag();
 QSqlQueryModel * sort_name_ag();
 QSqlQueryModel * sort_function_ag();
 void cleartable(QTableView * table );
 void rechercher_name(QTableView *table, QString x);
  void rechercher_cin(QTableView *table, int  x);
  private:
   QString lastname_ag,name_ag,mail_ag,adress_ag,function_ag,login_ag,password_ag;
   int cin_ag,num_ag;


};




#endif // AGENT_H
