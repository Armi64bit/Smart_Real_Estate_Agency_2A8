#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include "sellers.h"
#include "notification.h"
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

    void on_Sort_by_name_clicked();

    void on_Sort_by_id_clicked();

    void on_Sort_by_adress_clicked();

    void on_search_id_clicked();

    void on_search_name_clicked();

    void on_search_adress_clicked();

    void on_search_id_windowIconTextChanged(const QString &iconText);

    void on_search_id_2_textChanged(const QString &arg1);

    void on_search_name_2_textChanged(const QString &arg1);

    void on_search_adress_2_textChanged(const QString &arg1);

    void on_generatepdf_clicked();

private:
    Ui::MainWindow *ui;
    Seller S;
    Notification n;
    // Pour faire appel a la methode supp()
};

#endif // MAINWINDOW_H
