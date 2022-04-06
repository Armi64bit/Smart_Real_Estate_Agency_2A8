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
#include "arduino.h"
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
   void showmap();
   void update_label();   // slot permettant la mise à jour du label état de la lampe 1,
   // ce slot est lancé à chaque réception d'un message de Arduino
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

    void on_pushButton_11_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_14_clicked();

    void MapButton();

    void on_tableView_2_clicked(const QModelIndex &index);

    void pause_button();

    void on_pushButton_18_clicked();

    void on_pushButton_19_clicked();

    void on_pushButton_22_clicked();

private:
    Ui::MainWindow *ui;
    QPushButton *m_button;
    QPushButton *player_button;
    QVideoWidget videoWidget ;

    QByteArray data; // variable contenant les données reçues

    Arduino A; // objet temporaire
};


#endif // MAINWINDOW_H
