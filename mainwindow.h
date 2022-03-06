#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "partners.h"
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
    void on_pushButton_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_18_clicked();

    void on_pushButton_20_clicked();

    void on_pushButton_22_clicked();

    void on_pushButton_24_clicked();

    void on_toolButton_triggered(QAction *arg1);

    void on_toolButton_clicked();

    void on_pushButton_25_clicked();

    void on_pushButton_26_clicked();

    void on_pushButton_27_clicked();

    void on_pushButton_28_clicked();

    void on_pushButton_29_clicked();

    void on_pushButton_30_clicked();

    void on_pushButton_33_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_15_clicked();

    void on_add_clicked();

    void on_load_clicked();

    void on_supprimer_clicked();

    void on_id_dell_cursorPositionChanged(int arg1, int arg2);

    void on_update_2_clicked();

private:
    Ui::MainWindow *ui;
    PARTNERS p;
};
#endif // MAINWINDOW_H
