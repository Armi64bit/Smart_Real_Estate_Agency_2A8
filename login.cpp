#include "login.h"
#include "ui_login.h"
#include "mainwindow.h"
#include "form.h"
#include <QSqlQuery>
#include <QDebug>
#include <QMainWindow>
#include "ui_mainwindow.h"
#include "mainwindow.h"
#include <QWidget>
login::login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);

   /* QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
       db.setDatabaseName("fares");
        db.setUserName("fares");//inserer nom de l'utilisateur
        db.setPassword("fares");
        if(db.open()){
            ui->label_3->setText("connected....");

        }
        else {
            ui->label_3->setText(" not connected....");
        }
        */
}

login::~login()
{
    delete ui;
}

void login::on_login_2_clicked()
{
    QString  username,password;
    username= ui->lineEdit->text();
    password=ui->lineEdit_2->text();
int c=0;
QSqlQuery query ;
query.prepare("select * from agents where login_ag=:username and  password_ag=:password  ");
query.bindValue(":username",username);
query.bindValue(":password",password);
if(query.exec()){

   while(query.next()){
       c++;
   }
   /* ui->label_3->setText("username and password is   correct  ");
    }
else if(!query.exec()) {
    ui->label_3->setText("username and password is not correct  ");
}
*/
    if(c==1){
   ui->label_3->setText("username and password is correct  ");

   this->hide();
 MainWindow * newmain = new MainWindow() ;
 newmain->show();
  // w =new ui::MainWindow;
 // MainWindow->stackedWidget->setCurrentIndex(8);
   /*mainwindow = new MainWindow(this);
          mainwindow->show();*/
  /* this->hide();
   mainwindow = new form(this);
   mainwindow->show();*/




    }
    if(c>1)
    ui->label_3->setText(" duplicate username and password   ");

if(c<1)
    ui->label_3->setText("username and password is not correct  ");
}

}

