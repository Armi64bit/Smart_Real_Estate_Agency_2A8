#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include "sellers.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pb_Add_clicked();

    void on_pushButton_clicked();

    void on_pb_read_clicked();

    void on_pb_supp_clicked();

    void on_pb_modif_clicked();

    void on_comboBox_currentIndexChanged(int index);

private:
    Ui::MainWindow *ui;
    Seller S;
};

#endif // MAINWINDOW_H
