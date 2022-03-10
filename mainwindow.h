#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QApplication>

#include <QMediaPlayer>
#include <QVideoWidget>
#include <QtSql>
#include <QtSql>
#include <QtSql/QtSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QMessageBox>
#include <QtNetwork>
#include <QStackedWidget>

#include "map.h"
#include "markermodel.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QMediaPlayer  * player= new QMediaPlayer ;
    QVideoWidget* vw=new QVideoWidget ;


private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_Show_prop_button_clicked();

    void on_pushButton_3_toggled(bool checked);

    void on_pushButton_4_databaseprop_clicked();

    void on_pushButton_database_insert_clicked();

    void on_pushButton_4_clicked();



    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_comboBox_currentIndexChanged(int index);

    void on_comboBox_currentIndexChanged(const QString &arg1);

    void on_pushButton_7_clicked();

private:
    Ui::MainWindow *ui;


};
#endif // MAINWINDOW_H
