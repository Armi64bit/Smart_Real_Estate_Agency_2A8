#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <partners.h>
#include <QtDebug>
#include <QtMessageHandler>
#include <QMessageBox>
#include <connection.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tab_produit->setModel(p.read());

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
  {
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
   {
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

}
