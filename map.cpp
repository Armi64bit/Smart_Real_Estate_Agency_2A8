#include "map.h"
#include "ui_map.h"
#include "markermodel.h"
#include <QQuickItem>
#include <QApplication>

#include <QMediaPlayer>
#include <QVideoWidget>
#include <QtSql>
#include <QtSql/QtSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QQmlApplicationEngine>
#include <QGuiApplication>
#include <QMetaObject>
map::map(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::map)
{
    ui->setupUi(this);
  //ui->quickWidget->setSource(QUrl(QStringLiteral("qrc:/map.qml")));


    //ui->map->addWidget(container);



   /* auto obj = ui->quickWidget->rootObject();

   // connect(this,SIGNAL(addMarker(QVariant,QVariant)),obj,SLOT(addMarker(QVariant,QVariant)));
   QQmlProperty(obj, "oldlat").write(36);
    QQmlProperty(obj, "oldlng").write(10);
// emit addMarker(36,10);

//marker
   // QQuickWidget w;*/


}

map::~map()
{
    delete ui;
}
