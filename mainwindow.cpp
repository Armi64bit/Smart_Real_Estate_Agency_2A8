#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <partners.h>
#include <QtDebug>
#include <QtMessageHandler>
#include <QMessageBox>
#include <connection.h>
#include <QComboBox>
#include <QFileDialog>
#include <QPdfWriter>
#include <QDesktopServices>
#include "excel.h"
#include "parking.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    int ret=A.connect_arduino(); // lancer la connexion à arduino
    switch(ret){
    case(0):qDebug()<< "arduino is available and connected to : "<< A.getarduino_port_name();
        break;
    case(1):qDebug() << "arduino is available but not connected to :" <<A.getarduino_port_name();
       break;
    case(-1):qDebug() << "arduino is not available";
    }
      data=A.read_from_arduino();
    qDebug() << data;

  int a= pr.dispo_place();
  QByteArray abyte0;

  abyte0.resize(4);

  abyte0[0] = (uchar)
(0x000000ff & a);

A.write_to_arduino(abyte0);


     QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_label())); // permet de lancer
     //le slot update_label suite à la reception du signal readyRead (reception des données).
    ui->setupUi(this);
    ui->tab_produit->setModel(p.read());
    ui->tab_produit->verticalHeader()->hide();
    ui->idbox->setModel(p.read_id());
    ui->id_par->setValidator( new QIntValidator(0, 999999, this));
            ui->sub_num_par->setValidator( new QIntValidator(0, 99999999, this));





            QRegularExpression rx("\\b[A-Z ._%+-]+@[A-Z .-]+\\.[A-Z]\\b",
                                              QRegularExpression::CaseInsensitiveOption);
                    ui->name_par->setValidator(new QRegularExpressionValidator(rx, this));

                    QRegularExpression rx3("\\b[A-Z ._%+-]+@[A-Z .-]+\\.[A-Z]\\b",
                                                      QRegularExpression::CaseInsensitiveOption);
                            ui->contract_language_par->setValidator(new QRegularExpressionValidator(rx, this));

                    QRegularExpression rx1("\\b[A-Z ._%+-]+@[A-Z .-]+\\.[A-Z]\\b",
                                                  QRegularExpression::CaseInsensitiveOption);
                        ui->name_up->setValidator(new QRegularExpressionValidator(rx1, this));

                        QRegularExpression rx2("\\b[A-Z ._%+-]+@[A-Z .-]+\\.[A-Z]\\b",
                                                      QRegularExpression::CaseInsensitiveOption);
                            ui->type_par->setValidator(new QRegularExpressionValidator(rx2, this));

                                    QRegularExpression rx4("\\b[A-Z._%+-]+@[A-Z.-]+\\.[A-Z]\\b",
                                                                  QRegularExpression::CaseInsensitiveOption);
                                     ui->duration_par->setValidator(new QRegularExpressionValidator(rx, this));

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
     ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_12_clicked()
{
     ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_2_clicked()
{
  ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_pushButton_11_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_pushButton_3_clicked()
{
     ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_pushButton_10_clicked()
{
     ui->stackedWidget->setCurrentIndex(6);
}

void MainWindow::on_pushButton_6_clicked()
{
     ui->stackedWidget->setCurrentIndex(7);
}

void MainWindow::on_pushButton_14_clicked()
{
       ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_18_clicked()
{
       ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_20_clicked()
{
       ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_22_clicked()
{
       ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_24_clicked()
{
       ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_25_clicked()
{
     ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_26_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);

}

void MainWindow::on_pushButton_27_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);

}

void MainWindow::on_pushButton_28_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);

}

void MainWindow::on_pushButton_29_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);

}

void MainWindow::on_pushButton_30_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);

}

