#ifndef LOGIN_H
#define LOGIN_H
#include "mainwindow.h"
#include <QDialog>
#include <QSqlDatabase>
#include <QMainWindow>
namespace Ui {
class login;
}

class login : public QDialog
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = nullptr);
    ~login();

private slots:
    void on_login_2_clicked();

private:
    Ui::login *ui;
    QSqlDatabase db;

};

#endif // LOGIN_H
