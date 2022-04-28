#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <agent.h>
#include <QMainWindow>
#include "login.h"
#include <QTcpSocket>
#include <QVariant>
#include <QMessageBox>
#include "buyer.h"
#include "subscriptions.h"
#include "partners.h"
#include "notification.h"
#include "sellers.h"
#include "property.h"
#include <QMediaPlayer>
#include <QVideoWidget>
#include "arduino.h"
#include "camera.h"
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
//properties
QMediaPlayer  * player= new QMediaPlayer ;

void closebutton();
void closebutton2();
void hmed();

private slots:
    //void on_stackedWidget_currentChanged(int arg1);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_3_clicked();

    //void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_comboBox_currentIndexChanged(int index);

    //void on_label_38_linkActivated(const QString &link);

    void on_pushButton_15_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton_17_clicked();

    //void on_pushButton_18_clicked();

    void on_lineEdit_cherche_textChanged(const QString &arg1);

    void on_lineEdit_cherche_cin_textChanged(const QString &arg1);

    void on_pushButton_connect_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_14_clicked();

    void on_logout_clicked();

    void on_lineEdit_cherche_number_textChanged(const QString &arg1);

    //void on_photo_clicked();

    void on_chat_clicked();

    void on_pushButton_24_clicked();

    //void on_comboBox_2_activated(const QString &arg1);

    void on_combo_clicked();

    //void on_comboBox_2_currentIndexChanged(int index);

    void on_valider_clicked();

    void on_pushButton_delete_clicked();

    void on_update_clicked();

    void on_comboBox_buyer_3_currentIndexChanged(int index);

    void on_sort_name_buyer_clicked();

    void on_sort_request_buyer_clicked();

    void on_sort_adress_buyer_clicked();

    void on_sort_id_buyer_clicked();

    void on_chercher_id_textChanged(const QString &arg1);

    void on_chercher_name_textChanged(const QString &arg1);

    void on_chercher_request_textChanged(const QString &arg1);

    void on_mailling_clicked();

    void on_inserer_photo_clicked();

    void on_recommand_clicked();

    //void on_pushButton_23_clicked();

   // void on_delete_agent_clicked();

    void on_pushButton_23_clicked();

    void on_photo_2_clicked();

    void on_add_ag_clicked();

   // void on_label_78_linkActivated(const QString &link);

    void on_pb_add_2_clicked();

    void on_pushButton_20_clicked();

    void on_pd_update_2_clicked();

    void on_comboBox_5_currentIndexChanged(const QString &arg1);

    void on_comboBox_5_currentIndexChanged(int index);

    void on_pb_delete_2_clicked();

    //void on_searchnum_2_clicked();

   // void on_searchType_2_clicked();

    //void on_searchStartDate_2_clicked();

    void on_numtosearch_2_textChanged(const QString &arg1);

    void on_typetosearch_2_textChanged(const QString &arg1);

    void on_startdatetosearch_2_textChanged(const QString &arg1);

    void on_sortById_2_clicked();

    void on_sortByType_2_clicked();

    void on_sortByPrice_2_clicked();

    void on_pb_read_2_clicked();

    void on_tabWidget_3_currentChanged(int index);

    void on_pb_history_2_clicked();

    void on_pbExport_2_clicked();

    void on_pushButton_19_clicked();

    void on_add_2_clicked();

   // void on_idbox_2_currentIndexChanged(int index);

    void on_pushButton_42_clicked();

    void on_update_3_clicked();

    void on_supprimer_2_clicked();

    void on_sort_par_clicked();

    void on_sort_par_2_clicked();

    void on_sort_par_3_clicked();

    void on_chercher_4_textChanged(const QString &arg1);

    void on_chercher_5_textChanged(const QString &arg1);

    void on_tri_stock_7_clicked();

    //void on_tri_stock_9_clicked();

    void on_tri_stock_8_clicked();

    void on_ig_2_clicked();

    void on_fb_2_clicked();

    void on_linkedin_2_clicked();

    void on_tri_stock_9_clicked();

    void on_tri_stock_10_clicked();

    void on_pushButton_18_clicked();

    void on_pb_Add_clicked();

    void on_pb_supp_clicked();

    void on_comboBox_agent_currentIndexChanged(int index);

    void on_pb_modif_clicked();

    void on_Sort_by_id_clicked();

    void on_Sort_by_name_clicked();

    void on_Sort_by_adress_clicked();

    void on_search_id_2_textChanged(const QString &arg1);

    void on_search_name_2_textChanged(const QString &arg1);

    void on_search_adress_2_textChanged(const QString &arg1);

    void on_todo_clicked();

    void on_generer_pdf_clicked();

    void on_pushButton_database_insert_clicked();

    void on_pushButton_21_clicked();

    void on_pushButton_29_clicked();

    void on_pushButton_30_clicked();

    void on_update_prop_clicked();

    void on_comboBox_7_currentIndexChanged(int index);

    void on_pushButton_delete_prop_clicked();

    void on_tableView_2_prop_clicked(const QModelIndex &index);

    void on_pushButton_31_clicked();

    void on_pushButton_32_clicked();

    void on_pushButton_33_clicked();

    void on_pushButton_34_clicked();

    void on_pushButton_35_clicked();

    void on_pushButton_36_clicked();

    void on_lineEdit_cherche_function_textChanged(const QString &arg1);

    void on_lineEdit_cherche_function_textEdited(const QString &arg1);

    void on_chat_2_clicked();

    void on_pushButton_security_arduino_clicked();

    void on_pushButton_27_clicked();

    void on_pushButton_security_arduino_2_clicked();

    void on_pushButton_28_clicked();
    void update_label();   // slot permettant la mise à jour du label état de la lampe 1,
    // ce slot est lancé à chaque réception d'un message de Arduino

    void on_pushButton_arduino_clicked();

private:
 Ui::MainWindow *ui;
    agent a;
    QTcpSocket*mSocket;
    buyer b;
    Seller S;
    //subscriptions Sub;
    PARTNERS p;
Notification n;
//Property P;
QPushButton *player_button;
QVideoWidget videoWidget ;
QMediaPlayer  video_player;
QByteArray data; // variable contenant les données reçues

Arduino A; // objet temporaire
 Camera camera;
};
#endif // MAINWINDOW_H
