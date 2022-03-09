#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QMessageBox>
#include <QtSql/QSqlQuery>
#include"agent.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    agent a ;
    ui->tabagent->setModel(a.afficher());
    ui->comboBox->setModel(a.afficher_id());
    ui->lineEdit_cin->setValidator( new QIntValidator(10000000, 999999999, this));
            ui->lineEdit_number ->setValidator( new QIntValidator(10000000, 999999999, this));





            QRegularExpression rx("\\b[A-Z ._%+-]+@[A-Z .-]+\\.[A-Z]\\b",
                                              QRegularExpression::CaseInsensitiveOption);
                    ui->lineEdit_lastname->setValidator(new QRegularExpressionValidator(rx, this));

                    QRegularExpression rx1("\\b[A-Z ._%+-]+@[A-Z .-]+\\.[A-Z]\\b",
                                                  QRegularExpression::CaseInsensitiveOption);
                        ui->lineEdit_name->setValidator(new QRegularExpressionValidator(rx1, this));

                        QRegularExpression rx2("\\b[A-Z ._%+-]+@[A-Z .-]+\\.[A-Z]\\b",
                                                      QRegularExpression::CaseInsensitiveOption);
                            ui->lineEdit_adress->setValidator(new QRegularExpressionValidator(rx2, this));
                            QRegularExpression rx3("\\b[A-Z 1-9 ._%+-]+@[A-Z 1-9 .-]+\\.[A-Z]\\b",
                                                              QRegularExpression::CaseInsensitiveOption);
                                    ui->lineEdit_mail ->setValidator(new QRegularExpressionValidator(rx, this));

                                    QRegularExpression rx4("\\b[A-Z._%+-]+@[A-Z.-]+\\.[A-Z]\\b",
                                                                  QRegularExpression::CaseInsensitiveOption);
                                     ui->lineEdit_adress->setValidator(new QRegularExpressionValidator(rx, this));
                                     QRegularExpression rx5("\\b[A-Z._%+-]+@[A-Z.-]+\\.[A-Z]\\b",
                                                                   QRegularExpression::CaseInsensitiveOption);
                                      ui->lineEdit_function->setValidator(new QRegularExpressionValidator(rx, this));
                                      QRegularExpression rx6("\\b[A-Z._%+-]+@[A-Z.-]+\\.[A-Z]\\b",
                                                                    QRegularExpression::CaseInsensitiveOption);
                                       ui->lineEdit_login->setValidator(new QRegularExpressionValidator(rx, this));

                                       QRegularExpression rx7("\\b[A-Z._%+-]+@[A-Z.-]+\\.[A-Z]\\b",
                                                                     QRegularExpression::CaseInsensitiveOption);
                                        ui->lineEdit_password->setValidator(new QRegularExpressionValidator(rx, this));

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
     ui->stackedWidget->setCurrentIndex(1);


}





void MainWindow::on_pushButton_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);

}

void MainWindow::on_pushButton_8_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);

}

void MainWindow::on_pushButton_11_clicked()
{
     ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_12_clicked()
{
      ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_13_clicked()
{
      ui->stackedWidget->setCurrentIndex(0);
}





// bouton ajout
void MainWindow::on_pushButton_2_clicked()
{

            int cin_ag=ui->lineEdit_cin->text().toInt();
             QString lastname_ag =ui->lineEdit_lastname->text();
            QString name_ag = ui->lineEdit_lastname->text();
           int num_ag = ui->lineEdit_number->text().toInt();
           QString mail_ag = ui->lineEdit_mail->text();
            QString adress_ag=ui->lineEdit_adress->text();
           QString function_ag =ui->lineEdit_function->text();
           QString login_ag =ui->lineEdit_login->text();
           QString password_ag =ui->lineEdit_password->text();
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
void MainWindow::on_pushButton_5_clicked()
{
    agent a ;
        int cin_ag=ui->lineEdit_cin_2->text().toInt();

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
void MainWindow::on_comboBox_currentIndexChanged(int id)
{


    id=ui->comboBox->currentText().toInt();

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
    agent a ;
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
                                               "clic cancel to exit."),QMessageBox::Cancel);}
}
