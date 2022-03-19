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

  //  void on_comboBox_2_currentIndexChanged(int index);

  //  void on_tri_stock_clicked();

    void on_sortById_clicked();

    void on_sortByType_clicked();

    void on_sortByPrice_clicked();

//    void on_searchId_windowIconTextChanged(const QString &iconText);

 //   void on_idtosearch_textChanged(const QString &arg1);

    void on_typetosearch_textChanged(const QString &arg1);

    void on_startdatetosearch_textChanged(const QString &arg1);

    void on_numtosearch_textChanged(const QString &arg1);

    void on_pb_read_clicked();

    void on_searchnum_clicked();

    void on_searchType_clicked();

    void on_searchStartDate_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
