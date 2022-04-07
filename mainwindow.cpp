#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "connection.h"
#include "connection.cpp"
#include<QMessageBox>
#include<QComboBox>
#include<QSqlQuery>
#include"buyer.h"
#include "email.h"
#include <QTextStream>
#include <QTextDocument>
#include <QtPrintSupport/QPrintDialog>
#include <QtPrintSupport/QPrinter>
#include <QtWidgets>
#include<QFileDialog>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
  buyer b ;

    ui->setupUi(this);
    ui->tab_produit->setModel(b.read());
    ui->comboBox->setModel(b.read_id());
    ui->comboBox_2->setModel(b.read_agent());
    ui->comboBox_3->setModel(b.read_id());
    //ui->tableView2->setModel(b.recomondation());
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
             ui->comboBox_3->setModel(b.read_id());
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
ui->comboBox_3->setModel(b.read_id());
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

void MainWindow::on_tri_stock_clicked()
{
    ui->tab_produit->setModel(b.sort_name());
    QMessageBox::information(nullptr, QObject::tr("Ok"),
                QObject::tr("tri effectu.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}

void MainWindow::on_trier_clicked()
{
     ui->tab_produit->setModel(b.sort_request());
    QMessageBox::information(nullptr, QObject::tr("Ok"),
                QObject::tr("tri effectu.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}

void MainWindow::on_trier_2_clicked()
{
    ui->tab_produit->setModel(b.sort_adress());
    QMessageBox::information(nullptr, QObject::tr("Ok"),
                QObject::tr("tri effectu.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}

void MainWindow::on_rechercher_2_clicked()
{
    int code=ui->chercher_id->text().toInt();
                 ui->tab_produit->setModel(b.find_id(code));
                 QMessageBox::information(nullptr,QObject::tr("OK"),
                                           QObject::tr("recherche effectue.\n"
                                                       "clic cancel to exit."),QMessageBox::Cancel);
}

void MainWindow::on_rechercher_3_clicked()
{
    QString name=ui->chercher_name->text();
                 ui->tab_produit->setModel(b.find_name(name));
                 QMessageBox::information(nullptr,QObject::tr("OK"),
                                           QObject::tr("recherche effectue.\n"
                                                       "clic cancel to exit."),QMessageBox::Cancel);
}

void MainWindow::on_rechercher_4_clicked()
{
    QString req=ui->chercher_request->text();
                 ui->tab_produit->setModel(b.find_request(req));
                 QMessageBox::information(nullptr,QObject::tr("OK"),
                                           QObject::tr("recherche effectue.\n"
                                                       "clic cancel to exit."),QMessageBox::Cancel);
}



void MainWindow::on_sort_id_clicked()
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
    int id_buy1 = ui->comboBox_3->currentText().toInt();

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
