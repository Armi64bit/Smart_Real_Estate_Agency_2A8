#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <agent.h>
#include <QMainWindow>
#include "login.h"
#include <QTcpSocket>
#include <QVariant>
#include <QMessageBox>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
Ui::MainWindow *Myui;
   //QString login;

void closebutton();

void hmed();

private slots:
    void on_stackedWidget_currentChanged(int arg1);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_comboBox_currentIndexChanged(int index);

    void on_label_38_linkActivated(const QString &link);

    void on_pushButton_15_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton_17_clicked();

    void on_pushButton_18_clicked();

    void on_lineEdit_cherche_textChanged(const QString &arg1);

    void on_lineEdit_cherche_cin_textChanged(const QString &arg1);

    void on_pushButton_connect_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_14_clicked();

    void on_logout_clicked();

    void on_lineEdit_cherche_number_textChanged(const QString &arg1);

    void on_photo_clicked();

    void on_chat_clicked();

    void on_pushButton_24_clicked();

    void on_comboBox_2_activated(const QString &arg1);

    void on_combo_clicked();

    void on_comboBox_2_currentIndexChanged(int index);

private:
 Ui::MainWindow *ui;
    agent a;
    QTcpSocket*mSocket;

};
#endif // MAINWINDOW_H
