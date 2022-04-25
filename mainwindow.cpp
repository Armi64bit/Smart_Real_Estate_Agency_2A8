#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "video.h"
#include "property.h"
#include "dialog.h"
#include <QApplication>
#include "camera.h"
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QFileDialog>
#include <QPainter>
#include <QPdfWriter>
#include "arduino.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    Property p;
    ui->setupUi(this);
    //arduino:
    QSqlDatabase db=QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("test");
    db.setUserName("dhafer");
    db.setPassword("dhafer");

    if(db.open()){
        QMessageBox::information(this,"Connection","Database Connected Successfully");

    }
    else {
        QMessageBox::information(this,"Not Connected","Database Not connected");
    }
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







    //
    //showing tables and comboboxes :

    ui->tableView_2->setModel(p.read());
    ui->comboBox->setModel(p.read());
    ui->comboBox_2->setModel(p.read_buyer());
    ui->comboBox_3->setModel(p.read_seller());
     ui->comboBox_4->setModel(p.read());
    //
    ui->lineEdit_Id_prop->setValidator(new QIntValidator(0,99999999,this));
    QPixmap pixmap("C:/Users/Souid/Desktop/projetQT/ressourcesgraphiques/button.jpg");
    QIcon ButtonIcon(pixmap);
    //ui->pushButton_3->setIcon(ButtonIcon);
   // ui->pushButton_3->setIconSize(pixmap.rect().size());


    QPixmap pixmap_play("C:/Users/Souid/Desktop/projetQT/ressourcesgraphiques/audio_02.jpg");
    QIcon ButtonIcon_play(pixmap_play);
    ui->pushButton_16->setIcon(ButtonIcon_play);
    ui->pushButton_16->setIconSize(pixmap_play.rect().size());

    QPixmap pixmap_pause("C:/Users/Souid/Desktop/projetQT/ressourcesgraphiques/audio_01.jpg");
    QIcon ButtonIcon_pause(pixmap_pause);
    ui->pushButton_17->setIcon(ButtonIcon_pause);
    ui->pushButton_17->setIconSize(pixmap_pause.rect().size());



    ////map
    ///combobox
   //push buttons in table :
    /*



    m_button = new QPushButton("My Button", this);
      // set size and location of the button
    const int currentRow = ui->tableView_2->model()->rowCount();
    for(int i=0;i<currentRow;i++)
     ui->tableView_2->setIndexWidget(ui->tableView_2->model()->index(i, 7), new QPushButton);
      m_button->setGeometry(QRect(QPoint(100, 100), QSize(200, 50)));

      // Connect button signal to appropriate slot
      connect(m_button, &QPushButton::released, this, &MainWindow::MapButton);

    //*/



    ui->lineEdit_Id_prop->setValidator( new QIntValidator(0, 999999, this));
            ui->lineEdit_price_pro->setValidator( new QIntValidator(0, 99999999, this));

           // ui->lineEdit_latitude_prop->setValidator( new QIntValidator(0, 99999999, this));
           // ui->lineEdit_longitude_prop->setValidator( new QIntValidator(0, 99999999, this));





            QRegularExpression rx("\\b[A-Z ._%+-]+@[A-Z .-]+\\.[A-Z]\\b",
                                              QRegularExpression::CaseInsensitiveOption);
                    ui->lineEdit_Type_prop->setValidator(new QRegularExpressionValidator(rx, this));

                    QRegularExpression rx1("\\b[A-Z ._%+-]+@[A-Z .-]+\\.[A-Z]\\b",
                                                  QRegularExpression::CaseInsensitiveOption);


}

MainWindow::~MainWindow()
{
    delete ui;


}


void MainWindow::on_pushButton_clicked()
{

    Property P ;

    P.setID(ui->lineEdit_Id_prop->text());
    P.setType(ui->lineEdit_Type_prop->text());
    P.setPrice(ui->lineEdit_price_pro->text());


    Dialog d ;
    d.setProperty(P);
    d.exec();


}

void MainWindow::on_pushButton_3_clicked()
{
    player=new QMediaPlayer(this);
    QMainWindow *window1 = new QMainWindow();
    QVideoWidget *vw = new QVideoWidget ;
    player->setVideoOutput(vw);
    player->setMedia(QUrl::fromLocalFile("C:/Users/Souid/Downloads/Qtvideo.mp4"));
    window1->setCentralWidget(vw);
   // vw->setGeometry(100,100,300,400);
    QPushButton *close_button = new QPushButton(window1);
    close_button->setText(tr("something"));
    close_button->move(0, 0);
    close_button->show();
    player->play();
    window1->show();
    vw->show();
QObject::connect(close_button, SIGNAL(clicked()), this, SLOT(pause_button()));

    //
    // player->setVideoOutput(vw);



   //  playlist->setCurrentIndex(1);

   //  vw->show();
    // player->pause();





}

void MainWindow::on_pushButton_3_toggled(bool checked)
{

}

