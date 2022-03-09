#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "connection.h"
#include "connection.cpp"
#include<QMessageBox>
#include<QComboBox>
#include<QSqlQuery>
#include"buyer.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
  buyer b ;

    ui->setupUi(this);
    ui->tab_produit->setModel(b.read());
    ui->comboBox->setModel(b.read_id());
    ui->comboBox_2->setModel(b.read_agent());
        ui->lineEdit_id->setValidator( new QIntValidator(0, 999999, this));
        ui->lineEdit_num->setValidator( new QIntValidator(0, 99999999, this));





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
                                ui->lineEdit_request->setValidator(new QRegularExpressionValidator(rx3, this));

                                QRegularExpression rx4("\\b[A-Z._%+-]+@[A-Z.-]+\\.[A-Z]\\b",
                                                              QRegularExpression::CaseInsensitiveOption);
                                 ui->lineEdit_mail->setValidator(new QRegularExpressionValidator(rx4, this));


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("Source_Projet2A");
    db.setUserName("aziz");//inserer nom de l'utilisateur
    db.setPassword("aziz");
    if(db.open()){
        QMessageBox::information(this,"Connection","Database Connected Successfully");
    }
    else{
        QMessageBox::information(this,"Not Connected","Database Not connected");
    }
}



void MainWindow::on_valider_clicked()
{
   int id_buy=ui->lineEdit_id->text().toInt();
    QString lastname_buy=ui->lineEdit_lastname->text();
     QString name_buy=ui->lineEdit_name->text();
      QString adress_buy=ui->lineEdit_adress->text();
       QString request_buy=ui->lineEdit_request->text();
       int num_buy=ui->lineEdit_num->text().toInt();
         QString mail_buy=ui->lineEdit_mail->text();
         int id_agent=ui->comboBox_2->currentText().toInt();
         buyer b(id_buy,lastname_buy,name_buy,adress_buy,request_buy,num_buy,mail_buy,id_agent);
         bool test=b.addbuyer();
         if(test)
         {
             ui->tab_produit->setModel(b.read());
             ui->comboBox->setModel(b.read_id());
             ui->comboBox_2->setModel(b.read_agent());
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
















void MainWindow::on_read_clicked()
{
    buyer b ;
    ui->tab_produit->setModel(b.read1());
   /*ui->comboBox->setModel(b.read_id());*/
}

void MainWindow::on_pushButton_delete_clicked()
{
    buyer b;
    int id_buy=ui->lineEdit_del->text().toInt();
    int id_buy2=ui->comboBox->currentText().toInt();
    bool test= b.supprimer(id_buy);
    bool test1= b.supprimer(id_buy2);
    if(test || test1) {

        ui->tab_produit->setModel(b.read());
       ui->comboBox->setModel(b.read_id());
       ui->comboBox_2->setModel(b.read_agent());
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



void MainWindow::on_pushButton_2_clicked()
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
                 ui->comboBox->setModel(b.read_id());


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

void MainWindow::on_pushButton_show_clicked()
{
    buyer b ;

    ui->comboBox->setModel(b.read_id());
}






void MainWindow::on_comboBox_currentIndexChanged(int id )
{
    id=ui->comboBox->currentText().toInt();

    QSqlQuery query;

query.prepare("select * from buyers where ID_BUY=:id");
query.bindValue(":id",id);
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
