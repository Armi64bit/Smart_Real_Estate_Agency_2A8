#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QMessageBox>
#include <QtSql/QSqlQuery>
#include<QFileDialog>
#include"agent.h"
#include "login.h"
#include <QTcpSocket>
#include <QSqlQueryModel>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QMessageBox>
#include "QIntValidator"
#include <QDateEdit>
#include <QPlainTextEdit>
#include <QTextStream>
#include <QTextDocument>
#include <QtPrintSupport/QPrintDialog>
#include <QtPrintSupport/QPrinter>
#include <QTextStream>
#include <QPainter>
#include <QTextStream>
#include <QFileDialog>
#include <QTextDocument>
#include <QtPrintSupport/QPrinter>
#include <QFileDialog>
#include <QTextDocument>
#include <strstream>
#include <QSystemTrayIcon>
#include <QRegExpValidator>
#include <QDesktopServices>
#include <QUrl>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QTcpSocket>
#include <QQuickItem>
#include <QFile>
#include <QMediaPlayer>
#include "buyer.h"
#include "email.h"
#include <QtWidgets>
#include<QFileDialog>
#include "subscriptions.h"
#include"exporttoexcelfile.h"
#include <iostream>
#include <QProgressBar>
#include <QFile>
#include"partners.h"
#include "sellers.h"
#include "notification.h"
#include "dialog.h"
#include "property.h"
#include <QApplication>
#include <QQmlApplicationEngine>
#include <QGuiApplication>
#include "map.h"
#include <QMetaObject>
#include "camera.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    mSocket=new QTcpSocket(this);
        mSocket->connectToHost("localhost",2000);
        if (mSocket->waitForConnected(3000))
        {
            ui->plainTextEdit->appendPlainText("se connecter correctement");
        }
        else
        {
            ui->plainTextEdit->appendPlainText("pas de connexion");
        }
        connect(mSocket,SIGNAL(readyRead()),this,SLOT(leer()));
        Property P;
         ui->comboBox_10->setModel(P.read());
        ui->tableView_2_prop->setModel(P.read());
        ui->comboBox_7->setModel(P.read());
        ui->comboBox_8->setModel(P.read_buyer());
        ui->comboBox_9->setModel(P.read_seller());
subscriptions Sub;
ui->comboBox_3->setModel(S.read_id());
ui->comboBox_6->setModel(S.read_id_buy());
    agent a ;
    PARTNERS p;
    //subscription:
    ui->comboBox->setModel(S.read_id());
    ui->tab_seller->setModel(S.afficher());
         ui->tab_subscriptions_2->setModel(Sub.read());
ui->idbox_2->setModel(p.read_id());
ui->tab_produit_3->setModel(p.read());
    ui->comboBox_5->setModel(Sub.read_id());
    ui->comboBox_4->setModel(Sub.read_buyer());
    ui->comboBox_buyer_3->setModel(b.read_id());
    ui->comboBox_buyer_1->setModel(b.read_agent());
    ui->comboBox_buyer_2->setModel(b.read_id());
    ui->tab_produit->setModel(b.read());
    ui->tabagent->setModel(a.afficher());
    ui->comboBox_agent->setModel(a.afficher_id());
    ui->agent_cin->setValidator( new QIntValidator(10000000, 999999999, this));
            ui->agent_num ->setValidator( new QIntValidator(10000000, 999999999, this));
//ui->pushButton_7->setDisabled(true);



            QRegularExpression rx("\\b[A-Z ._%+-]+@[A-Z .-]+\\.[A-Z]\\b",
                                              QRegularExpression::CaseInsensitiveOption);
                    ui->agent_lastname->setValidator(new QRegularExpressionValidator(rx, this));

                    QRegularExpression rx1("\\b[A-Z ._%+-]+@[A-Z .-]+\\.[A-Z]\\b",
                                                  QRegularExpression::CaseInsensitiveOption);
                        ui->agent_name->setValidator(new QRegularExpressionValidator(rx1, this));

                        QRegularExpression rx2("\\b[A-Z ._%+-]+@[A-Z .-]+\\.[A-Z]\\b",
                                                      QRegularExpression::CaseInsensitiveOption);
                            ui->agent_adress->setValidator(new QRegularExpressionValidator(rx2, this));
                            QRegularExpression rx3("\\b[A-Z 1-9 ._%+-]+@[A-Z 1-9 .-]+\\.[A-Z]\\b",
                                                              QRegularExpression::CaseInsensitiveOption);
                                    ui->agent_mail ->setValidator(new QRegularExpressionValidator(rx, this));

                                    QRegularExpression rx4("\\b[A-Z._%+-]+@[A-Z.-]+\\.[A-Z]\\b",
                                                                  QRegularExpression::CaseInsensitiveOption);
                                     ui->agent_adress->setValidator(new QRegularExpressionValidator(rx, this));
                                     QRegularExpression rx5("\\b[A-Z._%+-]+@[A-Z.-]+\\.[A-Z]\\b",
                                                                   QRegularExpression::CaseInsensitiveOption);
                                      ui->agent_function->setValidator(new QRegularExpressionValidator(rx, this));
                                      QRegularExpression rx6("\\b[A-Z._%+-]+@[A-Z.-]+\\.[A-Z]\\b",
                                                                    QRegularExpression::CaseInsensitiveOption);
                                       ui->agent_login->setValidator(new QRegularExpressionValidator(rx, this));

                                       QRegularExpression rx7("\\b[A-Z._%+-]+@[A-Z.-]+\\.[A-Z]\\b",
                                                                     QRegularExpression::CaseInsensitiveOption);
                                        ui->agent_pass->setValidator(new QRegularExpressionValidator(rx, this));
                                        ui->lineEdit_id_buyer->setValidator( new QIntValidator(0, 999999, this));
                                        ui->lineEdit_num_buyer->setValidator( new QIntValidator(0, 99999999, this));





                                        QRegularExpression rx8("\\b[A-Z ._%+-]+@[A-Z .-]+\\.[A-Z]\\b",
                                                                          QRegularExpression::CaseInsensitiveOption);
                                                ui->lineEdit_lastname_buyer->setValidator(new QRegularExpressionValidator(rx8, this));

                                                QRegularExpression rx9("\\b[A-Z ._%+-]+@[A-Z .-]+\\.[A-Z]\\b",
                                                                              QRegularExpression::CaseInsensitiveOption);
                                                    ui->lineEdit_name_buyer->setValidator(new QRegularExpressionValidator(rx9, this));

                                                    QRegularExpression rx10("\\b[A-Z ._%+-]+@[A-Z .-]+\\.[A-Z]\\b",
                                                                                  QRegularExpression::CaseInsensitiveOption);
                                                        ui->lineEdit_adress_buyer->setValidator(new QRegularExpressionValidator(rx10, this));
                                                        QRegularExpression rx11("\\b[A-Z 1-9 ._%+-]+@[A-Z 1-9 .-]+\\.[A-Z]\\b",
                                                                                          QRegularExpression::CaseInsensitiveOption);
                                                                ui->lineEdit_request_buyer->setValidator(new QRegularExpressionValidator(rx11, this));

                                                                QRegularExpression rx12("\\b[A-Z._%+-]+@[A-Z.-]+\\.[A-Z]\\b",
                                                                                              QRegularExpression::CaseInsensitiveOption);
                                                                 ui->lineEdit_mail_buyer->setValidator(new QRegularExpressionValidator(rx12, this));
                                                                 ///subscription controle de saisie

                                                                  ui->le_num_3->setValidator( new QIntValidator(0, 999999, this));
                                                                 QRegularExpression rx99("\\b[1-9 A-Z]+[A-Z 1-9]\\b",
                                                                 QRegularExpression::CaseInsensitiveOption);
                                                                 ui->le_type_2->setValidator(new QRegularExpressionValidator(rx99, this));
                                                                 ui->le_type_modif_2->setValidator(new QRegularExpressionValidator(rx99, this));
                                                                 QRegularExpression rx13("\\b[1-9 A-Z]+[A-Z 1-9]\\b",
                                                                 QRegularExpression::CaseInsensitiveOption);
                                                                 ui->le_durt_2->setValidator(new QRegularExpressionValidator(rx13, this));
                                                                 ui->le_duration_modif_2->setValidator(new QRegularExpressionValidator(rx13, this));
                                                                 QRegularExpression rx14("\\b[0-9]+/[0-9]+/[0-9]+/[0-9]\\b",
                                                                 QRegularExpression::CaseInsensitiveOption);
                                                                 ui->le_sdate_2->setValidator(new QRegularExpressionValidator(rx14, this));
                                                                 ui->le_sdate_modif_2->setValidator(new QRegularExpressionValidator(rx14, this));
                                                                 QRegularExpression rx15("\\b[0-9]+/[0-9]+/[0-9]+/[0-9]\\b",
                                                                 QRegularExpression::CaseInsensitiveOption);
                                                                 ui->le_edate_2->setValidator(new QRegularExpressionValidator(rx15, this));
                                                                 ui->le_edate_modif_2->setValidator(new QRegularExpressionValidator(rx15, this));
                                                                 QRegularExpression rx16("\\b[0-9]+.+[0-9]\\b",
                                                                 QRegularExpression::CaseInsensitiveOption);
                                                                 ui->le_price_2->setValidator(new QRegularExpressionValidator(rx16, this));
                                                                 ui->le_price_modif_2->setValidator(new QRegularExpressionValidator(rx16, this));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::update_label()
{
    data=A.read_from_arduino();




     if (data=="0")
     {
qDebug()<<"data est: "<< data ;
ui->label_63->setText("no one is detected !");
 ui->label_64->setText("no one is detected to launch alarm ?");
     }
       else if(data=="2")
    {
            qDebug()<<"2 est envoyé";
 ui->label_63->setText("SOMEONE IS DETECTED !");
  ui->label_64->setText("LAUNCH ALARM ?");
            camera.show();
          camera.takeImage();
          camera.add_image_todatabase();
          //QThread::msleep(5000);
          camera.applicationExiting=true;


        }
}
void MainWindow::on_pushButton_clicked()
{
     ui->stackedWidget->setCurrentIndex(2);


}





void MainWindow::on_pushButton_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);

}

void MainWindow::on_pushButton_8_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);

}