void MainWindow::on_pushButton_4_databaseprop_clicked()
{

}

void MainWindow::on_pushButton_database_insert_clicked()
{
Property P(ui->lineEdit_Id_prop->text(),ui->lineEdit_Type_prop->text(),ui->lineEdit_longitude_prop->text(),ui->lineEdit_latitude_prop->text(),ui->lineEdit_price_pro->text(),ui->comboBox_2->currentText().toInt(),ui->comboBox_3->currentText().toInt(),ui->lineEdit->text(),ui->plainTextEdit->toPlainText(),ui->lineEdit_2->text()) ;

qDebug()<<"hello" ;
if(P.addProperty())
{
        QMessageBox::information(this,"inserted","house inserted Successfully");
        ui->tableView_2->setModel(P.read());
        ui->comboBox->setModel(P.read());
        ui->comboBox_2->setModel(P.read_buyer());
        ui->comboBox_3->setModel(P.read_seller());
        ui->comboBox_4->setModel(P.read());
}
        else {
       QMessageBox::information(this,"not inserted","house not inserted Successfully");
}


}

void MainWindow::on_pushButton_4_clicked()
{



}

void MainWindow::on_pushButton_5_clicked()
{
ui->lineEdit_Id_prop->setText("");
ui->lineEdit_Type_prop->setText("");
ui->lineEdit_price_pro->setText("");

ui->lineEdit_find_id_prop->setText("");
ui->lineEdit_latitude_prop->setText("");
ui->lineEdit_longitude_prop->setText("");
ui->lineEdit_find_price_prop->setText("");

}

void MainWindow::on_pushButton_6_clicked()
{
    Property P ;
    int id=ui->comboBox_4->currentText().toInt();

 if( P.delete_Property(id)) {

        ui->tableView_2->setModel(P.read());
        ui->comboBox_4->setModel(P.read());
               QMessageBox::information(nullptr,QObject::tr("OK"),
                                      QObject::tr("delete done.\n"
                                                  "clic cancel to exit."),QMessageBox::Cancel);
    }
    else
        {ui->tableView_2->setModel(P.read());
      ui->comboBox_4->setModel(P.read());
    QMessageBox::critical(nullptr,QObject::tr("NOT OK"),
                               QObject::tr("delete not done .\n"
                                           "clic cancel to exit."),QMessageBox::Cancel);}
}



