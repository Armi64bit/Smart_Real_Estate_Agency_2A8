#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "buyer.h"
#include <QMainWindow>
#include "arduino.h"
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
    void on_pushButton_clicked();

    void on_valider_clicked();

    void on_tab_produit_activated(const QModelIndex &index);

    void on_read_clicked();

    void on_supprimer_clicked();

    void on_lineEdit_3_cursorPositionChanged(int arg1, int arg2);





    void on_pushButton_delete_clicked();

    void on_pushButton_show_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_comboBox_currentIndexChanged(const QString &arg1);

    void on_comboBox_currentIndexChanged(int index);

    void on_tri_stock_clicked();

    void on_trier_clicked();

    void on_trier_2_clicked();

    void on_rechercher_2_clicked();

    void on_rechercher_3_clicked();

    void on_rechercher_4_clicked();

    void on_sort_id_clicked();

    void on_rechercher_2_windowIconTextChanged(const QString &iconText);

    void on_chercher_id_textChanged(const QString &arg1);

    void on_chercher_name_windowIconTextChanged(const QString &iconText);

    void on_chercher_name_textChanged(const QString &arg1);

    void on_chercher_request_textChanged(const QString &arg1);

    void on_mailling_clicked();

    void on_inserer_photo_clicked();

    void on_Qrcode_clicked();

    void on_recommand_clicked();
 void read_serial();

private:
    Ui::MainWindow *ui;
    buyer b;
    QByteArray data; // variable contenant les données reçues
arduino A;
    //Arduino A;
    Notification n;
};

#endif // MAINWINDOW_H
