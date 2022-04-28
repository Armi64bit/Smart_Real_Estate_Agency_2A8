#include"agent.h"
#include<QMessageBox>
#include <QtSql>
#include <QTableView>
agent::agent()
{
    cin_ag=0;
    lastname_ag="";
    name_ag="";
    num_ag=0;
    mail_ag="";
    adress_ag="";
    function_ag="";
    login_ag="";
    password_ag="";


}

agent::agent(int cin_ag,QString lastname_ag, QString name_ag, int num_ag,QString mail_ag   , QString adress_ag, QString function_ag ,QString login_ag ,QString password_ag  )
{

      this->cin_ag=cin_ag;
      this->lastname_ag=lastname_ag;
      this->name_ag=name_ag;
      this->num_ag=num_ag;
      this->mail_ag=mail_ag;
      this->adress_ag=adress_ag;
      this->function_ag=function_ag;
      this->login_ag=login_ag;
      this->password_ag=password_ag;

}


// getters



// les fonction crud


bool agent::ajouter()
{
 QSqlQuery query;
 QString res = QString::number(cin_ag);
 QString res1 = QString::number(num_ag);

 //prend la requête en paramètre pour préparer son execution
 query.prepare("insert into AGENTS(cin_ag,lastname_ag, name_ag,num_ag,mail_ag,adress_ag,function_ag,login_ag,password_ag) VALUES(:cin_ag,:lastname_ag,:name_ag,:num_ag,:mail_ag,:adress_ag,:function_ag,:login_ag,:password_ag)");
 //creation des variables liées
 query.bindValue(":cin_ag",res);

  query.bindValue(":lastname_ag",lastname_ag);
  query.bindValue(":name_ag",name_ag);
  query.bindValue(":num_ag",res1);
  query.bindValue(":mail_ag",mail_ag);
  query.bindValue(":adress_ag",adress_ag);
  query.bindValue(":function_ag",function_ag);
  query.bindValue(":login_ag",login_ag);
  query.bindValue(":password_ag",password_ag);
 return query.exec(); //envoie la requete pour l'executer
}

bool agent::supprimer(int cin_ag)
{
    QSqlQuery query ;
    QString res=QString ::number(cin_ag);
    query.prepare("Delete from AGENTS where cin_ag=:cin_ag");

    query.bindValue(":cin_ag",res);
    return  query.exec();





}

QSqlQueryModel * agent::afficher(){


QSqlQueryModel * model = new QSqlQueryModel();
model->setQuery("select * from agents");
model->setHeaderData(0,Qt::Horizontal,QObject::tr("cin_ag"));
model->setHeaderData(1,Qt::Horizontal,QObject::tr("lastname_ag"));
model->setHeaderData(2,Qt::Horizontal,QObject::tr("name_ag"));
model->setHeaderData(3,Qt::Horizontal,QObject::tr("num_ag"));
model->setHeaderData(4,Qt::Horizontal,QObject::tr("mail_ag"));
model->setHeaderData(5,Qt::Horizontal,QObject::tr("adress_ag"));
model->setHeaderData(6,Qt::Horizontal,QObject::tr("function_ag"));
model->setHeaderData(7,Qt::Horizontal,QObject::tr("login_ag"));
model->setHeaderData(8,Qt::Horizontal,QObject::tr("password_ag"));
return  model;
}


// modification

bool agent::modifier(int cin){


        QSqlQuery  query;
        QString res = QString::number(cin);
        QString tes = QString::number(num_ag);
    query.prepare("update agents set  lastname_ag=:lastname_ag , name_ag=:name_ag, num_ag=:num_ag, mail_ag=:mail_ag , adress_ag=:adress_ag , function_ag=:function_ag , login_ag=:login_ag , password_ag=:password_ag  where cin_ag=:cin");
       //creation des variables liées
       query.bindValue(":cin",res);
       query.bindValue(":lastname_ag",lastname_ag);
       query.bindValue(":name_ag",name_ag);
       query.bindValue(":num_ag", tes);
       query.bindValue(":mail_ag", mail_ag);
       query.bindValue(":adress_ag",adress_ag);
       query.bindValue(":function_ag",function_ag);
       query.bindValue(":login_ag",login_ag);
       query.bindValue(":password_ag",password_ag);
       return query.exec(); //envoie la requete pour l'executer


}

QSqlQueryModel * agent::afficher_id()
{QSqlQueryModel *model=new QSqlQueryModel();
model->setQuery("select cin_ag from agents");
model->setHeaderData(0,Qt::Horizontal,QObject::tr("cin_ag"));
return model;
}

// tri par cin
QSqlQueryModel * agent::sort_cin_ag(){
    QSqlQueryModel * model= new QSqlQueryModel();
        model->setQuery("select * from agents order by cin_ag");
        return model;
}
// tri name
QSqlQueryModel * agent::sort_name_ag(){

    QSqlQueryModel * model= new QSqlQueryModel();
        model->setQuery("select * from agents order by name_ag ");
        return model;
}

// tri function
QSqlQueryModel * agent::sort_function_ag(){
    QSqlQueryModel * model= new QSqlQueryModel();
        model->setQuery("select * from agents order by function_ag  ");
        return model;
}
// clear table
//void cleartable(QTableView * table );

void agent::cleartable(QTableView *table){

     QSqlQueryModel *model=new QSqlQueryModel();
     model->clear();
     table->setModel(model);


}





// recherche


void agent::rechercher_name(QTableView *table, QString x)
   {
      QSqlQueryModel *model=new QSqlQueryModel();
      QSqlQuery *query =new QSqlQuery;
      query->prepare("select * from agents where regexp_like(name_ag,:name_ag);");
      query->bindValue(":name_ag",x);

      if(x==0)
      {
          query->prepare("select * from agents;");
      }
      query->exec();
      model->setQuery(*query);
      table->setModel(model);
      table->show();
   }
void agent::rechercher_cin(QTableView *table, int x)
   {
      QSqlQueryModel *model=new QSqlQueryModel();
      QSqlQuery *query =new QSqlQuery;
      query->prepare("select * from agents where regexp_like(cin_ag,:cin_ag);");
      query->bindValue(":cin_ag",x);

      if(x==0)
      {
          query->prepare("select * from agents;");
      }
      query->exec();
      model->setQuery(*query);
      table->setModel(model);
      table->show();
   }
void agent::rechercher_function(QTableView *table, QString x)
{

    QSqlQueryModel *model=new QSqlQueryModel();
    QSqlQuery *query =new QSqlQuery;
    query->prepare("select * from agents where regexp_like(function_ag,:function_ag);");
    query->bindValue(":function_ag",x);

    if(x==0)
    {
        query->prepare("select * from agents;");
    }
    query->exec();
    model->setQuery(*query);
    table->setModel(model);
    table->show();



}

// afficher nom chat
// QSqlQueryModel * agent::afficher_id()

//QSqlQueryModel *model=new QSqlQueryModel();
//model->setQuery("select cin_ag from agents");
//model->setHeaderData(0,Qt::Horizontal,QObject::tr("cin_ag"));
//return model;

QSqlQueryModel * agent::afficherNom(int id){

    QSqlQueryModel *model=new QSqlQueryModel();
    QSqlQuery *query =new QSqlQuery;
    query->prepare("select name_ag from agents where cin_ag=:id    ");
    query->bindValue(":id",id);
  query->exec();
model->setQuery(*query);


}