void MainWindow::on_comboBox_currentIndexChanged(const QString &arg1)
{
    int id=ui->comboBox->currentText().toInt();
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

void MainWindow::on_pushButton_7_clicked()
{
Property P(ui->lineEdit_Id_prop->text(),ui->lineEdit_Type_prop->text(),ui->lineEdit_longitude_prop->text(),ui->lineEdit_latitude_prop->text(),ui->lineEdit_price_pro->text(),ui->comboBox_2->currentText().toInt(),ui->comboBox_3->currentText().toInt(),ui->lineEdit->text(),ui->plainTextEdit->toPlainText(),ui->lineEdit_2->text()) ;
if(P.update())
{
        QMessageBox::information(this,"inserted","house inserted Successfully");

        ui->tableView_2->setModel(P.read());
        ui->comboBox->setModel(P.read());
        ui->comboBox_2->setModel(P.read_buyer());
        ui->comboBox_3->setModel(P.read_seller());
        ui->comboBox_4->setModel(P.read());

}
        else {
       QMessageBox::information(this,"not inserted","house not inserted Successfully");

       ui->tableView_2->setModel(P.read());
       ui->comboBox->setModel(P.read());
       ui->comboBox_2->setModel(P.read_buyer());
       ui->comboBox_3->setModel(P.read_seller());
        ui->comboBox_4->setModel(P.read());
}

}

void MainWindow::on_pushButton_11_clicked()
{
    Property p;
    ui->tableView_2->setModel(p.sort_ID());
}

void MainWindow::on_pushButton_12_clicked()
{
    Property p;
    ui->tableView_2->setModel(p.sort_type());
}

void MainWindow::on_pushButton_13_clicked()
{
    Property p;
    ui->tableView_2->setSortingEnabled(true);
    ui->tableView_2->setModel(p.sort_Price());

}

void MainWindow::on_pushButton_8_clicked()
{
    Property p ;
    ui->tableView_2->setModel(p.find_id(ui->lineEdit_find_id_prop->text().toInt()));
}

void MainWindow::on_pushButton_9_clicked()
{
    Property p ;
    ui->tableView_2->setModel(p.find_type(ui->lineEdit_find_type_prop->text()));
}

void MainWindow::on_pushButton_10_clicked()
{
    Property p ;
    ui->tableView_2->setModel(p.find_price(ui->lineEdit_find_price_prop->text().toInt()));
}

void MainWindow::on_pushButton_14_clicked()
{
    Property p ;
    QString home = "Image";
       QString path = QFileDialog::getOpenFileName(this, "Select Image", home + "/Images",
                                                   "Images(*.jpg);;All Files(*.*)");
       QFileInfo relativePath(path);
             QString localisation=relativePath.filePath();
             qDebug()<<"localisation est :"<<localisation ;
             ui->lineEdit_2->setText(localisation);
}
void MainWindow::MapButton()
{
  // change the text
  m_button->setText("Example");
  // resize button
  m_button->resize(100,100);
}
void MainWindow::showmap()
{

}

void MainWindow::on_tableView_2_clicked(const QModelIndex &index)
{

     if (index.isValid() && index.column()==7) {
             QString cellText = index.data().toString();
             qDebug() <<"cell number"<<index.column() ;

             map m ;
             QQmlApplicationEngine engine;
             engine.load(QUrl(QStringLiteral("qrc:/map.qml")));
             QObject *window = engine.rootObjects().first();
             QVariant lat= ui->tableView_2->model()->data(ui->tableView_2->model()->index(index.row(),2)).toString();
             QVariant lng= ui->tableView_2->model()->data(ui->tableView_2->model()->index(index.row(),3)).toString();;
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
     QString localisation=ui->tableView_2->model()->data(ui->tableView_2->model()->index(index.row(),8)).toString();
          player=new QMediaPlayer(this);
         // QMainWindow *window1 = new QMainWindow();
          QVideoWidget *vw = new QVideoWidget ;
          video_player.setVideoOutput(vw);
          video_player.setMedia(QUrl::fromLocalFile(localisation));
         // window1->setCentralWidget(vw);
          vw->setGeometry(100,100,1200,1200);

         /* QPushButton *close_button = new QPushButton(window1);
          close_button->setText(tr("something"));
          close_button->move(0, 0);
          close_button->show();*/


         // window1->show();
          vw->show();
          video_player.play();
      }
      if (index.isValid() && index.column()==9) {
     QString description=ui->tableView_2->model()->data(ui->tableView_2->model()->index(index.row(),9)).toString();
     QString localisation_image=ui->tableView_2->model()->data(ui->tableView_2->model()->index(index.row(),10)).toString();

     QPdfWriter pdf("C:/Users/Souid/Desktop/projetQT/ressourcesgraphiques/pdfgenere.pdf");
     QPainter painter(&pdf);
     painter.setFont(QFont("Arial Bold", 15));
     painter.setPen(Qt::blue);
     painter.drawText(200,200,description);
     painter.drawPixmap(QRect(0,2600,5000,5000),QPixmap(localisation_image));
     QDesktopServices::openUrl(QUrl::fromLocalFile("C:/Users/Souid/Desktop/projetQT/ressourcesgraphiques/pdfgenere.pdf"));
      }
      if (index.isValid() && index.column()==10) {
    QString localisation=ui->tableView_2->model()->data(ui->tableView_2->model()->index(index.row(),10)).toString();
     QDesktopServices::openUrl(QUrl::fromLocalFile(localisation));
      }
}
//arduino:
void MainWindow::update_label()
{
    data=A.read_from_arduino();




     if (data=="0")
     {
qDebug()<<"data est: "<< data ;
ui->label_13->setText("no one is detected !");
 ui->label_14->setText("no one is detected to launch alarm ?");
     }
       else if(data=="2")
    {
            qDebug()<<"2 est envoyé";
 ui->label_13->setText("SOMEONE IS DETECTED !");
  ui->label_14->setText("LAUNCH ALARM ?");
            camera.show();
          camera.takeImage();
          camera.add_image_todatabase();
          //QThread::msleep(5000);
          camera.applicationExiting=true;


        }
}

void MainWindow::on_pushButton_18_clicked()
{
    A.write_to_arduino("1"); //envoyer 1 à arduino
    qDebug()<<"sent to arduino 1 " ;

}

void MainWindow::on_pushButton_19_clicked()
{
     A.write_to_arduino("0");
      qDebug()<<"sent to arduino  0" ;
      ui->label_13->setText("No one Is Detected");
       ui->label_14->setText("No One is Detected to launch alarm");
}

void MainWindow::on_pushButton_22_clicked()
{
    QString home = "Videos";
       QString path = QFileDialog::getOpenFileName(this, "Select Imagae", home + "/Videos",
                                                   "Videos(*.mp4);;All Files(*.*)");
       QFileInfo relativePath(path);
             QString localisation=relativePath.filePath();
             qDebug()<<"localisation est :"<<localisation ;
             ui->lineEdit->setText(localisation);


}

void MainWindow::on_pushButton_15_clicked()
{
    video_player.pause();
}

void MainWindow::on_pushButton_23_clicked()
{
    video_player.play();
}

void MainWindow::on_lineEdit_delete_prop_cursorPositionChanged(int arg1, int arg2)
{

}

void MainWindow::on_lineEdit_find_id_prop_textChanged(const QString &arg1)
{

}

void MainWindow::on_pushButton_20_clicked()
{
     QDesktopServices::openUrl(QUrl::fromLocalFile(camera.localisation));
}


