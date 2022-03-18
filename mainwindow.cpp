#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "sellers.h"
#include <QString>
#include <QMessageBox>
#include <QtSql>
#include <QIntValidator>
#include <QLabel>
#include "notification.h"
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
   ui->setupUi(this);
   ui->comboBox_2->setModel(S.read_id());
   ui->comboBox_3->setModel(S.read_id_buy());
   ui->comboBox->setModel(S.read_id());
   ui->id_sel->setValidator(new QIntValidator(0, 9999, this));
   ui->num_sel->setValidator(new QIntValidator(0,99999999,this));
   ui->num_modif->setValidator(new QIntValidator(0,99999999,this));
   ui->tab_seller->setModel(S.afficher());
   QRegularExpression rx("\\b[A-Z ._%+-]+@[A-Z .-]+\\.[A-Z]\\b",
   QRegularExpression::CaseInsensitiveOption);
   ui->lastname_sel->setValidator(new QRegularExpressionValidator(rx, this));
   ui->lastname_modif->setValidator(new QRegularExpressionValidator(rx, this));
   QRegularExpression rx1("\\b[A-Z ._%+-]+@[A-Z .-]+\\.[A-Z]\\b",
   QRegularExpression::CaseInsensitiveOption);
   ui->name_sel->setValidator(new QRegularExpressionValidator(rx1, this));
   ui->name_modif->setValidator(new QRegularExpressionValidator(rx1, this));
   QRegularExpression rx2("\\b[A-Z 1-9 ._%+-]+@[A-Z .-]+\\.[A-Z]\\b",
   QRegularExpression::CaseInsensitiveOption);
   ui->adress_sel->setValidator(new QRegularExpressionValidator(rx2, this));
   ui->adress_modif->setValidator(new QRegularExpressionValidator(rx2, this));

   QRegularExpression rx3("\\b[A-Z._%+-]+@[A-Z.-]+\\.[A-Z]\\b",
   QRegularExpression::CaseInsensitiveOption);
   ui->mail_sel->setValidator(new QRegularExpressionValidator(rx3, this));
   ui->mail_modif->setValidator(new QRegularExpressionValidator(rx3, this));


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
    // A modifier
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





void MainWindow::on_search_id_clicked()
{
    int code=ui->search_id_2->text().toInt();
                     ui->tab_seller->setModel(S.find_id(code));
                     QMessageBox::information(nullptr,QObject::tr("OK"),
                                               QObject::tr("recherche effectue.\n"
                                                           "clic cancel to exit."),QMessageBox::Cancel);
}

void MainWindow::on_search_name_clicked()
{
    QString name=ui->search_name_2->text();
                     ui->tab_seller->setModel(S.find_name(name));
                     QMessageBox::information(nullptr,QObject::tr("OK"),
                                               QObject::tr("recherche effectue.\n"
                                                           "clic cancel to exit."),QMessageBox::Cancel);
}

void MainWindow::on_search_adress_clicked()
{
    QString adress=ui->search_adress_2->text();
                     ui->tab_seller->setModel(S.find_adress(adress));
                     QMessageBox::information(nullptr,QObject::tr("OK"),
                                               QObject::tr("recherche effectue.\n"
                                                           "clic cancel to exit."),QMessageBox::Cancel);
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

void MainWindow::on_generatepdf_clicked()
{
    int id_sel1=ui->comboBox_2->currentText().toInt();
    int id_buy1=ui->comboBox_3->currentText().toInt();
     QPdfWriter pdf("C:/Users/GHOFRANE/Desktop/Sellers/contract.pdf");

          QPainter painter(&pdf);


          painter.setPen(Qt::black);
          painter.setFont(QFont("Arial", 30));
          painter.drawPixmap(QRect(100,400,2000,2000),QPixmap("C:/Users/GHOFRANE/Desktop/Sellers/logo.png"));
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
          painter.drawText(500,300, asctime(ti));
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



          painter.setPen(Qt::black);
          painter.setFont(QFont("Arial", 15));
          painter.drawText(300,13000,"Seller's Signature");

          painter.setPen(Qt::black);
          painter.setFont(QFont("Arial", 15));
          painter.drawText(7000,13000,"Buyer's Signature");


          int reponse = QMessageBox::question(this, "PDF Generated", "Show the PDF?", QMessageBox::Yes |  QMessageBox::No);
          if (reponse == QMessageBox::Yes)
          {
              QDesktopServices::openUrl(QUrl::fromLocalFile("C:/Users/GHOFRANE/Desktop/Sellers/contract.pdf"));

              painter.end();
          }
          if (reponse == QMessageBox::No)
          {
              painter.end();
          }
      }
}
