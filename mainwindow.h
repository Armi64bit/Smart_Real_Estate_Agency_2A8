#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "subscriptions.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pb_add_clicked();

    void on_pb_delete_clicked();

    void on_comboBox_currentIndexChanged(int index);

    void on_pd_update_clicked();

    void on_comboBox_2_currentIndexChanged(int index);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
