#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "video.h"
#include "property.h"
#include "dialog.h"
#include <QApplication>

#include <QMediaPlayer>
#include <QVideoWidget>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    Property p;
    ui->setupUi(this);
    ui->lineEdit_Id_prop->setValidator(new QIntValidator(0,99999999,this));
    QPixmap pixmap("C:/Users/Souid/Desktop/projetQT/ressourcesgraphiques/button.jpg");
    QIcon ButtonIcon(pixmap);
    ui->pushButton_3->setIcon(ButtonIcon);
    ui->pushButton_3->setIconSize(pixmap.rect().size());
    ////map
    ///combobox


    ui->lineEdit_Id_prop->setValidator( new QIntValidator(0, 999999, this));
            ui->lineEdit_price_pro->setValidator( new QIntValidator(0, 99999999, this));

            ui->lineEdit_latitude_prop->setValidator( new QIntValidator(0, 99999999, this));
            ui->lineEdit_longitude_prop->setValidator( new QIntValidator(0, 99999999, this));





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
    player->setVideoOutput(vw);
    player->setMedia(QUrl::fromLocalFile("C:/Users/Souid/Downloads/Qtvideo.mp4"));

    vw->setGeometry(100,100,300,400);
    vw->show();

    player->play();
}

void MainWindow::on_pushButton_3_toggled(bool checked)
{

}

void MainWindow::on_pushButton_4_databaseprop_clicked()
{
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
}

void MainWindow::on_pushButton_database_insert_clicked()
{
Property P(ui->lineEdit_Id_prop->text(),ui->lineEdit_Type_prop->text(),ui->lineEdit_longitude_prop->text(),ui->lineEdit_latitude_prop->text(),ui->lineEdit_price_pro->text(),ui->comboBox_2->currentText().toInt(),ui->comboBox_3->currentText().toInt()) ;

if(P.addProperty(P))
{
        QMessageBox::information(this,"inserted","house inserted Successfully");
}
        else {
       QMessageBox::information(this,"not inserted","house not inserted Successfully");
}


}

void MainWindow::on_pushButton_4_clicked()
{
    map m ;
    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/map.qml")));
    QObject *window = engine.rootObjects().first();
    QVariant lat= "36.806389";
    QVariant lng= "10.181667";
    QVariant returnedValue ;
    QMetaObject::invokeMethod(window, "addMarker",
            Q_RETURN_ARG(QVariant, returnedValue),
            Q_ARG(QVariant, lat),
            Q_ARG(QVariant, lng));



    qDebug() << "Property lng:" << QQmlProperty::read(window, "lng").toInt();
    QQmlProperty::write(window, "lng", 10.181667);

    qDebug() << "Property lng:" << window->property("lng").toInt();
    window->setProperty("lng", 10.181667);
    ///////////////////////////
    qDebug() << "Property lat:" << QQmlProperty::read(window, "lat").toInt();
    QQmlProperty::write(window, "lat",36.806389);

    qDebug() << "Property lat:" << window->property("lat").toInt();
    window->setProperty("lat", 36.806389);



    m.exec();


}

void MainWindow::on_pushButton_5_clicked()
{
    Property p;
    ui->tableView_2->setModel(p.read());
    ui->comboBox->setModel(p.read());
    ui->comboBox_2->setModel(p.read_buyer());
    ui->comboBox_3->setModel(p.read_seller());

}

void MainWindow::on_pushButton_6_clicked()
{
    Property P ;
    int id=ui->lineEdit_delete_prop->text().toInt();

 if( P.delete_Property(id)) {

        ui->tableView_2->setModel(P.read());
               QMessageBox::information(nullptr,QObject::tr("OK"),
                                      QObject::tr("delete done.\n"
                                                  "clic cancel to exit."),QMessageBox::Cancel);
    }
    else
        {ui->tableView_2->setModel(P.read());
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
Property P(ui->lineEdit_Id_prop->text(),ui->lineEdit_Type_prop->text(),ui->lineEdit_longitude_prop->text(),ui->lineEdit_latitude_prop->text(),ui->lineEdit_price_pro->text(),ui->comboBox_2->currentText().toInt(),ui->comboBox_3->currentText().toInt()) ;
if(P.update(P))
{
        QMessageBox::information(this,"inserted","house inserted Successfully");
}
        else {
       QMessageBox::information(this,"not inserted","house not inserted Successfully");
}

}
