#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <partners.h>
#include <QtDebug>
#include <QtMessageHandler>
#include <QMessageBox>
#include <connection.h>
#include <QComboBox>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tab_produit->setModel(p.read());
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
