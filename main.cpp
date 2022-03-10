#include "mainwindow.h"
#include "markermodel.h"
#include <QApplication>

#include <QMediaPlayer>
#include <QVideoWidget>
#include <QtSql>
#include <QtSql/QtSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QFile>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QFile styleSheetFile("Incrypt.qss");
    styleSheetFile.open(QFile::ReadOnly);
    QString styleSheet= QLatin1String(styleSheetFile.readAll());
    a.setStyleSheet(styleSheet);
    MainWindow w;






w.show();


///////////////


    return a.exec();
}
