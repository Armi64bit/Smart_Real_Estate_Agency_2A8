#include "login2.h"
#include "ui_login2.h"
#include "mainwindow.h"
#include <QSqlQuery>
#include <QDebug>
#include <QMainWindow>
#include "ui_mainwindow.h"
#include "mainwindow.h"
login2::login2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::login2)
{
    ui->setupUi(this);
    ui->stackedWidget
}

login2::~login2()
{
    delete ui;
}

void login2::on_login_2_clicked()
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

       //this->hide();
     //MainWindow * newmain = new MainWindow() ;
     //newmain->show();
      // w =new ui::MainWindow;
     // MainWindow->stackedWidget->setCurrentIndex(8);
       /*mainwindow = new MainWindow(this);
              mainwindow->show();*/


        }
        if(c>1)
        ui->label_3->setText(" duplicate username and password   ");

    if(c<1)
        ui->label_3->setText("username and password is not correct  ");
    }
}
