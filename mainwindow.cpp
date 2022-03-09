#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "sellers.h"
#include <QString>
#include <QMessageBox>
#include <QtSql>
#include <QIntValidator>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->comboBox->setModel(S.read_id());
   ui->id_sel->setValidator(new QIntValidator(0, 9999, this));
   ui->num_sel->setValidator(new QIntValidator(0,99999999,this));
   ui->tab_seller->setModel(S.afficher());
  /* QRegularExpression rx("\\b[A-Z ._%+-]+@[A-Z .-]+\\.[A-Z]\\b",
                                             QRegularExpression::CaseInsensitiveOption);
                   ui->lastname_sel->setValidator(new QRegularExpressionValidator(rx, this));

                   QRegularExpression rx1("\\b[A-Z ._%+-]+@[A-Z .-]+\\.[A-Z]\\b",
                                                 QRegularExpression::CaseInsensitiveOption);
                       ui->name_sel->setValidator(new QRegularExpressionValidator(rx1, this));

                       QRegularExpression rx2("\\b[A-Z 1-9 ._%+-]+@[A-Z .-]+\\.[A-Z]\\b",
                                                     QRegularExpression::CaseInsensitiveOption);
                           ui->adress_sel->setValidator(new QRegularExpressionValidator(rx2, this));*/


                                   QRegularExpression rx3("\\b[A-Z._%+-]+@[A-Z.-]+\\.[A-Z]\\b",
                                                                 QRegularExpression::CaseInsensitiveOption);
                                    ui->mail_sel->setValidator(new QRegularExpressionValidator(rx3, this));


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pb_Add_clicked()
{
   int id_sel=ui->id_sel->text().toInt();
   QString lastname_sel=ui->lastname_sel->text();
   QString name_sel=ui->name_sel->text();
   QString adress_sel=ui->adress_sel->text();
   int num_sel=ui->num_sel->text().toInt();
   QString mail_sel=ui->mail_sel->text();

  Seller S(id_sel,lastname_sel,name_sel,adress_sel,num_sel,mail_sel);
  bool test=S.ajouter();
           if(test)
           {
               ui->tab_seller->setModel(S.afficher());
               ui->comboBox->setModel(S.read_id());
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


void MainWindow::on_pushButton_clicked()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
           db.setDatabaseName("realestate");
           db.setUserName("ghofrane");//inserer nom de l'utilisateur
           db.setPassword("ghofrane");
           if(db.open()){
               QMessageBox::information(this,"Connection","Database Connected Successfully");
           }
           else{
               QMessageBox::information(this,"Not Connected","Database Not connected");
           }
}

void MainWindow::on_pb_read_clicked()
{
    ui->tab_seller->setModel(S.afficher());
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

    }
    else
        msgBox.setText("deletion failed");
    msgBox.exec();


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


void MainWindow::on_comboBox_currentIndexChanged(int id)
{
     id=ui->comboBox->currentText().toInt();

        QSqlQuery query;

    query.prepare("select * from SELLERS where ID_SEL=:id");
    query.bindValue(":id",id);
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