void MainWindow::on_pushButton_33_clicked()
{
     ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_9_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_pushButton_15_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_add_clicked()
{
    int sub_num_par=ui->sub_num_par->text().toInt();
    int id_par=ui->id_par->text().toInt();

    QString name_par=ui->name_par->text();
    QString type_par=ui->type_par->text();
    QString duration_par=ui->duration_par->text();
    QString contract_language_par=ui->contract_language_par->text();


 PARTNERS p(id_par,sub_num_par,name_par,type_par,duration_par,contract_language_par);
  bool test =p.add();
  if(test)
  {ui->tab_produit->setModel(p.read());
       ui->idbox->setModel(p.read_id());
      QMessageBox::information(nullptr, QObject::tr("added"),
                  QObject::tr("successful.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("error"),
                  QObject::tr("add failed.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);



}
/*
void MainWindow::on_load_clicked()
{
    Connection c;
 QSqlQueryModel * modal=new QSqlQueryModel();
 c.createconnect();
 QSqlQuery* qry=new QSqlQuery (c.get_db());
 qry->prepare("SELECT * FROM PARTNERS");
 qry->exec();
 modal->setQuery(*qry);
 ui->tab_produit->setModel(modal);
 c.closeconnect();
 qDebug()<<(modal->rowCount());

}*/

void MainWindow::on_supprimer_clicked()
{
   int id = ui->id_dell->text().toInt();
   bool  test=p.dell(id);
   if(test)
   {ui->tab_produit->setModel(p.read());
        ui->idbox->setModel(p.read_id());
       QMessageBox::information(nullptr, QObject::tr("done"),
                   QObject::tr("delete successful.\n"
                               "Click Cancel to exit."), QMessageBox::Cancel);

}
   else
       QMessageBox::critical(nullptr, QObject::tr("ERROR"),
                   QObject::tr("delete failed.\n"
                               "Click Cancel to exit."), QMessageBox::Cancel);












}


void MainWindow::on_update_2_clicked()
{
            int id_par=ui->id_up->text().toInt();
            QString name_par=ui->name_up->text();
            QString duration_par=ui->duration_up->text();
            int numsub=ui->subnum_up->text().toInt();
            QString contract=ui->conlang_up->text();
            QString type_par=ui->type_up->text();

                     PARTNERS Sub(id_par,numsub,name_par,type_par,duration_par,contract);//creer objet/instance et passer par contructr paramétré
                 //pour verifier ajout:   (shih fl fichier .cpp hedha ?)
                     bool test2=Sub.update(Sub.getid());// ou read-id ?   w getnum wala toul num?
                     //verif:
                      QMessageBox msgBox;
                     if(test2)
                     {ui->tab_produit->setModel(p.read());
                         msgBox.setText("Update successfully.");
                         ui->tab_produit->setModel(Sub.read());//refresh de mon tab (afficher une autre fois avec l'ajout effectué)
                        // ui->comboBox->setModel(Sub.read_id());
                     }
                     else
                         msgBox.setText("Error ; can't update.");
                     msgBox.exec();
/*



    int id_par=ui->id_up->text().toInt();
              QString name_par=ui->name_up->text();
               QString type_par=ui->type_up->text();
              QString duration_par=ui->duration_up->text();
                QString contract=ui->conlang_up->text();
                 int num_sub=ui->subnum_up->text().toInt();

  PARTNERS p (id_par,num_sub,name_par,type_par,duration_par,contract);
              bool test2=p.update(p.getid());
              if(test2)
              {   ui->tab_produit->setModel(p.read());
          QMessageBox::information(nullptr,QObject::tr("OK"),
                                 QObject::tr("update effectue.\n"
                                             "clic cancel to exit."),QMessageBox::Cancel);

              }
      else
          {ui->tab_produit->setModel(p.read());
      QMessageBox::critical(nullptr,QObject::tr("NOT OK"),
                                 QObject::tr("update non effectue.\n"
                                             "clic cancel to exit."),QMessageBox::Cancel);}
*/
}



void MainWindow::on_tab_produit_activated(const QModelIndex &index)
{

    QString val=ui->tab_produit->model()->data(index).toString();
    Connection c;
    c.createconnect();
   QSqlQuery qry;
   qry.prepare("SELECT * FROM PARTNERS WHERE ID_PAR=:val OR NAME_PAR=:val");
   qry.bindValue(":val",val);
   if(qry.exec()){
       while(qry.next()){
           ui->id_up->setText(qry.value(0).toString());
           ui->name_up->setText(qry.value(1).toString());
           ui->type_up->setText(qry.value(2).toString());
           ui->duration_up->setText(qry.value(3).toString());
           ui->conlang_up->setText(qry.value(4).toString());
           ui->subnum_up->setText(qry.value(5).toString());


       }
       c.closeconnect();
   }
else {
       QMessageBox::critical(this,tr("error::"),qry.lastError().text());
   }
}



void MainWindow::on_pushButton_5_clicked()
{
    //int id=ui->id_up->text().toInt();
    int id=ui->idbox->currentText().toInt();

        QSqlQuery qry;

    qry.prepare("SELECT * FROM PARTNERS WHERE ID_PAR=:id");
    qry.bindValue(":id",id);
    if(qry.exec())
    {ui->tab_produit->setModel(p.read());
        while(qry.next())
              {
            ui->id_up->setText(qry.value(0).toString());
            ui->name_up->setText(qry.value(1).toString());
            ui->type_up->setText(qry.value(2).toString());
            ui->duration_up->setText(qry.value(3).toString());
            ui->conlang_up->setText(qry.value(4).toString());
            ui->subnum_up->setText(qry.value(5).toString());


        }
    }
}

void MainWindow::on_rechercher_2_clicked()
{
    int id=ui->chercher_2->text().toInt();

        QSqlQuery qry;

    qry.prepare("SELECT * FROM PARTNERS WHERE ID_PAR=:id");
    qry.bindValue(":id",id);
    if(qry.exec())
    {ui->tab_produit->setModel(p.read1(id));

    }
}


void MainWindow::on_tri_stock_clicked()
{
    ui->tab_produit-> setModel(p.sort_name_ag());
            QMessageBox::information(nullptr, QObject::tr("Ok"),
                        QObject::tr("tri effectu.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_trier_clicked()
{
    ui->tab_produit-> setModel(p.sort_id());
            QMessageBox::information(nullptr, QObject::tr("Ok"),
                        QObject::tr("tri effectu.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_trier_2_clicked()
{
    ui->tab_produit-> setModel(p.sort_lg());
            QMessageBox::information(nullptr, QObject::tr("Ok"),
                        QObject::tr("tri effectu.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
}


void MainWindow::on_chercher_3_textChanged(const QString &arg1)
{
    p.cleartable(ui->tab_produit);
        QString name=ui->chercher_3->text();
        p.rechercher_name(ui->tab_produit, name);
}

void MainWindow::on_chercher_2_textChanged(const QString &arg1)
{
    p.cleartable(ui->tab_produit);
        int name=ui->chercher_2->text().toInt();
        p.rechercher_id(ui->tab_produit, name);

}


void MainWindow::on_tri_stock_2_clicked()
{
    int ID_PAR=ui->idbox->currentText().toInt();

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

void MainWindow::on_tri_stock_3_clicked()
{

    QString fileName = QFileDialog::getSaveFileName(this, tr("Excel file"), qApp->applicationDirPath (),
                                                               tr("Excel Files (*.xls)"));
               if (fileName.isEmpty())
                   return;

               ExportExcelObject obj(fileName, "mydata", ui->tab_produit);

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

void MainWindow::on_tri_stock_4_clicked()
{

    int ID_PAR=ui->idbox->currentText().toInt();

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

void MainWindow::on_tri_stock_5_clicked()
{

    int ID_PAR=ui->idbox->currentText().toInt();

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

void MainWindow::on_ig_clicked()
{
     QDesktopServices::openUrl(QUrl("https://www.instagram.com/armiisnotred/", QUrl::TolerantMode));



}

void MainWindow::on_fb_clicked()
{
        QDesktopServices::openUrl(QUrl("https://www.facebook.com", QUrl::TolerantMode));
}

void MainWindow::on_linkedin_clicked()
{
     QDesktopServices::openUrl(QUrl("https://www.linkedin.com", QUrl::TolerantMode));

}

void MainWindow::update_label()
{
    data=A.read_from_arduino();

    if(data!="0"){
A.write_to_arduino("1");
p.update(data.toInt());   // TAL3 ACEE

QMessageBox msgBox;

msgBox.setText("Spots left = " +QString::number(data.toInt()));
msgBox.exec();
 qDebug() << data;

    }
    else if(data=="0"){
        QMessageBox::information(nullptr, QObject::tr("spots left"),
                    QObject::tr("NO SPOTS LEFT.\n"), QMessageBox::Cancel);
         A.write_to_arduino("3");  // mafamch blassa
    }

}

