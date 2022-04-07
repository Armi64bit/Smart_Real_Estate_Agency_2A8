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
#include <QComboBox>

login::login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
   //ui->comboBox->setPlaceholderText(QStringLiteral("--Select Country--"));
  //  comboBox->setCurrentIndex(-1);

//

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

    QString  username,password,type;
    username= ui->lineEdit->text();
    password=ui->lineEdit_2->text();
    type=ui->type->text();
int c=0;
QSqlQuery query ;
query.prepare("select * from agents where login_ag=:username and  password_ag=:password and function_ag=:type   ");
query.bindValue(":username",username); // fix la valreur pas d'injection
query.bindValue(":password",password);
query.bindValue(":type",type);
if(query.exec()){
// query.next   exection chnaya bech issir imba3d
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

        if(type=="admin"){


            this->hide();
            // newmain variable pour acceder au mainWindow pour afficher MainWindow (newmain var type mainWindow)
          MainWindow * newmain = new MainWindow() ;
          newmain->hmed(); // fonction pour block les button
          newmain->show(); // affiche mainwindow
        }
        if(type=="buyer"){


            this->hide();
            // newmain variable pour acceder au mainWindow
          MainWindow * newmain = new MainWindow() ;
           newmain->hmed();
          newmain->show();
          newmain->closebutton();

        }



   ui->label_3->setText("username and password is correct  ");

  // w =new ui::MainWindow;
 // MainWindow->stackedWidget->setCurrentIndex(8);
   /*mainwindow = new MainWindow(this);
          mainwindow->show();*/
  /* this->hide();
   mainwindow = new form(this);
   mainwindow->show();*/
 //QPushButton *  pushButton_7 = qobject_cast<QPushButton *>(sender());
  // pushButton_7->setEnabled(false);



    }
    if(c>1)
    ui->label_3->setText(" duplicate username and password   ");

if(c<1)
    ui->label_3->setText("username and password is not correct  ");
}

}