void MainWindow::on_pushButton_11_clicked()
{
     ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_12_clicked()
{
      ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_13_clicked()
{
      ui->stackedWidget->setCurrentIndex(1);
}





// bouton ajout
void MainWindow::on_pushButton_2_clicked()
{

            int cin_ag=ui->agent_cin->text().toInt();

             QString lastname_ag =ui->agent_lastname->text();
            QString name_ag = ui->agent_name->text();
           int num_ag = ui->agent_num->text().toInt();
           QString mail_ag = ui->agent_mail->text();
            QString adress_ag=ui->agent_adress->text();
           QString function_ag =ui->agent_function->text();
           QString login_ag =ui->agent_login->text();
           QString password_ag =ui->agent_pass->text();
agent a ( cin_ag,lastname_ag,  name_ag, num_ag, mail_ag   ,  adress_ag,  function_ag , login_ag , password_ag );
           bool test=a.ajouter();
           if(test)
               {

               agent a ;
               ui->tabagent->setModel(a.afficher());
                   QMessageBox::information(nullptr, QObject::tr("OK"),
                               QObject::tr("Modification effectuée.\n"
                                           "Click Cancel to exit."), QMessageBox::Cancel);
               }
               else
               {
               agent a ;
               ui->tabagent->setModel(a.afficher());
                   QMessageBox::critical(nullptr, QObject::tr("Failed"),
                               QObject::tr("Modification non effectuée.\n"
                                           "Click Cancel to exit."), QMessageBox::Cancel);
               }


}

void MainWindow::on_pushButton_3_clicked()
{

    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
       db.setDatabaseName("realestate");
       db.setUserName("fares");//inserer nom de l'utilisateur
       db.setPassword("fares");
       if(db.open()){
           QMessageBox::information(this,"Connection","Database Connected Successfully");
       }
       else{
           QMessageBox::information(this,"Not Connected","Database Not connected");
       }


}
// bouton supprimer


void MainWindow::on_pushButton_6_clicked()
{
    //  mail_ag= :mail_ag , adress_ag= :adress_ag , function_ag= :function_ag , login_ag= :login_ag , password_ag= :password_ag  where cin_ag= :cin"


    int cin_ag=ui->lineEdit_cin_3->text().toInt();
                 QString lastname_ag=ui->lineEdit_lastname_2->text();
                  QString name_ag=ui->lineEdit_name_2->text();
                int  num_ag=ui->lineEdit_number_2->text().toInt() ;
                   QString mail_ag=ui->lineEdit_mail_2->text();
                   QString adress_ag=ui->lineEdit_adress_2->text();
                     QString mail_buy=ui->lineEdit_mail_2->text();
                   QString function_ag=ui->lineEdit_login_2->text();
                   QString login_ag=ui->lineEdit_login_2->text();
                 QString password_ag=ui->lineEdit_password_2->text();


    agent b (cin_ag,lastname_ag,name_ag,num_ag,mail_ag,adress_ag,function_ag,login_ag,password_ag);
                 b.modifier(cin_ag);
                 if(b.modifier(cin_ag))
                 {   ui->tabagent->setModel(b.afficher());
                  //   ui->comboBox->setModel(b.read_id());

                    // ui->comboBox_2->setModel(b.read_agent());
             QMessageBox::information(nullptr,QObject::tr("OK"),
                                    QObject::tr("update effectue.\n"
                                                "clic cancel to exit."),QMessageBox::Cancel);

                 }
         else
             {ui->tabagent->setModel(b.afficher());
         QMessageBox::critical(nullptr,QObject::tr("NOT OK"),
                                    QObject::tr("update non effectue.\n"
                                                "clic cancel to exit."),QMessageBox::Cancel);}



}
// modifier
void MainWindow::on_comboBox_agent_currentIndexChanged(int id)
{


    id=ui->comboBox_agent->currentText().toInt();

        QSqlQuery query;

    query.prepare("select * from agents where cin_ag=:id");
    query.bindValue(":id",id);
    if(query.exec())
    {
        while(query.next())
              {
       ui->lineEdit_cin_3->setText(query.value(0).toString());
       ui->lineEdit_lastname_2->setText(query.value(1).toString());
       ui->lineEdit_name_2->setText(query.value(2).toString());
       ui->lineEdit_number_2->setText(query.value(3).toString());
       ui->lineEdit_mail_2->setText(query.value(4).toString());
       ui->lineEdit_adress_2->setText(query.value(5).toString());
       ui->lineEdit_function_2->setText(query.value(6).toString());
        ui->lineEdit_login_2->setText(query.value(6).toString());
         ui->lineEdit_password_2->setText(query.value(6).toString());
        }
    }
}
// supp2
void MainWindow::on_pushButton_7_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
    /*agent a ;
        int cin_ag=ui->lineEdit_cin_3->text().toInt();

     if( a.supprimer(cin_ag)) {

           ui->tabagent->setModel(a.afficher());
                   QMessageBox::information(nullptr,QObject::tr("OK"),
                                          QObject::tr("delete done.\n"
                                                      "clic cancel to exit."),QMessageBox::Cancel);
        }
        else
            {ui->tabagent->setModel(a.afficher());
        QMessageBox::critical(nullptr,QObject::tr("NOT OK"),
                                   QObject::tr("delete not done .\n"
                                               "clic cancel to exit."),QMessageBox::Cancel);}*/
}
// tri cin


void MainWindow::on_pushButton_15_clicked()
{
    ui->tabagent-> setModel(a.sort_cin_ag());
        QMessageBox::information(nullptr, QObject::tr("Ok"),
                    QObject::tr("tri effectu.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pushButton_16_clicked()
{
    ui->tabagent-> setModel(a.sort_name_ag());
        QMessageBox::information(nullptr, QObject::tr("Ok"),
                    QObject::tr("tri effectu.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pushButton_17_clicked()
{
    ui->tabagent-> setModel(a.sort_function_ag());
        QMessageBox::information(nullptr, QObject::tr("Ok"),
                    QObject::tr("tri effectu.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}
// recherche name


void MainWindow::on_lineEdit_cherche_textChanged(const QString &arg1)
{

    a.cleartable(ui->tabagent);
    QString name_ag=ui->lineEdit_cherche->text();
    a.rechercher_name(ui->tabagent,name_ag);
}

void MainWindow::on_lineEdit_cherche_cin_textChanged(const QString &arg1)
{

    a.cleartable(ui->tabagent);
    int  cin_ag=ui->lineEdit_cherche_cin->text().toUInt();
    a.rechercher_cin(ui->tabagent,cin_ag);
}


void MainWindow::on_pushButton_connect_clicked()
{
   login login2 ;
   login2.setModal(true);
    login2.exec();

}

void MainWindow::on_pushButton_9_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_10_clicked()
{ this->close();
    login login2;
    login2.setModal(true);
    login2.exec();



}

// desactiver les bouton
void MainWindow::closebutton()
{
    ui->pushButton_7->setDisabled(true);
    ui->pushButton_19->setDisabled(true);
    ui->pushButton_18->setDisabled(true);
    ui->pushButton_20->setDisabled(true);
    ui->pushButton_22->setDisabled(true);
    ui->pushButton_21->setDisabled(true);
}
void MainWindow::closebutton2()
{
    ui->pushButton_7->setDisabled(true);
    ui->pushButton_19->setDisabled(true);
    ui->pushButton_18->setDisabled(true);
    ui->pushButton_20->setDisabled(true);
    ui->pushButton_22->setDisabled(true);
    ui->pushButton_21->setDisabled(true);
}



void MainWindow::on_pushButton_14_clicked()
{
     ui->stackedWidget->setCurrentIndex(4);
}
// logout
void MainWindow::on_logout_clicked()
{
    this->close();
        login login2;
        login2.setModal(true);
        login2.exec();

}

void MainWindow::hmed(){

    ui->stackedWidget->setCurrentIndex(0);


}
// recherche funtion
void MainWindow::on_lineEdit_cherche_number_textChanged(const QString &arg1)
{
    a.cleartable(ui->tabagent);
    QString function_ag=ui->lineEdit_cherche_function->text();
    a.rechercher_function(ui->tabagent,function_ag);
}
// add picture
void MainWindow::on_photo_2_clicked()
{
    QString filename = QFileDialog::getSaveFileName(this,tr("choose"),"",tr("Image( *.jpeg *.jpg *.bmp *.gif)"));
      if (QString::compare(filename,QString()) !=0)
      {
          QImage image;
          bool valid = image.load(filename);
          if(valid)
          {
              image=image.scaledToWidth(ui->lbl_image_2->width(), Qt::SmoothTransformation);
                      ui->lbl_image_2->setPixmap(QPixmap::fromImage(image));
          }
          else
          {
              //ERROR HANDLING
          }
      }
}
// chat button
/*
void MainWindow::on_comboBox_2_currentIndexChanged(int id)
{
    id= ui->comboBox_2->currentText().toInt();
   QSqlQuery query ;
   query.prepare("select  * from agents where cin_ag=:id ");
   query.bindValue(":id",id);
   if(query.exec()){
    while (query.next())
    {
    ui->lineEdit->setText(query.value(2).toString());
    }


   }
}
*/



void MainWindow::on_chat_clicked()
{

  // login l;
 int  user =ui->comboBox_2->currentText().toInt();
    mSocket->write(ui->lineEdit->text().toLatin1().data(),ui->lineEdit->text().size());
 QSqlQuery  query2;

 //query2.prepare("select name_ag from agents where cin_ag=:login  ");
 //query2.bindValue(":login",user);
 //query2.exec();

       ui->plainTextEdit->appendPlainText(ui->lineEdit->text());

       QString text = ui->lineEdit->text();


       ui->lineEdit->clear();
       QSqlQuery  query;
        qDebug()<<"login est " << user ;
       query.prepare("update AGENTS set chat= concat(concat((select chat from AGENTS),' '),:chat ) WHERE cin_ag=:login ");
       //creation des variables liées
qDebug()<< "chat est"<< text;
       query.bindValue(":chat",text);
       query.bindValue(":login",user);
 qDebug()<<"login est " << user ;
       query.exec();
}

void MainWindow::on_pushButton_24_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);

}

// combo
void MainWindow::on_combo_clicked()
{
 ui->comboBox_2->setModel(a.afficher_id());
}



void MainWindow::on_valider_clicked()
{
    int id_buy=ui->lineEdit_id_buyer->text().toInt();
     QString lastname_buy=ui->lineEdit_lastname_buyer->text();
      QString name_buy=ui->lineEdit_name_buyer->text();
       QString adress_buy=ui->lineEdit_adress_buyer->text();
        QString request_buy=ui->lineEdit_request_buyer->text();
        int num_buy=ui->lineEdit_num_buyer->text().toInt();
          QString mail_buy=ui->lineEdit_mail_buyer->text();
          int id_agent=ui->comboBox_2->currentText().toInt();
          buyer b(id_buy,lastname_buy,name_buy,adress_buy,request_buy,num_buy,mail_buy,id_agent);
          bool test=b.addbuyer();
          if(test)
          {
              ui->comboBox_buyer_2->setModel(b.read_id());
              ui->tab_produit->setModel(b.read());
              ui->comboBox_buyer_3->setModel(b.read_id());
              ui->comboBox_buyer_1->setModel(b.read_agent());
              QMessageBox::information(nullptr,QObject::tr("OK"),
                                     QObject::tr("data added.\n"
                                                 "clicl cancel to exit."),QMessageBox::Cancel);
          }
          else{
              QMessageBox::information(nullptr,QObject::tr("OK"),
                                     QObject::tr("data not added.\n"
                                                 "clicl cancel to exit."),QMessageBox::Cancel);
          }
}

void MainWindow::on_pushButton_delete_clicked()
{
    buyer b;
    int id_buy=ui->lineEdit_del->text().toInt();
    int id_buy2=ui->comboBox_buyer_3->currentText().toInt();
    bool test= b.supprimer(id_buy);
    bool test1= b.supprimer(id_buy2);
    if(test || test1) {
ui->comboBox_buyer_3->setModel(b.read_id());
        ui->tab_produit->setModel(b.read());
       ui->comboBox_buyer_2->setModel(b.read_id());
       ui->comboBox_buyer_1->setModel(b.read_agent());
               QMessageBox::information(nullptr,QObject::tr("OK"),
                                      QObject::tr("delete done.\n"
                                                  "clic cancel to exit."),QMessageBox::Cancel);
    }
    else
        {ui->tab_produit->setModel(b.read());
    QMessageBox::critical(nullptr,QObject::tr("NOT OK"),
                               QObject::tr("delete not done .\n"
                                           "clic cancel to exit."),QMessageBox::Cancel);}
}

void MainWindow::on_update_clicked()
{
    int id_buy=ui->update_id->text().toInt();
             QString lastname_buy=ui->update_lastname->text();
              QString name_buy=ui->update_name->text();
             QString adress_buy=ui->update_adress->text();
               QString request_buy=ui->update_request->text();
                int num_buy=ui->update_num->text().toInt();
                 QString mail_buy=ui->update_mail->text();
                 int id_agent=ui->comboBox_2->currentText().toInt();
 buyer b (id_buy,lastname_buy,name_buy,adress_buy,request_buy,num_buy,mail_buy,id_agent);
             b.update(id_buy);
             if(b.update(id_buy))
             {   ui->tab_produit->setModel(b.read());
                 ui->comboBox_buyer_3->setModel(b.read_id());


         QMessageBox::information(nullptr,QObject::tr("OK"),
                                QObject::tr("update effectue.\n"
                                            "clic cancel to exit."),QMessageBox::Cancel);

             }
     else
         {ui->tab_produit->setModel(b.read());
     QMessageBox::critical(nullptr,QObject::tr("NOT OK"),
                                QObject::tr("update non effectue.\n"
                                            "clic cancel to exit."),QMessageBox::Cancel);}
}

void MainWindow::on_comboBox_buyer_3_currentIndexChanged(int index)
{
    index=ui->comboBox_buyer_3->currentText().toInt();

    QSqlQuery query;

query.prepare("select * from buyers where ID_BUY=:id");
query.bindValue(":id",index);
if(query.exec())
{
    while(query.next())
          {
   ui->update_id->setText(query.value(0).toString());
   ui->update_lastname->setText(query.value(1).toString());
   ui->update_name->setText(query.value(2).toString());
   ui->update_adress->setText(query.value(3).toString());
   ui->update_request->setText(query.value(4).toString());
   ui->update_num->setText(query.value(5).toString());
   ui->update_mail->setText(query.value(6).toString());
    }
}
}

void MainWindow::on_sort_name_buyer_clicked()
{
    ui->tab_produit->setModel(b.sort_name());
    QMessageBox::information(nullptr, QObject::tr("Ok"),
                QObject::tr("tri effectu.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_sort_request_buyer_clicked()
{
    ui->tab_produit->setModel(b.sort_request());
   QMessageBox::information(nullptr, QObject::tr("Ok"),
               QObject::tr("tri effectu.\n"
                           "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_sort_adress_buyer_clicked()
{
    ui->tab_produit->setModel(b.sort_adress());
    QMessageBox::information(nullptr, QObject::tr("Ok"),
                QObject::tr("tri effectu.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_sort_id_buyer_clicked()
{
    ui->tab_produit->setModel(b.sort_id());
    QMessageBox::information(nullptr, QObject::tr("Ok"),
                QObject::tr("tri effectu.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);
}
void MainWindow::on_chercher_id_textChanged(const QString &arg1)
{
b.cleartable(ui->tab_produit);
int id_buy=ui->chercher_id->text().toInt();
b.finda_id(ui->tab_produit, id_buy);
}

void MainWindow::on_chercher_name_textChanged(const QString &arg1)
{
    b.cleartable(ui->tab_produit);
    QString name_buy=ui->chercher_name->text();
    b.finda_name(ui->tab_produit, name_buy);
}

void MainWindow::on_chercher_request_textChanged(const QString &arg1)
{
    b.cleartable(ui->tab_produit);
    QString request_buy=ui->chercher_request->text();
    b.finda_request(ui->tab_produit, request_buy);
}



void MainWindow::on_mailling_clicked()
{
    email email;
    email.setModal(true);
    email.exec();
}
void MainWindow::on_inserer_photo_clicked()
{
    int id_buy1 = ui->comboBox_buyer_2->currentText().toInt();

    QPdfWriter pdf("C:/Users/21629/Desktop/buyers/Liste.pdf");

    QPainter painter(&pdf);

    int i = 4000;
    painter.setPen(Qt::black);
    painter.setFont(QFont("Arial", 30));
    painter.drawPixmap(QRect(400,400,2000,2000),QPixmap("C:/Users/21629/Desktop/aziz/logo.png"));
    painter.drawText(3000,1500,"BUYER'S REQUESt");
    /*painter.setPen(Qt::blue);
    painter.setFont(QFont("Arial", 50));
    painter.drawRect(2700,200,6300,2600);
    painter.drawRect(0,3000,9600,500);*/
    painter.setPen(Qt::darkYellow);
    painter.setFont(QFont("Arial", 11));
    /*painter.drawText(300,3300,"id_Buy");
    painter.drawText(1600,3300,"lastname");
    painter.drawText(2900,3300,"name");
    painter.drawText(4200,3300,"adress");
    painter.drawText(5500,3300,"request");
    painter.drawText(6800,3300,"Num");
    painter.drawText(8100,3300,"mail");*/
    QSqlQuery query;
    query.prepare("<SELECT CAST( GETDATE() AS Date ) ");
    time_t tt;
    struct tm* ti;
    time(&tt);
    ti=localtime(&tt);
    asctime(ti);
    painter.drawText(500,300, asctime(ti));
    query.prepare("select * from BUYERS WHERE ID_BUY=:id_buy1 ");
    query.bindValue(":id_buy1",id_buy1);
    query.exec();
    while (query.next())
    {
        painter.setPen(Qt::black);
        painter.setFont(QFont("Arial", 11));
        painter.drawText(300,i,"I am the buyer with the id");
        painter.setPen(Qt::blue);
        painter.drawText(2500,i,query.value(0).toString());
        painter.setPen(Qt::black);
        painter.drawText(2800,i,"named");
        painter.setPen(Qt::blue);
        painter.drawText(3600,i,query.value(1).toString());
        painter.drawText(5000,i,query.value(2).toString());
        painter.setPen(Qt::black);
        painter.drawText(7000,i,"with the adress");
        painter.setPen(Qt::blue);
        painter.drawText(8500,i,query.value(3).toString());
        painter.setPen(Qt::black);
        painter.drawText(300,4500,"with the phone number");
        painter.setPen(Qt::blue);
        painter.drawText(2500,4500,query.value(5).toString());
        painter.setPen(Qt::black);
        painter.drawText(300,5000,"with the Mail adress");
        painter.setPen(Qt::blue);
        painter.drawText(2500,5000,query.value(6).toString());
        painter.setPen(Qt::black);
        painter.drawText(300,5500,"with the Request:");
        painter.setPen(Qt::blue);
        painter.drawText(300,6000,query.value(4).toString());
        painter.setPen(Qt::darkYellow);
        painter.drawText(4000,9000,"signature of the buyer");
        i = i +500;
    }

    int reponse = QMessageBox::question(this, "PDF generated", "read pdf ?", QMessageBox::Yes |  QMessageBox::No);
    if (reponse == QMessageBox::Yes)
    {
        QDesktopServices::openUrl(QUrl::fromLocalFile("C:/Users/21629/Desktop/buyers/Liste.pdf"));

        painter.end();
    }
    if (reponse == QMessageBox::No)
    {
        painter.end();
    }
}
void MainWindow::on_recommand_clicked()
{
    b.cleartable(ui->tableView2);
  QString city =ui->city->text();
 b.recomondation(ui->tableView2,city);
}





void MainWindow::on_pushButton_23_clicked()
{
    agent a ;
        int cin_ag=ui->comboBox_agent->currentText().toInt();

     if( a.supprimer(cin_ag)) {

           ui->tabagent->setModel(a.afficher());
                   QMessageBox::information(nullptr,QObject::tr("OK"),
                                          QObject::tr("delete done.\n"
                                                      "clic cancel to exit."),QMessageBox::Cancel);
        }
        else
            {ui->tabagent->setModel(a.afficher());
        QMessageBox::critical(nullptr,QObject::tr("NOT OK"),
                                   QObject::tr("delete not done .\n"
                                               "clic cancel to exit."),QMessageBox::Cancel);}
}



void MainWindow::on_add_ag_clicked()
{
    int cin_ag=ui->agent_cin->text().toInt();

     QString lastname_ag =ui->agent_lastname->text();
    QString name_ag = ui->agent_name->text();
   int num_ag = ui->agent_num->text().toInt();
   QString mail_ag = ui->agent_mail->text();
    QString adress_ag=ui->agent_adress->text();
   QString function_ag =ui->agent_function->text();
   QString login_ag =ui->agent_login->text();
   QString password_ag =ui->agent_pass->text();
agent a ( cin_ag,lastname_ag,  name_ag, num_ag, mail_ag   ,  adress_ag,  function_ag , login_ag , password_ag );
   bool test=a.ajouter();
   if(test)
       {

       agent a ;
       ui->tabagent->setModel(a.afficher());
           QMessageBox::information(nullptr, QObject::tr("OK"),
                       QObject::tr("Modification effectuée.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);
       }
       else
       {
       agent a ;
       ui->tabagent->setModel(a.afficher());
           QMessageBox::critical(nullptr, QObject::tr("Failed"),
                       QObject::tr("Modification non effectuée.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);
       }


}



void MainWindow::on_pb_add_2_clicked()
{
    // subscriptions Sub;
     int num_sub=ui->le_num_3->text().toInt();
     QString type_sub=ui->le_type_2->text();
     QString durat_sub=ui->le_durt_2->text();
     float price_sub=ui->le_price_2->text().toFloat();
     QString s_date=ui->le_sdate_2->text();
     QString e_date=ui->le_edate_2->text();
     int idBuy= ui->comboBox_4->currentText().toInt();

     subscriptions Sub(num_sub,type_sub,durat_sub,price_sub,idBuy,s_date,e_date);
     bool tester=Sub.add();
     //verif:
      QMessageBox msgBox;
     if(tester)
     {
         QMessageBox::information(nullptr, QObject::tr("OK"),
                     QObject::tr("successfully added.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);
         ui->tab_subscriptions_2->setModel(Sub.read());
         ui->comboBox_5->setModel(Sub.read_id());
         ui->comboBox_4->setModel(Sub.read_buyer());
         //hist
         Sub.historique("A subscription is added : ",ui->le_num_3->text(),ui->le_type_2->text(),ui->le_durt_2->text(),ui->le_price_2->text(),ui->comboBox_4->currentText(),ui->le_sdate_2->text(),ui->le_edate_2->text());
}
     }

void MainWindow::on_pushButton_20_clicked()
{
   ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_pd_update_2_clicked()
{
    int num_sub=ui->le_num_modif_2->text().toInt();
    QString type_sub=ui->le_type_modif_2->text();
    QString durat_sub=ui->le_duration_modif_2->text();
    float price_sub=ui->le_price_modif_2->text().toFloat();
    int idBuy=ui->le_idBuy_modif_2->text().toInt();
    QString s_date=ui->le_sdate_modif_2->text();
    QString e_date=ui->le_edate_modif_2->text();

             subscriptions Sub(num_sub,type_sub,durat_sub,price_sub,idBuy,s_date,e_date);
             bool test2=Sub.update(Sub.getnum());
             //verif:
              QMessageBox msgBox;
             if(test2)
             {
                 msgBox.setText("Update successfully.");
                 ui->tab_subscriptions_2->setModel(Sub.read());
                 ui->comboBox_5->setModel(Sub.read_id());
                 Sub.historique("A subscription is updated : ",ui->le_num_modif_2->text(),ui->le_type_modif_2->text(),ui->le_duration_modif_2->text(),ui->le_price_modif_2->text(),ui->le_idBuy_modif_2->text(),ui->le_sdate_modif_2->text(),ui->le_edate_modif_2->text());
             }
             else
             {
                 msgBox.setText("Error ; can't update.");
             Sub.historique2("Failed to update a subscription");
             }
             msgBox.exec();
}

void MainWindow::on_comboBox_5_currentIndexChanged(const QString &arg1)
{

}

void MainWindow::on_comboBox_5_currentIndexChanged(int index)
{

    index=ui->comboBox_5->currentText().toInt();
     QSqlQuery query;
    query.prepare("select * from subscriptions where num_sub=:id");
    query.bindValue(":id",index);
    if(query.exec())
    {
        while(query.next())
       {
       ui->le_num_modif_2->setText(query.value(0).toString());
       ui->le_type_modif_2->setText(query.value(1).toString());
       ui->le_duration_modif_2->setText(query.value(2).toString());
       ui->le_price_modif_2->setText(query.value(3).toString());
       ui->le_idBuy_modif_2->setText(query.value(4).toString());
       ui->le_sdate_modif_2->setText(query.value(5).toString());
       ui->le_edate_modif_2->setText(query.value(6).toString());
       }
    }
}

void MainWindow::on_pb_delete_2_clicked()
{
    subscriptions Sub1;
    Sub1.setnum(ui->comboBox_5->currentText().toInt());
    bool test=Sub1.deleteS(Sub1.getnum());
    //verif:
     QMessageBox msgBox;
    if(test)
    {
        msgBox.setText("Successfully deleted.");
        ui->tab_subscriptions_2->setModel(Sub1.read());
        ui->comboBox_5->setModel(Sub1.read_id());
        //hist
        QFile file("Historique.txt");
        if (file.open(QIODevice::Append | QIODevice::Text))
        {
            QTextStream ecriture(&file);
            ecriture << "Subscription number "<< Sub1.getnum() << " is deleted" << endl;
            file.close();
        }
    }
    else
       {

        msgBox.setText("Failed to delete.");
    Sub1.historique2("Failed to delete a subscription");
    }
    msgBox.exec();
}



void MainWindow::on_numtosearch_2_textChanged(const QString &arg1)
{
    subscriptions Sub1;
    Sub1.cleartable(ui->tab_subscriptions_2);
    int num_sub=ui->numtosearch_2->text().toInt();
    Sub1.findNum(ui->tab_subscriptions_2, num_sub);
    QFile file("Historique.txt");
    if (file.open(QIODevice::Append | QIODevice::Text))
    {
        QTextStream ecriture(&file);
        ecriture << "Search for subscription number "<< num_sub << endl;
        file.close();
    }

}

void MainWindow::on_typetosearch_2_textChanged(const QString &arg1)
{

    subscriptions Sub1;
    Sub1.cleartable(ui->tab_subscriptions_2);
    QString type_sub=ui->typetosearch_2->text();
    Sub1.findType(ui->tab_subscriptions_2, type_sub);
    QFile file("Historique.txt");
    if (file.open(QIODevice::Append | QIODevice::Text))
    {
        QTextStream ecriture(&file);
        ecriture << "Search for subscription with type : "<< type_sub << endl;
        file.close();
    }
}

void MainWindow::on_startdatetosearch_2_textChanged(const QString &arg1)
{

    subscriptions Sub1;
    Sub1.cleartable(ui->tab_subscriptions_2);
    QString s_date_sub=ui->startdatetosearch_2->text();
    Sub1.findStartDate(ui->tab_subscriptions_2, s_date_sub);
    QFile file("Historique.txt");
    if (file.open(QIODevice::Append | QIODevice::Text))
    {
        QTextStream ecriture(&file);
        ecriture << "Search for subscription with start date "<< s_date_sub << endl;
        file.close();
    }
}

void MainWindow::on_sortById_2_clicked()
{
    subscriptions Sub1;
    bool test=Sub1.sort_id();
    //verif:
     QMessageBox msgBox;
    if(test)
    {
        msgBox.setText("Successfully sorted.");
        ui->tab_subscriptions_2->setModel(Sub1.sort_id());
        Sub1.historique2("List of subscriptions is sorted by ID");
    }
    else
     {
        msgBox.setText("Failed to sort the list of subscriptions.");
        Sub1.historique2("Failed to sort the list of subscriptions");
    }
    msgBox.exec();
}

void MainWindow::on_sortByType_2_clicked()
{
    subscriptions Sub1;
    bool test=Sub1.sort_type();
    //verif:
     QMessageBox msgBox;
    if(test)
    {
        msgBox.setText("Successfully sorted.");
        ui->tab_subscriptions_2->setModel(Sub1.sort_type());
        Sub1.historique2("List of subscriptions is sorted by type");
    }
    else
    {
        msgBox.setText("Failed to sort the list of subscriptions.");
        Sub1.historique2("Failed to sort the list of subscriptions");
    }
    msgBox.exec();
}

void MainWindow::on_sortByPrice_2_clicked()
{
    subscriptions Sub1;
    bool test=Sub1.sort_price();
    //verif:
     QMessageBox msgBox;
    if(test)
    {
        msgBox.setText("Successfully sorted.");
        ui->tab_subscriptions_2->setModel(Sub1.sort_price());
        Sub1.historique2("List of subscriptions is sorted by price");
    }
    else
    {
        msgBox.setText("Failed to sort the list of subscriptions.");
        Sub1.historique2("Failed to sort the list of subscriptions");
    }
    msgBox.exec();
}

void MainWindow::on_pb_read_2_clicked()
{
    subscriptions Sub1;
    ui->tab_subscriptions_2->setModel(Sub1.read());
    Sub1.historique2("List of subscriptions is displayed" );
}

void MainWindow::on_tabWidget_3_currentChanged(int index)
{
    subscriptions Sub1;
                       // Background :
                      QLinearGradient gradient(0, 0, 0, 400);
                      gradient.setColorAt(0, QColor(90, 90, 90));
                      gradient.setColorAt(0.38, QColor(105, 105, 105));
                      gradient.setColorAt(1, QColor(70, 70, 70));
                      ui->plot_2->setBackground(QBrush(gradient));

                       // Bars:
                      QCPBars *amande = new QCPBars(ui->plot_2->xAxis, ui->plot_2->yAxis);
                      amande->setAntialiased(false);
                      amande->setStackingGap(1);

                       // Couleurs:
                      amande->setName("Repartition des types selon prix ");
                      amande->setPen(QPen(QColor(0, 168, 140).lighter(130)));
                      amande->setBrush(QColor(0, 168, 140));

                       // Axe des abscisses:
                      QVector<double> ticks;
                      QVector<QString> labels;
                      Sub1.statistique(&ticks,&labels);
                      QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
                      textTicker->addTicks(ticks, labels);
                      ui->plot_2->xAxis->setTicker(textTicker);
                      ui->plot_2->xAxis->setTickLabelRotation(60);
                      ui->plot_2->xAxis->setSubTicks(false);
                      ui->plot_2->xAxis->setTickLength(0, 4);
                      ui->plot_2->xAxis->setRange(0, 8);
                      ui->plot_2->xAxis->setBasePen(QPen(Qt::white));
                      ui->plot_2->xAxis->setTickPen(QPen(Qt::white));
                      ui->plot_2->xAxis->grid()->setVisible(true);
                      ui->plot_2->xAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));
                      ui->plot_2->xAxis->setTickLabelColor(Qt::white);
                      ui->plot_2->xAxis->setLabelColor(Qt::white);
                      // Axe des ordonnées:
                      ui->plot_2->yAxis->setRange(0,500);
                      ui->plot_2->yAxis->setPadding(5);
                      ui->plot_2->yAxis->setLabel("Statistiques");
                      ui->plot_2->yAxis->setBasePen(QPen(Qt::white));
                      ui->plot_2->yAxis->setTickPen(QPen(Qt::white));
                      ui->plot_2->yAxis->setSubTickPen(QPen(Qt::white));
                      ui->plot_2->yAxis->grid()->setSubGridVisible(true);
                      ui->plot_2->yAxis->setTickLabelColor(Qt::white);
                      ui->plot_2->yAxis->setLabelColor(Qt::white);
                      ui->plot_2->yAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::SolidLine));
                      ui->plot_2->yAxis->grid()->setSubGridPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));

                      // Ajout des données:
                      QVector<double> PlaceData;
                      QSqlQuery q1("select SUM(price_sub) from SUBSCRIPTIONS where regexp_like(type_sub,'air conditioning');");
                      while (q1.next()) {
                                    int  n = q1.value(0).toFloat();
                                    PlaceData<< n;
                                    QSqlQuery q2("select SUM(price_sub) from SUBSCRIPTIONS where regexp_like(type_sub,'electricity');");
                                    while (q2.next()) {
                                                  int  n = q2.value(0).toFloat();
                                                  PlaceData<< n;
                                                  QSqlQuery q3("select SUM(price_sub) from SUBSCRIPTIONS where regexp_like(type_sub,'plumbing');");
                                                  while (q3.next()) {
                                                                int  n = q3.value(0).toFloat();
                                                                PlaceData<< n;
                                                                  }
                                                    }
                                      }
                      amande->setData(ticks, PlaceData);
                      // Legende:
                      ui->plot_2->legend->setVisible(true);
                      ui->plot_2->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignHCenter);
                      ui->plot_2->legend->setBrush(QColor(255, 255, 255, 100));
                      ui->plot_2->legend->setBorderPen(Qt::NoPen);
                      QFont legendFont = font();
                      legendFont.setPointSize(10);
                      ui->plot_2->legend->setFont(legendFont);
                       // Interact:
                      ui->plot_2->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);

                      Sub1.historique2("Statistics is updated");
}

void MainWindow::on_pb_history_2_clicked()
{
    subscriptions Sub1;
    QFile file("Historique.txt");
    Sub1.historique2("Show Text History");
   if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        QMessageBox::information(0,"info",file.errorString());
            QTextStream lecture(&file);
            ui->textBrowser_2->setText(lecture.readAll());
            QMessageBox::information(nullptr, QObject::tr("Text History is open"),
                        QObject::tr("Text History is successfully displayed.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
            file.close();
}

void MainWindow::on_pbExport_2_clicked()
{
    subscriptions Sub;
    QString fileName = QFileDialog::getSaveFileName(this, tr("Excel file"), qApp->applicationDirPath (),
                                                            tr("Excel Files (*.xls)"));
            if (fileName.isEmpty())
                return ;
        QProgressBar progressBar;
            exportExcel  obj(fileName, "tabsub", ui->tab_subscriptions_2);

            // ordre des colonnes et la colonne à exporter
            obj.addField(0, "num", "char(20)") ;
            obj.addField(1, "type", "char(20)");
            obj.addField(2, "duration", "char(20)");
            obj.addField(3, "price", "char(20)");
            obj.addField(4, "idbuyer", "char(20)");
            obj.addField(5, "startdate", "char(20)");
            obj.addField(6, "enddate", "char(20)");

            int retVal = obj.export2Excel();
            if( retVal > 0)
            {
                QMessageBox::information(this, tr("Done"),
                                         QString( tr("%1 enregistrements exportés!")).arg(retVal)
                                         );
                Sub.historique2("Export to Excel file");
            }
}

void MainWindow::on_pushButton_19_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_add_2_clicked()
{
    int sub_num_par=ui->sub_num_par_2->text().toInt();
    int id_par=ui->id_par_2->text().toInt();

    QString name_par=ui->name_par_2->text();
    QString type_par=ui->type_par_2->text();
    QString duration_par=ui->duration_par_2->text();
    QString contract_language_par=ui->contract_language_par_2->text();


 PARTNERS p(id_par,sub_num_par,name_par,type_par,duration_par,contract_language_par);
  bool test =p.add();
  if(test)
  {ui->tab_produit_3->setModel(p.read());
       ui->idbox_2->setModel(p.read_id());
      QMessageBox::information(nullptr, QObject::tr("added"),
                  QObject::tr("successful.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("error"),
                  QObject::tr("add failed.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
}



void MainWindow::on_pushButton_42_clicked()
{
    //int id=ui->id_up->text().toInt();
    int id=ui->idbox_2->currentText().toInt();

        QSqlQuery qry;
PARTNERS p;
    qry.prepare("SELECT * FROM PARTNERS WHERE ID_PAR=:id");
    qry.bindValue(":id",id);
    if(qry.exec())
    {ui->tab_produit_3->setModel(p.read());
        while(qry.next())
              {
            ui->id_up_2->setText(qry.value(0).toString());
            ui->name_up_2->setText(qry.value(1).toString());
            ui->type_up_2->setText(qry.value(2).toString());
            ui->duration_up_2->setText(qry.value(3).toString());
            ui->conlang_up_2->setText(qry.value(4).toString());
            ui->subnum_up_2->setText(qry.value(5).toString());


        }
    }
}

void MainWindow::on_update_3_clicked()
{PARTNERS p;
    int id_par=ui->id_up_2->text().toInt();
    QString name_par=ui->name_up_2->text();
    QString duration_par=ui->duration_up_2->text();
    int numsub=ui->subnum_up_2->text().toInt();
    QString contract=ui->conlang_up_2->text();
    QString type_par=ui->type_up_2->text();

             PARTNERS Sub(id_par,numsub,name_par,type_par,duration_par,contract);//creer objet/instance et passer par contructr paramétré
         //pour verifier ajout:   (shih fl fichier .cpp hedha ?)
             bool test2=Sub.update(Sub.getid());// ou read-id ?   w getnum wala toul num?
             //verif:
              QMessageBox msgBox;
             if(test2)
             {ui->tab_produit_3->setModel(p.read());
                 msgBox.setText("Update successfully.");
                 //ui->tab_produit_3->setModel(Sub.read());//refresh de mon tab (afficher une autre fois avec l'ajout effectué)
                // ui->comboBox->setModel(Sub.read_id());
             }
             else
                 msgBox.setText("Error ; can't update.");
             msgBox.exec();
}

void MainWindow::on_supprimer_2_clicked()
{
    PARTNERS p;
   int id=ui->idbox_2->currentText().toInt();
    bool  test=p.dell(id);
    if(test)
    {ui->tab_produit_3->setModel(p.read());
         ui->idbox_2->setModel(p.read_id());
        QMessageBox::information(nullptr, QObject::tr("done"),
                    QObject::tr("delete successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

 }
    else
        QMessageBox::critical(nullptr, QObject::tr("ERROR"),
                    QObject::tr("delete failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);











}

void MainWindow::on_sort_par_clicked()
{
    ui->tab_produit_3-> setModel(p.sort_name_ag());
            QMessageBox::information(nullptr, QObject::tr("Ok"),
                        QObject::tr("tri effectu.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_sort_par_2_clicked()
{
    ui->tab_produit_3-> setModel(p.sort_id());
            QMessageBox::information(nullptr, QObject::tr("Ok"),
                        QObject::tr("tri effectu.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_sort_par_3_clicked()
{
    ui->tab_produit_3-> setModel(p.sort_lg());
            QMessageBox::information(nullptr, QObject::tr("Ok"),
                        QObject::tr("tri effectu.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_chercher_4_textChanged(const QString &arg1)
{
    p.cleartable(ui->tab_produit_3);
        int name=ui->chercher_4->text().toInt();
        p.rechercher_id(ui->tab_produit_3, name);
}

void MainWindow::on_chercher_5_textChanged(const QString &arg1)
{
    p.cleartable(ui->tab_produit_3);
        QString name=ui->chercher_5->text();
        p.rechercher_name(ui->tab_produit_3, name);
}

void MainWindow::on_tri_stock_7_clicked()
{
    int ID_PAR=ui->idbox_2->currentText().toInt();

    QString dir = QFileDialog::getExistingDirectory(this, tr("Open Directory"),"/home/Desktop",QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    qDebug()<<dir;
    QPdfWriter pdf(dir+"/PARTNERS.pdf");
    QPainter painter(&pdf);
    int i = 4000;

                           painter.setPen(Qt::black);
                         painter.setFont(QFont("Roboto", 30));
                         painter.drawPixmap(QRect(100,400,2000,2000),QPixmap("C:/Users/GHOFRANE/Desktop/Sellers/logo.png"));
                         painter.drawText(3000,1500,"Contract");


                         painter.setPen(Qt::darkBlue);
                                             painter.setFont(QFont("Roboto", 13));
                                             painter.drawText(300,2300,"Between The Undersigned:");

                                                                                      QSqlQuery query;
                                                                                                          query.prepare("<SELECT CAST( GETDATE() AS Date ) ");
                                                                                                          time_t tt;
                                                                                                          struct tm* ti;
                                                                                                          time(&tt);
                                                                                                          ti=localtime(&tt);
                                                                                                          asctime(ti);
                                                                                                          painter.drawText(500,300, asctime(ti));
                                                                                                          query.prepare("select * from PARTNERS where ID_PAR=:ID_PAR");
                                                                                                          query.bindValue(":ID_PAR",ID_PAR);
                                                                                                          query.exec();
                                                                                                          while (query.next())
                                                                                                          {
                                                                                                              painter.setPen(Qt::black);
                                                                                                              painter.setFont(QFont("Roboto", 11));

                                                                                                              painter.drawText(3000,2300,query.value(1).toString());

                                                                                                          }painter.drawText(3700,2300,"and BYOND TRUST for the duration of ");
                                                                                                          query.prepare("select * from PARTNERS where ID_PAR=:ID_PAR");
                                                                                                          query.bindValue(":ID_PAR",ID_PAR);
                                                                                                          query.exec();
                                                                                                          while (query.next())
                                                                                                          {
                                                                                                              painter.setPen(Qt::black);
                                                                                                              painter.setFont(QFont("Roboto", 11));

                                                                                                              painter.drawText(6900,2300,query.value(2).toString());

                                                                                                          }
                                                                                                          painter.drawText(300,3400, "EMPLOYEE REPRESENTATIONS AND WARRANTIES:");
                                                                                                          painter.drawText(300,3400, "EMPLOYEE REPRESENTATIONS AND WARRANTIES:");
                                                                                                          painter.drawText(300,3400, "EMPLOYEE REPRESENTATIONS AND WARRANTIES:");

                                                                                                          painter.setPen(Qt::black);
                                                                                                                              painter.setFont(QFont("Roboto", 13));
                                                                                                                              painter.drawText(300,3700,"There is no employment contract or any other contractual obligation to which ");
                                                                                                                              painter.drawText(300,4000,"the Employee is subject, which prevents the Employee from entering into this ");
painter.drawText(300,4300, "Contract or from performing fully the Employee's duties under this Contract.");

painter.drawText(300,5000, "SEVERABILITY:");
painter.drawText(300,5000, "SEVERABILITY:");
painter.drawText(300,5000, "SEVERABILITY:");

painter.drawText(300,5300, "If a court finds any provision of this Employment Contract invalid or unenforceable,");
painter.drawText(300,5600, "the remainder of this Employment Contract shall be interpreted as best to affect ");
painter.drawText(300,5900, "the intent of the parties. ");

painter.drawText(300,6600, "ENTIRE AGREEMENT:");
painter.drawText(300,6600, "ENTIRE AGREEMENT:");
painter.drawText(300,6600, "ENTIRE AGREEMENT:");


painter.drawText(300,6900, "This Employment Contract expresses the complete understanding of the parties with ");
painter.drawText(300,7200, "respect to the subject matter and supersedes all prior proposals, agreements,");
painter.drawText(300,7500, "representations, and understandings. This Employment Contract may not be amended");
painter.drawText(300,7800, " except in a writing signed by both parties.");

painter.drawText(300,8500, "EXPENSES:");
painter.drawText(300,8500, "EXPENSES:");
painter.drawText(300,8500, "EXPENSES:");






painter.drawText(300,9200, "The Employee shall not be entitled to reimbursement for any expenses except those  ");
painter.drawText(300,9500, "that have been previously approved in writing by the Company. Should the Company");
painter.drawText(300,9800, "require travel by the Employee, the Company shall reimburse the Employee for ");
painter.drawText(300,10100, "such travel expenses, along with reasonable lodging and meal expenses upon");
painter.drawText(300,10300, "presentation of receipts of such expenses.");






                                                                                                          painter.setPen(Qt::black);
                                                                                                                              painter.setFont(QFont("Roboto", 15));
                                                                                                                              painter.drawText(300,12000,"Partner's Signature");

                                                                                                                              painter.setPen(Qt::black);
                                                                                                                              painter.setFont(QFont("Roboto", 15));
                                                                                                                              painter.drawText(6800,12000,"Adminstration's Signature");


    int reponse = QMessageBox::question(this, "Génerer PDF", "PDF Enregistré.\nVous Voulez Affichez Le PDF ?", QMessageBox::Yes |  QMessageBox::No);
    if (reponse == QMessageBox::Yes)
    {
        QDesktopServices::openUrl(QUrl::fromLocalFile(dir+"/PARTNERS.pdf"));
        painter.end();
    }
    else
    {
        painter.end();
    }
}



void MainWindow::on_tri_stock_8_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Excel file"), qApp->applicationDirPath (),
                                                               tr("Excel Files (*.xls)"));
               if (fileName.isEmpty())
                   return;

               exportExcel obj(fileName, "mydata", ui->tab_produit);

               obj.addField(0, "id", "char(20)");
               obj.addField(1, "type", "char(20)");
               obj.addField(2, "name", "char(20)");
               obj.addField(3, "duration", "char(20)");
               obj.addField(4, "language", "char(20)");
               obj.addField(5, "subnum", "char(20)");


               int retVal = obj.export2Excel();

               if( retVal > 0)
               {
                   QMessageBox::information(this, tr("Done"),
                                            QString(tr("exported!")).arg(retVal)
                                            );
               }
}

void MainWindow::on_ig_2_clicked()
{
    QDesktopServices::openUrl(QUrl("https://www.instagram.com/armiisnotred/", QUrl::TolerantMode));
}

void MainWindow::on_fb_2_clicked()
{
     QDesktopServices::openUrl(QUrl("https://www.facebook.com", QUrl::TolerantMode));
}
void MainWindow::on_linkedin_2_clicked()
{
    QDesktopServices::openUrl(QUrl("https://www.linkedin.com", QUrl::TolerantMode));
}

void MainWindow::on_tri_stock_9_clicked()
{
    int ID_PAR=ui->idbox_2->currentText().toInt();

    QString dir = QFileDialog::getExistingDirectory(this, tr("Open Directory"),"/home/Desktop",QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    qDebug()<<dir;
    QPdfWriter pdf(dir+"/PARTNERS.pdf");
    QPainter painter(&pdf);
    int i = 4000;

                           painter.setPen(Qt::black);
                         painter.setFont(QFont("Roboto", 30));
                         painter.drawPixmap(QRect(100,400,2000,2000),QPixmap("C:/Users/GHOFRANE/Desktop/Sellers/logo.png"));
                         painter.drawText(3000,1500,"Contrat");


                         painter.setPen(Qt::darkBlue);
                                             painter.setFont(QFont("Roboto", 13));
                                             painter.drawText(300,2300,"Entre les soussignés :");

                                                                                      QSqlQuery query;
                                                                                                          query.prepare("<SELECT CAST( GETDATE() AS Date ) ");
                                                                                                          time_t tt;
                                                                                                          struct tm* ti;
                                                                                                          time(&tt);
                                                                                                          ti=localtime(&tt);
                                                                                                          asctime(ti);
                                                                                                          painter.drawText(500,300, asctime(ti));
                                                                                                          query.prepare("select * from PARTNERS where ID_PAR=:ID_PAR");
                                                                                                          query.bindValue(":ID_PAR",ID_PAR);
                                                                                                          query.exec();
                                                                                                          while (query.next())
                                                                                                          {
                                                                                                              painter.setPen(Qt::black);
                                                                                                              painter.setFont(QFont("Roboto", 11));

                                                                                                              painter.drawText(3000,2300,query.value(1).toString());

                                                                                                          }painter.drawText(3700,2300,"et BYOND TRUST pour la durée de");
                                                                                                          query.prepare("select * from PARTNERS where ID_PAR=:ID_PAR");
                                                                                                          query.bindValue(":ID_PAR",ID_PAR);
                                                                                                          query.exec();
                                                                                                          while (query.next())
                                                                                                          {
                                                                                                              painter.setPen(Qt::black);
                                                                                                              painter.setFont(QFont("Roboto", 11));

                                                                                                              painter.drawText(6900,2300,query.value(2).toString());

                                                                                                          }
                                                                                                          painter.drawText(300,3400, "DÉCLARATIONS ET GARANTIES DES EMPLOYÉS :");
                                                                                                          painter.drawText(300,3400, "DÉCLARATIONS ET GARANTIES DES EMPLOYÉS :");
                                                                                                          painter.drawText(300,3400, "DÉCLARATIONS ET GARANTIES DES EMPLOYÉS :");

                                                                                                          painter.setPen(Qt::black);
                                                                                                                              painter.setFont(QFont("Roboto", 13));
                                                                                                                              painter.drawText(300,3700,"Il n’y a pas de contrat de travail ou d’autre obligation contractuelle à laquelle");
                                                                                                                              painter.drawText(300,4000,"l’Employé est sujet, ce qui empêche l’Employé d’entrer dans ce ");
painter.drawText(300,4300, "Contrat ou de l’exécution complète des obligations de l’employé en vertu du présent contrat.");

painter.drawText(300,5000, "DIVISIBILITÉ:");
painter.drawText(300,5000, "DIVISIBILITÉ:");
painter.drawText(300,5000, "DIVISIBILITÉ:");

painter.drawText(300,5300, "Si un tribunal juge une disposition du présent contrat de travail invalide ou inapplicable,");
painter.drawText(300,5600, "le reste du présent contrat de travail doit être interprété comme étant le meilleur moyen d’affecter");
painter.drawText(300,5900, "l’intention des parties. ");

painter.drawText(300,6600, "INTÉGRALITÉ DE L’ACCORD :");
painter.drawText(300,6600, "INTÉGRALITÉ DE L’ACCORD :");
painter.drawText(300,6600, "INTÉGRALITÉ DE L’ACCORD :");


painter.drawText(300,6900, "Le présent contrat de travail exprime l’entière compréhension des parties avec");
painter.drawText(300,7200, "respecte l’objet et remplace toutes les propositions, accords antérieurs,");
painter.drawText(300,7500, "représentations et compréhensions. Le présent contrat de travail ne peut être modifié");
painter.drawText(300,7800, " sauf dans un écrit signé par les deux parties.");

painter.drawText(300,8500, "DÉPENSE:");
painter.drawText(300,8500, "DÉPENSE:");
painter.drawText(300,8500, "DÉPENSE:");






painter.drawText(300,9200, "L’employé n’a pas droit au remboursement de toutes les dépenses, à l’exception de celles ");
painter.drawText(300,9500, "qui ont déjà été approuvés par écrit par la Société. L’entreprise devrait-elle");
painter.drawText(300,9800, "exiger un voyage de l’Employé, la Société remboursera à l’Employé pour ");
painter.drawText(300,10100, "ces frais de déplacement, ainsi que les frais raisonnables d’hébergement et de repas");
painter.drawText(300,10300, "la présentation des recettes de ces dépenses.");






                                                                                                          painter.setPen(Qt::black);
                                                                                                                              painter.setFont(QFont("Roboto", 15));
                                                                                                                              painter.drawText(300,12000,"Signature du partenaire");

                                                                                                                              painter.setPen(Qt::black);
                                                                                                                              painter.setFont(QFont("Roboto", 15));
                                                                                                                              painter.drawText(6500,12000,"Signature de l’administration");


    int reponse = QMessageBox::question(this, "Génerer PDF", "PDF Enregistré.\nVous Voulez Affichez Le PDF ?", QMessageBox::Yes |  QMessageBox::No);
    if (reponse == QMessageBox::Yes)
    {
        QDesktopServices::openUrl(QUrl::fromLocalFile(dir+"/PARTNERS.pdf"));
        painter.end();
    }
    else
    {
        painter.end();
    }
}

void MainWindow::on_tri_stock_10_clicked()
{
    int ID_PAR=ui->idbox_2->currentText().toInt();

    QString dir = QFileDialog::getExistingDirectory(this, tr("Open Directory"),"/home/Desktop",QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    qDebug()<<dir;
    QPdfWriter pdf(dir+"/PARTNERS.pdf");
    QPainter painter(&pdf);
    int i = 4000;

                           painter.setPen(Qt::black);
                         painter.setFont(QFont("Roboto", 30));
                         painter.drawPixmap(QRect(100,400,2000,2000),QPixmap("C:/Users/GHOFRANE/Desktop/Sellers/logo.png"));
                         painter.drawText(3000,1500,"Contrato");


                         painter.setPen(Qt::darkBlue);
                                             painter.setFont(QFont("Roboto", 13));
                                             painter.drawText(300,2300,"Entre los abajo firmantes:");

                                                                                      QSqlQuery query;
                                                                                                          query.prepare("<SELECT CAST( GETDATE() AS Date ) ");
                                                                                                          time_t tt;
                                                                                                          struct tm* ti;
                                                                                                          time(&tt);
                                                                                                          ti=localtime(&tt);
                                                                                                          asctime(ti);
                                                                                                          painter.drawText(500,300, asctime(ti));
                                                                                                          query.prepare("select * from PARTNERS where ID_PAR=:ID_PAR");
                                                                                                          query.bindValue(":ID_PAR",ID_PAR);
                                                                                                          query.exec();
                                                                                                          while (query.next())
                                                                                                          {
                                                                                                              painter.setPen(Qt::black);
                                                                                                              painter.setFont(QFont("Roboto", 11));

                                                                                                              painter.drawText(3000,2300,query.value(1).toString());

                                                                                                          }painter.drawText(3700,2300,"y BYOND TRUST por la duración de ");
                                                                                                          query.prepare("select * from PARTNERS where ID_PAR=:ID_PAR");
                                                                                                          query.bindValue(":ID_PAR",ID_PAR);
                                                                                                          query.exec();
                                                                                                          while (query.next())
                                                                                                          {
                                                                                                              painter.setPen(Qt::black);
                                                                                                              painter.setFont(QFont("Roboto", 11));

                                                                                                              painter.drawText(6900,2300,query.value(2).toString());

                                                                                                          }
                                                                                                          painter.drawText(300,3400, "REPRESENTACIONES Y GARANTÍAS DE LOS EMPLEADOS:");
                                                                                                          painter.drawText(300,3400, "REPRESENTACIONES Y GARANTÍAS DE LOS EMPLEADOS:");
                                                                                                          painter.drawText(300,3400, "REPRESENTACIONES Y GARANTÍAS DE LOS EMPLEADOS:");

                                                                                                          painter.setPen(Qt::black);
                                                                                                                              painter.setFont(QFont("Roboto", 13));
                                                                                                                              painter.drawText(300,3700,"No existe ningún contrato de trabajo ni ninguna otra obligación contractual a la que ");
                                                                                                                              painter.drawText(300,4000,"el Empleado está sujeto, lo que impide que el Empleado entre en esto ");
painter.drawText(300,4300, "Contrato o del cumplimiento completo de las obligaciones del Empleado en virtud de este Contrato.");

painter.drawText(300,5000, "DIVISIBILIDAD:");
painter.drawText(300,5000, "DIVISIBILIDAD:");
painter.drawText(300,5000, "DIVISIBILIDAD:");

painter.drawText(300,5300, "Si un tribunal determina que alguna disposición de este Contrato de Trabajo es inválida o inaplicable,");
painter.drawText(300,5600, "el resto de este Contrato de Trabajo se interpretará como el mejor para afectar ");
painter.drawText(300,5900, "la intención de las partes. ");

painter.drawText(300,6600, "ACUERDO COMPLETO:");
painter.drawText(300,6600, "ACUERDO COMPLETO:");
painter.drawText(300,6600, "ACUERDO COMPLETO:");


painter.drawText(300,6900, "Este Contrato de Trabajo expresa el entendimiento completo de las partes con ");
painter.drawText(300,7200, "respeta la materia y sustituye a todas las propuestas y acuerdos anteriores,");
painter.drawText(300,7500, "representaciones y entendimientos. Este Contrato de Trabajo no puede ser modificado");
painter.drawText(300,7800, " excepto en un escrito firmado por ambas partes.");

painter.drawText(300,8500, "EXPENSAS:");
painter.drawText(300,8500, "EXPENSAS:");
painter.drawText(300,8500, "EXPENSAS:");






painter.drawText(300,9200, "El Empleado no tendrá derecho al reembolso de ningún gasto, excepto aquellos  ");
painter.drawText(300,9500, "que hayan sido previamente aprobados por escrito por la Compañía. ¿Debería la empresa");
painter.drawText(300,9800, "Requerir viajes por parte del Empleado, la Compañía reembolsará al Empleado por ");
painter.drawText(300,10100, "tales gastos de viaje, junto con gastos razonables de alojamiento y comida en");
painter.drawText(300,10400, "presentación de recibos de dichos gastos.");






                                                                                                          painter.setPen(Qt::black);
                                                                                                                              painter.setFont(QFont("Roboto", 15));
                                                                                                                              painter.drawText(300,12000,"Firma del socio");

                                                                                                                              painter.setPen(Qt::black);
                                                                                                                              painter.setFont(QFont("Roboto", 15));
                                                                                                                              painter.drawText(6800,12000,"Firma de la administración");


    int reponse = QMessageBox::question(this, "Génerer PDF", "PDF Enregistré.\nVous Voulez Affichez Le PDF ?", QMessageBox::Yes |  QMessageBox::No);
    if (reponse == QMessageBox::Yes)
    {
        QDesktopServices::openUrl(QUrl::fromLocalFile(dir+"/PARTNERS.pdf"));
        painter.end();
    }
    else
    {
        painter.end();
    }
}

void MainWindow::on_pushButton_18_clicked()
{
     ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_pb_Add_clicked()
{
    int id_sel=ui->id_sel->text().toInt();
    QString lastname_sel=ui->lastname_sel->text();
    QString name_sel=ui->name_sel->text();
    QString adress_sel=ui->adress_sel->text();
    int num_sel=ui->num_sel->text().toInt();
    QString mail_sel=ui->mail_sel->text();
   //instancier un objet de la classe seller en utilisant
    // les informations saisies dans l'interface
   Seller S(id_sel,lastname_sel,name_sel,adress_sel,num_sel,mail_sel);
   bool test=S.ajouter();// inserer l'objet seller instancié dans la table seller
   // et recuperer la valeur de retour de query.exec()
            if(test) // Si requete executée ==> QMessageBox::information
            {
                ui->tab_seller->setModel(S.afficher());
                ui->comboBox->setModel(S.read_id());
                n.notification_ajoutab();
                QMessageBox::information(nullptr,QObject::tr("OK"),
                                       QObject::tr("data added.\n"
                                                   "click cancel to exit."),QMessageBox::Cancel);
            }
            else

            {
                ui->tab_seller->setModel(S.afficher());
                QMessageBox::critical(nullptr,QObject::tr("OK"),
                                       QObject::tr("data not added.\n"
                                                   "click cancel to exit."),QMessageBox::Cancel);
            }
}

void MainWindow::on_pb_supp_clicked()
{
    Seller S1,S2; S1.setid_sel(ui->id_supp->text().toInt());
    S2.setid_sel(ui->comboBox->currentText().toInt());
    bool test=S1.supprimer(S1.getid_sel());
    bool test2=S2.supprimer(S2.getid_sel());
    QMessageBox msgBox;

    if(test || test2)
       { msgBox.setText("successfully deleted");

        ui->tab_seller->setModel(S.afficher());
        ui->comboBox->setModel(S.read_id());
        n.notification_supprimerab();

    }
    else
        msgBox.setText("deletion failed");
    msgBox.exec();
}

void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    index=ui->comboBox->currentText().toInt();

       QSqlQuery query;

   query.prepare("select * from SELLERS where ID_SEL=:id");
   query.bindValue(":id",index);
   if(query.exec())
   {
       while(query.next())
             {
      ui->id_modif->setText(query.value(0).toString());
      ui->lastname_modif->setText(query.value(1).toString());
      ui->name_modif->setText(query.value(2).toString());
      ui->adress_modif->setText(query.value(3).toString());
      ui->num_modif->setText(query.value(4).toString());
      ui->mail_modif->setText(query.value(5).toString());
       }
   }
}

void MainWindow::on_pb_modif_clicked()
{
    int id_sel=ui->id_modif->text().toInt();
             QString lastname_sel=ui->lastname_modif->text();
              QString name_sel=ui->name_modif->text();
             QString adress_sel=ui->adress_modif->text();
                int num_sel=ui->num_modif->text().toInt();
                 QString mail_sel=ui->mail_modif->text();
 Seller S (id_sel,lastname_sel,name_sel,adress_sel,num_sel,mail_sel);
             bool test2=S.modifier(S.getid_sel());
             if(test2)
             {   ui->tab_seller->setModel(S.afficher());
                 n.notification_modifierab();
         QMessageBox::information(nullptr,QObject::tr("OK"),
                                QObject::tr("modify done successfully \n"
                                            "click cancel to exit."),QMessageBox::Cancel);

             }
     else
         {ui->tab_seller->setModel(S.afficher());
     QMessageBox::critical(nullptr,QObject::tr("NOT OK"),
                                QObject::tr("modification failed \n"
                                            "click cancel to exit."),QMessageBox::Cancel);}
}
void MainWindow::on_Sort_by_name_clicked()
{
    ui->tab_seller->setModel(S.sort_name());
        QMessageBox::information(nullptr, QObject::tr("Ok"),
                    QObject::tr("tri effectu.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_Sort_by_id_clicked()
{
    ui->tab_seller->setModel(S.sort_id());
        QMessageBox::information(nullptr, QObject::tr("Ok"),
                    QObject::tr("tri effectu.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_Sort_by_adress_clicked()
{
    ui->tab_seller->setModel(S.sort_adress());
        QMessageBox::information(nullptr, QObject::tr("Ok"),
                    QObject::tr("tri effectu.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}



void MainWindow::on_search_id_2_textChanged(const QString &arg1)
{
    S.cleartable(ui->tab_seller);
        int id_sel=ui->search_id_2->text().toInt();
       S.search_id(ui->tab_seller, id_sel);
}

void MainWindow::on_search_name_2_textChanged(const QString &arg1)
{
    S.cleartable(ui->tab_seller);
        QString name_sel=ui->search_name_2->text();
       S.search_name(ui->tab_seller, name_sel);
}

void MainWindow::on_search_adress_2_textChanged(const QString &arg1)
{
    S.cleartable(ui->tab_seller);
        QString adress_sel=ui->search_adress_2->text();
       S.search_adress(ui->tab_seller, adress_sel);
}

void MainWindow::on_todo_clicked()
{
    this->hide();
     dialog * newmain = new dialog();
     newmain->show();
}

void MainWindow::on_generer_pdf_clicked()
{
    int id_sel1=ui->comboBox_3->currentText().toInt();
    int id_buy1=ui->comboBox_6->currentText().toInt();
         QPdfWriter pdf("C:/Users/21629/Desktop/Sellers/pdf.pdf");

              QPainter painter(&pdf);


              painter.setPen(Qt::black);
              painter.setFont(QFont("Arial", 30));
              painter.drawPixmap(QRect(100,400,2000,2000),QPixmap("C:/Users/21629/Desktop/aziz/logo.png"));
              painter.drawText(3000,1500,"Contract");


              painter.setPen(Qt::darkBlue);
              painter.setFont(QFont("Arial", 13));
              painter.drawText(300,2300,"Between The Undersigned:");
              painter.setPen(Qt::darkBlue);
              painter.setFont(QFont("Arial", 13));
              painter.drawText(300,2300,"Between The Undersigned:");


              painter.setPen(Qt::black);
              painter.setFont(QFont("Arial", 13));
              painter.drawText(500,2700," **The seller is:");


              painter.setPen(Qt::darkYellow);
              painter.setFont(QFont("Arial", 11));
              painter.drawText(300,3100,"Id_sel");
              painter.drawText(300,3500,"Lastname_sel");
              painter.drawText(300,3900,"Name_sel");
              painter.drawText(300,4300,"Adress_sel");
              painter.drawText(300,4700,"Num_sel");
              painter.drawText(300,5100,"Mail_sel");
              QSqlQuery query;
              query.prepare("<SELECT CAST( GETDATE() AS Date ) ");
              time_t tt;
              struct tm* ti;
              time(&tt);
              ti=localtime(&tt);
              asctime(ti);
              painter.drawText(500,300, asctime(ti));
              query.prepare("select * from SELLERS where id_sel=:id_sel1");
              query.bindValue(":id_sel1",id_sel1);
              query.exec();
              while (query.next())
              {
                  painter.setPen(Qt::black);
                  painter.setFont(QFont("Arial", 11));
                  painter.drawText(2200,3100,query.value(0).toString());
                  painter.drawText(2200,3500,query.value(1).toString());
                  painter.drawText(2200,3900,query.value(2).toString());
                  painter.drawText(2200,4300,query.value(3).toString());
                  painter.drawText(2200,4700,query.value(4).toString());
                  painter.drawText(2200,5100,query.value(5).toString());

              }

              painter.setPen(Qt::black);
              painter.setFont(QFont("Arial", 13));
              painter.drawText(4800,2700," **The buyer is:");

              painter.setPen(Qt::darkYellow);
              painter.setFont(QFont("Arial", 11));
              painter.drawText(5000,3100,"Id_Buy");
              painter.drawText(5000,3500,"Lastname_Buy");
              painter.drawText(5000,3900,"Name_Buy");
              painter.drawText(5000,4300,"Adress_Buy");
              painter.drawText(5000,4700,"Request_Buy");
              painter.drawText(5000,5100,"Num_Buy");
              painter.drawText(5000,5500,"Mail_Buy");
              QSqlQuery query1 ;
              painter.drawText(500,300, asctime(ti));
              query1.prepare("select * from BUYERS where id_buy=:id_buy1");
              query1.bindValue(":id_buy1",id_buy1);
              query1.exec();
              while (query1.next())
              {
                  painter.setPen(Qt::black);
                  painter.setFont(QFont("Arial", 11));
                  painter.drawText(6700,3100,query1.value(0).toString());
                  painter.drawText(6700,3500,query1.value(1).toString());
                  painter.drawText(6700,3900,query1.value(2).toString());
                  painter.drawText(6700,4300,query1.value(3).toString());
                  painter.drawText(6700,4700,query1.value(4).toString());
                  painter.drawText(6700,5100,query1.value(5).toString());
                  painter.drawText(6700,5500,query1.value(6).toString());

              }

              painter.setPen(Qt::darkBlue);
              painter.setFont(QFont("Arial", 12));
              painter.drawText(300,6700,"** The seller confirms that this information corresponds to the property sold.");
              painter.drawText(300,7000,"** The buyer accepts this deed of sale.");
              painter.setPen(Qt::black);
              painter.setFont(QFont("Arial", 13));
              painter.drawText(300,7500," **Property Description:");

              painter.setPen(Qt::darkYellow);
              painter.setFont(QFont("Arial", 11));
              painter.drawText(600,7900,"Id_Prop");
              painter.drawText(600,8300,"Type_Prop");
              painter.drawText(600,8700,"Description_Prop");
              painter.drawText(600,9100,"Localisation_Lat");
              painter.drawText(600,9500,"Localisation_Lng");
              painter.drawText(600,9900,"Id_Buy");
              painter.drawText(600,10300,"Id_Sel");
              QSqlQuery query2 ;
              query2.prepare("select * from PROPERTIES where id_sel=:id_sel1");
              query2.bindValue(":id_sel1",id_sel1);
              query2.exec();
              while (query2.next())
              {
                  painter.setPen(Qt::black);
                  painter.setFont(QFont("Arial", 11));
                  painter.drawText(2800,7900,query2.value(0).toString());
                  painter.drawText(2800,8300,query2.value(1).toString());
                  painter.drawText(2800,8700,query2.value(2).toString());
                  painter.drawText(2800,9100,query2.value(3).toString());
                  painter.drawText(2800,9500,query2.value(4).toString());
                  painter.drawText(2800,9900,query2.value(5).toString());
                  painter.drawText(2800,10300,query2.value(6).toString());

              }

              painter.setPen(Qt::black);
              painter.setFont(QFont("Arial", 15));
              painter.drawText(300,13000,"Seller's Signature");

              painter.setPen(Qt::black);
              painter.setFont(QFont("Arial", 15));
              painter.drawText(7000,13000,"Buyer's Signature");


              int reponse = QMessageBox::question(this, "PDF Generated", "Show the PDF?", QMessageBox::Yes |  QMessageBox::No);
              if (reponse == QMessageBox::Yes)
              {
                  QDesktopServices::openUrl(QUrl::fromLocalFile("C:/Users/21629/Desktop/Sellers/pdf.pdf"));

                  painter.end();
              }
              if (reponse == QMessageBox::No)
              {
                  painter.end();
              }
          }


void MainWindow::on_pushButton_database_insert_clicked()
{
    Property P(ui->lineEdit_Id_prop->text(),ui->lineEdit_Type_prop->text(),ui->lineEdit_longitude_prop->text(),ui->lineEdit_latitude_prop->text(),ui->lineEdit_price_pro->text(),ui->comboBox_8->currentText().toInt(),ui->comboBox_9->currentText().toInt(),ui->lineEdit_2->text(),ui->plainTextEdit_2->toPlainText(),ui->lineEdit_3->text()) ;

    qDebug()<<"hello" ;
    if(P.addProperty())
    {
            QMessageBox::information(this,"inserted","house inserted Successfully");
            ui->tableView_2_prop->setModel(P.read());
            ui->comboBox_7->setModel(P.read());
            ui->comboBox_8->setModel(P.read_buyer());
            ui->comboBox_9->setModel(P.read_seller());
            ui->comboBox_10->setModel(P.read());
    }
            else {
           QMessageBox::information(this,"not inserted","house not inserted Successfully");
    }
}

void MainWindow::on_pushButton_21_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}

void MainWindow::on_pushButton_29_clicked()
{
    QString home = "Videos";
       QString path = QFileDialog::getOpenFileName(this, "Select Imagae", home + "/Videos",
                                                   "Videos(*.mp4);;All Files(*.*)");
       QFileInfo relativePath(path);
             QString localisation=relativePath.filePath();
             qDebug()<<"localisation est :"<<localisation ;
             ui->lineEdit_2->setText(localisation);
}

void MainWindow::on_pushButton_30_clicked()
{
    Property p ;
    QString home = "Image";
       QString path = QFileDialog::getOpenFileName(this, "Select Image", home + "/Images",
                                                   "Images(*.jpg);;All Files(*.*)");
       QFileInfo relativePath(path);
             QString localisation=relativePath.filePath();
             qDebug()<<"localisation est :"<<localisation ;
             ui->lineEdit_3->setText(localisation);
}

void MainWindow::on_update_prop_clicked()
{
     Property P(ui->lineEdit_Id_prop->text(),ui->lineEdit_Type_prop->text(),ui->lineEdit_longitude_prop->text(),ui->lineEdit_latitude_prop->text(),ui->lineEdit_price_pro->text(),ui->comboBox_8->currentText().toInt(),ui->comboBox_9->currentText().toInt(),ui->lineEdit_2->text(),ui->plainTextEdit_2->toPlainText(),ui->lineEdit_3->text()) ;
    if(P.update())
    {
            QMessageBox::information(this,"updated","house updated Successfully");

            ui->tableView_2_prop->setModel(P.read());
            ui->comboBox_7->setModel(P.read());
            ui->comboBox_8->setModel(P.read_buyer());
            ui->comboBox_9->setModel(P.read_seller());
            ui->comboBox_10->setModel(P.read());

    }
            else {
           QMessageBox::information(this,"not updated","house not updated Successfully");

           ui->tableView_2_prop->setModel(P.read());
           ui->comboBox_7->setModel(P.read());
           ui->comboBox_8->setModel(P.read_buyer());
           ui->comboBox_9->setModel(P.read_seller());
           ui->comboBox_10->setModel(P.read());
    }
}

void MainWindow::on_comboBox_7_currentIndexChanged(int index)
{
    int id=ui->comboBox_7->currentText().toInt();
    qDebug() <<id ;
    QSqlQuery query;
    query.prepare("SELECT * from PROPERTIES WHERE ID_PROP=:id");
    query.bindValue(":id",id);
    if(query.exec())
    {
       while(query.next())
       {
           qDebug() <<"oyyyyyy" ;
           ui->lineEdit_Id_prop->setText(query.value(0).toString());
            ui->lineEdit_Type_prop->setText(query.value(1).toString());
           ui->lineEdit_price_pro->setText(query.value(4).toString());
          ui->lineEdit_longitude_prop->setText(query.value(3).toString());
           ui->lineEdit_latitude_prop->setText(query.value(2).toString());

       }
    }
}

void MainWindow::on_pushButton_delete_prop_clicked()
{
    Property P ;
    int id=ui->comboBox_10->currentText().toInt();

 if( P.delete_Property(id)) {

        ui->tableView_2_prop->setModel(P.read());
        ui->comboBox_10->setModel(P.read());
               QMessageBox::information(nullptr,QObject::tr("OK"),
                                      QObject::tr("delete done.\n"
                                                  "clic cancel to exit."),QMessageBox::Cancel);
    }
    else
        {ui->tableView_2_prop->setModel(P.read());
      ui->comboBox_10->setModel(P.read());
    QMessageBox::critical(nullptr,QObject::tr("NOT OK"),
                               QObject::tr("delete not done .\n"
                                           "clic cancel to exit."),QMessageBox::Cancel);}
}

void MainWindow::on_tableView_2_prop_clicked(const QModelIndex &index)
{
    if (index.isValid() && index.column()==7) {
            QString cellText = index.data().toString();
            qDebug() <<"cell number"<<index.column() ;

            map m ;
            QQmlApplicationEngine engine;
            engine.load(QUrl(QStringLiteral("qrc:/map.qml")));
            QObject *window = engine.rootObjects().first();
            QVariant lat= ui->tableView_2_prop->model()->data(ui->tableView_2_prop->model()->index(index.row(),2)).toString();
            QVariant lng= ui->tableView_2_prop->model()->data(ui->tableView_2_prop->model()->index(index.row(),3)).toString();;
            qDebug()<<"lat type:"<<lat ;
            QVariant returnedValue ;
            QMetaObject::invokeMethod(window, "addMarker",
                    Q_RETURN_ARG(QVariant, returnedValue),
                    Q_ARG(QVariant, lat),
                    Q_ARG(QVariant, lng));



            qDebug() << "Property lng:" << QQmlProperty::read(window, "lng").toInt();
            QQmlProperty::write(window, "lng", lng);

            qDebug() << "Property lng:" << window->property("lng").toInt();
            window->setProperty("lng", lng);
            ///////////////////////////
            qDebug() << "Property lat:" << QQmlProperty::read(window, "lat").toInt();
            QQmlProperty::write(window, "lat",lat);

            qDebug() << "Property lat:" << window->property("lat").toInt();
            window->setProperty("lat", lat);



            m.exec();

        }
     if (index.isValid() && index.column()==8) {
    QString localisation=ui->tableView_2_prop->model()->data(ui->tableView_2_prop->model()->index(index.row(),8)).toString();
        // player=new QMediaPlayer(this);
        // QMainWindow *window1 = new QMainWindow();
      //   QVideoWidget *vw = new QVideoWidget ;
      //   video_player.setVideoOutput(vw);
       //  video_player.setMedia(QUrl::fromLocalFile(localisation));
        // window1->setCentralWidget(vw);
        // vw->setGeometry(100,100,500,500);
 QDesktopServices::openUrl(QUrl::fromLocalFile(localisation));
        /* QPushButton *close_button = new QPushButton(window1);
         close_button->setText(tr("something"));
         close_button->move(0, 0);
         close_button->show();*/


        // window1->show();
      //   vw->show();
       //  video_player.play();
     }
     if (index.isValid() && index.column()==9) {
    QString description=ui->tableView_2_prop->model()->data(ui->tableView_2_prop->model()->index(index.row(),9)).toString();
    QString localisation_image=ui->tableView_2_prop->model()->data(ui->tableView_2_prop->model()->index(index.row(),10)).toString();

    QPdfWriter pdf("C:/Users/21629/Desktop/property/pdf_property.pdf");
    QPainter painter(&pdf);
    painter.setFont(QFont("Arial Bold", 15));
    painter.setPen(Qt::blue);
    painter.drawText(200,200,description);
    painter.drawPixmap(QRect(0,2600,5000,5000),QPixmap(localisation_image));
    QDesktopServices::openUrl(QUrl::fromLocalFile("C:/Users/21629/Desktop/property/pdf_property.pdf"));
     }
     if (index.isValid() && index.column()==10) {
   QString localisation=ui->tableView_2_prop->model()->data(ui->tableView_2_prop->model()->index(index.row(),10)).toString();
    QDesktopServices::openUrl(QUrl::fromLocalFile(localisation));
     }
}

void MainWindow::on_pushButton_31_clicked()
{
    Property p ;
    ui->tableView_2_prop->setModel(p.find_id(ui->lineEdit_find_id_prop->text().toInt()));
}

void MainWindow::on_pushButton_32_clicked()
{
    Property p ;
    ui->tableView_2_prop->setModel(p.find_type(ui->lineEdit_find_type_prop->text()));
}

void MainWindow::on_pushButton_33_clicked()
{
    Property p ;
    ui->tableView_2_prop->setModel(p.find_price(ui->lineEdit_find_price_prop->text().toInt()));
}

void MainWindow::on_pushButton_34_clicked()
{
    Property p;
    ui->tableView_2_prop->setModel(p.sort_ID());
}

void MainWindow::on_pushButton_35_clicked()
{
    Property p;
    ui->tableView_2_prop->setModel(p.sort_type());
}

void MainWindow::on_pushButton_36_clicked()
{
    Property p;
    ui->tableView_2_prop->setSortingEnabled(true);
    ui->tableView_2_prop->setModel(p.sort_Price());
}

void MainWindow::on_lineEdit_cherche_function_textChanged(const QString &arg1)
{
    a.cleartable(ui->tabagent);
    QString function_ag=ui->lineEdit_cherche_function->text();
    a.rechercher_function(ui->tabagent,function_ag);
}




void MainWindow::on_chat_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_pushButton_security_arduino_clicked()
{
    A.write_to_arduino("1"); //envoyer 1 à arduino
    qDebug()<<"sent to arduino 1 " ;
}



void MainWindow::on_pushButton_security_arduino_2_clicked()
{
    A.write_to_arduino("0");
     qDebug()<<"sent to arduino  0" ;
     ui->label_13->setText("No one Is Detected");
      ui->label_14->setText("No One is Detected to launch alarm");
}

void MainWindow::on_pushButton_28_clicked()
{
    QDesktopServices::openUrl(QUrl::fromLocalFile(camera.localisation));
    qDebug()<<"localisation camera est :"<<camera.localisation ;
}

void MainWindow::on_pushButton_arduino_clicked()
{
    int ret=A.connect_arduino(); // lancer la connexion à arduino
       switch(ret){
       case(0):qDebug()<< "arduino is available and connected to : "<< A.getarduino_port_name();
           break;
       case(1):qDebug() << "arduino is available but not connected to :" <<A.getarduino_port_name();
          break;
       case(-1):qDebug() << "arduino is not available";
       }
        QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_label())); // permet de lancer
        //le slot update_label suite à la reception du signal readyRead (reception des données).
    //data base connection :

}
