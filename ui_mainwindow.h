/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QLabel *label;
    QPushButton *valider;
    QPushButton *inserer_photo;
    QLabel *label_19;
    QLineEdit *lineEdit_mail;
    QLabel *label_14;
    QLabel *label_3;
    QLabel *label_55;
    QLineEdit *lineEdit_request;
    QLineEdit *lineEdit_adress;
    QLabel *label_5;
    QLineEdit *lineEdit_name;
    QLineEdit *lineEdit_num;
    QLineEdit *lineEdit_lastname;
    QLabel *label_52;
    QLabel *label_2;
    QLabel *label_4;
    QLineEdit *lineEdit_id;
    QLabel *label_6;
    QComboBox *comboBox_2;
    QWidget *tab_2;
    QTableView *tab_produit;
    QPushButton *trier;
    QPushButton *tri_stock;
    QPushButton *trier_2;
    QPushButton *rechercher_2;
    QLabel *label_22;
    QLineEdit *chercher_id;
    QLabel *label_23;
    QLineEdit *chercher_name;
    QPushButton *rechercher_3;
    QLabel *label_24;
    QLineEdit *chercher_request;
    QPushButton *rechercher_4;
    QPushButton *sort_id;
    QLabel *label_8;
    QLineEdit *update_name;
    QLineEdit *update_mail;
    QLineEdit *update_num;
    QLabel *label_12;
    QLineEdit *update_lastname;
    QLabel *label_20;
    QLabel *label_21;
    QLabel *label_10;
    QLineEdit *update_adress;
    QLabel *label_11;
    QLabel *label_9;
    QLineEdit *update_request;
    QLabel *label_13;
    QPushButton *read;
    QPushButton *pushButton_delete;
    QLineEdit *lineEdit_del;
    QLineEdit *update_id;
    QPushButton *pushButton_2;
    QComboBox *comboBox;
    QPushButton *pushButton_3;
    QPushButton *mailling;
    QTableView *tableView2;
    QLabel *label_7;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1337, 672);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(10, 0, 1391, 641));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        label = new QLabel(tab);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(340, 20, 281, 20));
        QFont font;
        font.setPointSize(14);
        label->setFont(font);
        label->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        valider = new QPushButton(tab);
        valider->setObjectName(QStringLiteral("valider"));
        valider->setGeometry(QRect(480, 390, 101, 31));
        valider->setStyleSheet(QLatin1String("QPushButton\n"
"{background-color: rgb(200,133,0);\n"
"color : white;\n"
"font: 10pt Arial;\n"
"            border-radius: 4px;\n"
"            text-shadow: 0 1px 1px rgba(0, 0, 0, 0.2);\n"
"border: 2px solid rgb(200,133,0);\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"border: 2px solid rgb(200,146,0);\n"
"background-color : rgb(200,149,47);\n"
"}"));
        inserer_photo = new QPushButton(tab);
        inserer_photo->setObjectName(QStringLiteral("inserer_photo"));
        inserer_photo->setGeometry(QRect(690, 390, 141, 31));
        inserer_photo->setStyleSheet(QLatin1String("QPushButton\n"
"{background-color: rgb(200,133,0);\n"
"color : white;\n"
"font: 10pt Arial;\n"
"            border-radius: 4px;\n"
"            text-shadow: 0 1px 1px rgba(0, 0, 0, 0.2);\n"
"border: 2px solid rgb(200,133,0);\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"border: 2px solid rgb(200,146,0);\n"
"background-color : rgb(200,149,47);\n"
"}"));
        label_19 = new QLabel(tab);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setGeometry(QRect(370, 150, 56, 16));
        QFont font1;
        font1.setPointSize(12);
        label_19->setFont(font1);
        label_19->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
""));
        lineEdit_mail = new QLineEdit(tab);
        lineEdit_mail->setObjectName(QStringLiteral("lineEdit_mail"));
        lineEdit_mail->setGeometry(QRect(530, 140, 171, 22));
        lineEdit_mail->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        label_14 = new QLabel(tab);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(-20, 0, 1211, 641));
        label_14->setPixmap(QPixmap(QString::fromUtf8("../../../Downloads/lovepik-financial-real-estate-black-gold-background-image_400084852.jpg")));
        label_3 = new QLabel(tab);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(50, 150, 102, 25));
        label_3->setFont(font1);
        label_3->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        label_55 = new QLabel(tab);
        label_55->setObjectName(QStringLiteral("label_55"));
        label_55->setGeometry(QRect(50, 372, 81, 25));
        label_55->setFont(font1);
        label_55->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        lineEdit_request = new QLineEdit(tab);
        lineEdit_request->setObjectName(QStringLiteral("lineEdit_request"));
        lineEdit_request->setGeometry(QRect(158, 373, 143, 22));
        lineEdit_request->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        lineEdit_adress = new QLineEdit(tab);
        lineEdit_adress->setObjectName(QStringLiteral("lineEdit_adress"));
        lineEdit_adress->setGeometry(QRect(158, 299, 143, 22));
        lineEdit_adress->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        label_5 = new QLabel(tab);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(50, 298, 91, 25));
        label_5->setFont(font1);
        label_5->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        lineEdit_name = new QLineEdit(tab);
        lineEdit_name->setObjectName(QStringLiteral("lineEdit_name"));
        lineEdit_name->setGeometry(QRect(158, 225, 143, 22));
        lineEdit_name->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        lineEdit_num = new QLineEdit(tab);
        lineEdit_num->setObjectName(QStringLiteral("lineEdit_num"));
        lineEdit_num->setGeometry(QRect(530, 80, 108, 22));
        lineEdit_num->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        lineEdit_lastname = new QLineEdit(tab);
        lineEdit_lastname->setObjectName(QStringLiteral("lineEdit_lastname"));
        lineEdit_lastname->setGeometry(QRect(158, 151, 143, 22));
        lineEdit_lastname->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        label_52 = new QLabel(tab);
        label_52->setObjectName(QStringLiteral("label_52"));
        label_52->setGeometry(QRect(370, 80, 171, 25));
        label_52->setFont(font1);
        label_52->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        label_2 = new QLabel(tab);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(50, 76, 31, 25));
        label_2->setFont(font1);
        label_2->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
""));
        label_4 = new QLabel(tab);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(50, 224, 67, 25));
        label_4->setFont(font1);
        label_4->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        lineEdit_id = new QLineEdit(tab);
        lineEdit_id->setObjectName(QStringLiteral("lineEdit_id"));
        lineEdit_id->setGeometry(QRect(158, 77, 143, 22));
        lineEdit_id->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        label_6 = new QLabel(tab);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(370, 230, 71, 21));
        label_6->setFont(font1);
        label_6->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        comboBox_2 = new QComboBox(tab);
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));
        comboBox_2->setGeometry(QRect(530, 220, 73, 22));
        comboBox_2->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        tabWidget->addTab(tab, QString());
        label_14->raise();
        label->raise();
        valider->raise();
        inserer_photo->raise();
        label_19->raise();
        lineEdit_mail->raise();
        label_3->raise();
        label_55->raise();
        lineEdit_request->raise();
        lineEdit_adress->raise();
        label_5->raise();
        lineEdit_name->raise();
        lineEdit_num->raise();
        lineEdit_lastname->raise();
        label_52->raise();
        label_2->raise();
        label_4->raise();
        lineEdit_id->raise();
        label_6->raise();
        comboBox_2->raise();
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        tab_produit = new QTableView(tab_2);
        tab_produit->setObjectName(QStringLiteral("tab_produit"));
        tab_produit->setGeometry(QRect(0, 0, 1061, 251));
        tab_produit->setStyleSheet(QLatin1String("QTableView {border: 3px solid #5E749C;text-align: top;padding: 4px;border-radius: 7px;border-bottom-left-radius: 7px;background: QLinearGradient( x1: 0, y1: 0, x2: 1, y2: 0,stop: 0 #fff, stop: 1 #eee,stop: 0.5 #ddd,stop: 1 #eee );width: 15px;}\n"
"QTableView::item:focus{selection-background-color: yellow;}\n"
"\n"
"\n"
" QScrollBar{\n"
"         background: QLinearGradient( x1: 0, y1: 0, x2: 1, y2: 0,stop: 0 #fff, stop: 1 #eee,stop: 0.5 #ddd,stop: 1 #eee );\n"
" }\n"
"\n"
" QScrollBar:vertical {\n"
"     border: 3px solid #5E749C;\n"
"     padding: 4px;\n"
"     border-radius: 7px;\n"
"     border-bottom-left-radius: 7px;\n"
"     background: QLinearGradient( x1: 0, y1: 0, x2: 1, y2: 0,stop: 0 #fff, stop: 1 #eee,stop: 0.5 #ddd,stop: 1 #eee );\n"
"     width: 45px;\n"
"     margin: 48px 0 48px 0;\n"
" }\n"
"\n"
" QScrollBar::handle:vertical {\n"
"     background: dark blue;\n"
"     border: 3px solid #5E749C;\n"
"     padding: 0px;\n"
"     border-radius: 7px;\n"
"     border-bottom-left-radius: 7px;\n"
"     m"
                        "in-height: 40px;\n"
" }\n"
" QScrollBar::add-line:vertical {\n"
"     background: dark blue;\n"
"     border: 3px solid #5E749C;\n"
"     padding: 0px;\n"
"     border-radius: 7px;\n"
"     border-bottom-left-radius: 7px;\n"
"     height: 40px;\n"
"     subcontrol-position: bottom;\n"
"     subcontrol-origin: margin;\n"
" }\n"
"\n"
" QScrollBar::sub-line:vertical {\n"
"     background: dark blue;\n"
"     border: 3px solid #5E749C;\n"
"     padding: 0px;\n"
"     border-radius: 7px;\n"
"     border-bottom-left-radius: 7px;\n"
"     height: 40px;\n"
"     subcontrol-position: top;\n"
"     subcontrol-origin: margin;\n"
" }\n"
" QScrollBar::up-arrow:vertical, QScrollBar::down-arrow:vertical {\n"
"     border: 2px solid grey;\n"
"     width: 3px;\n"
"     height: 3px;\n"
"     background: white;\n"
" }\n"
"\n"
" QScrollBar::add-page:vertical, QScrollBar::sub-page:vertical {\n"
"     background: none;\n"
" }\n"
"QHeaderView::section{\n"
"    background-color:rgb(90,90,90);\n"
"      color:rgb(200,200,200);\n"
"   "
                        " border:1px solid rgb(60,60,60);\n"
"    border-bottom:1px solid rgb(70,70,70);\n"
"    height:27px;\n"
"    min-width:55px;\n"
"}\n"
"QHeaderView::section:hover\n"
"{\n"
"    background-color:rgb(80,80,80);\n"
"\n"
"}\n"
"QTableView\n"
"{\n"
"	background: rgb(55,55,55);\n"
"}\n"
"QTableView{\n"
"    selection-background-color:rgb(255,0,0);\n"
"    background-color:rgb(50,50,50);\n"
"    border:1px solid rgb(70,70,70);\n"
"    color:rgb(200,200,200)\n"
"}\n"
"\n"
"QTableView::item\n"
"{\n"
"       border:1px solid rgb(65,65,65);\n"
"	color:rgb(200,200,200);\n"
"\n"
"}\n"
"QTableView::item:hover\n"
"{\n"
"    background-color: rgb(30,30,30);\n"
"    font: 75 9pt \"Microsoft YaHei\";\n"
"    color:rgb(31,163,246);\n"
"}\n"
"QTableView::item::selected\n"
"{\n"
"    background-color: rgb(30,30,30);\n"
"    font: 75 9pt \"Microsoft YaHei\";\n"
"    color:rgb(31,163,246);\n"
"}"));
        trier = new QPushButton(tab_2);
        trier->setObjectName(QStringLiteral("trier"));
        trier->setGeometry(QRect(160, 260, 141, 28));
        trier->setStyleSheet(QLatin1String("QPushButton\n"
"{background-color: rgb(200,133,0);\n"
"color : white;\n"
"font: 10pt Arial;\n"
"            border-radius: 4px;\n"
"            text-shadow: 0 1px 1px rgba(0, 0, 0, 0.2);\n"
"border: 2px solid rgb(200,133,0);\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"border: 2px solid rgb(200,146,0);\n"
"background-color : rgb(200,149,47);\n"
"}"));
        tri_stock = new QPushButton(tab_2);
        tri_stock->setObjectName(QStringLiteral("tri_stock"));
        tri_stock->setGeometry(QRect(20, 260, 121, 28));
        tri_stock->setStyleSheet(QLatin1String("QPushButton\n"
"{background-color: rgb(200,133,0);\n"
"color : white;\n"
"font: 10pt Arial;\n"
"            border-radius: 4px;\n"
"            text-shadow: 0 1px 1px rgba(0, 0, 0, 0.2);\n"
"border: 2px solid rgb(200,133,0);\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"border: 2px solid rgb(200,146,0);\n"
"background-color : rgb(200,149,47);\n"
"}"));
        trier_2 = new QPushButton(tab_2);
        trier_2->setObjectName(QStringLiteral("trier_2"));
        trier_2->setGeometry(QRect(320, 260, 131, 28));
        trier_2->setStyleSheet(QLatin1String("QPushButton\n"
"{background-color: rgb(200,133,0);\n"
"color : white;\n"
"font: 10pt Arial;\n"
"            border-radius: 4px;\n"
"            text-shadow: 0 1px 1px rgba(0, 0, 0, 0.2);\n"
"border: 2px solid rgb(200,133,0);\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"border: 2px solid rgb(200,146,0);\n"
"background-color : rgb(200,149,47);\n"
"}"));
        rechercher_2 = new QPushButton(tab_2);
        rechercher_2->setObjectName(QStringLiteral("rechercher_2"));
        rechercher_2->setGeometry(QRect(400, 320, 93, 28));
        rechercher_2->setStyleSheet(QLatin1String("QPushButton\n"
"{background-color: rgb(200,133,0);\n"
"color : white;\n"
"font: 10pt Arial;\n"
"            border-radius: 4px;\n"
"            text-shadow: 0 1px 1px rgba(0, 0, 0, 0.2);\n"
"border: 2px solid rgb(200,133,0);\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"border: 2px solid rgb(200,146,0);\n"
"background-color : rgb(200,149,47);\n"
"}"));
        label_22 = new QLabel(tab_2);
        label_22->setObjectName(QStringLiteral("label_22"));
        label_22->setGeometry(QRect(40, 320, 131, 20));
        label_22->setFont(font1);
        label_22->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        chercher_id = new QLineEdit(tab_2);
        chercher_id->setObjectName(QStringLiteral("chercher_id"));
        chercher_id->setGeometry(QRect(240, 320, 111, 22));
        chercher_id->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        label_23 = new QLabel(tab_2);
        label_23->setObjectName(QStringLiteral("label_23"));
        label_23->setGeometry(QRect(40, 370, 141, 20));
        label_23->setFont(font1);
        label_23->setStyleSheet(QLatin1String("\n"
"color: rgb(255, 255, 255);"));
        chercher_name = new QLineEdit(tab_2);
        chercher_name->setObjectName(QStringLiteral("chercher_name"));
        chercher_name->setGeometry(QRect(240, 370, 113, 22));
        chercher_name->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        rechercher_3 = new QPushButton(tab_2);
        rechercher_3->setObjectName(QStringLiteral("rechercher_3"));
        rechercher_3->setGeometry(QRect(400, 370, 93, 28));
        rechercher_3->setStyleSheet(QLatin1String("QPushButton\n"
"{background-color: rgb(200,133,0);\n"
"color : white;\n"
"font: 10pt Arial;\n"
"            border-radius: 4px;\n"
"            text-shadow: 0 1px 1px rgba(0, 0, 0, 0.2);\n"
"border: 2px solid rgb(200,133,0);\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"border: 2px solid rgb(200,146,0);\n"
"background-color : rgb(200,149,47);\n"
"}"));
        label_24 = new QLabel(tab_2);
        label_24->setObjectName(QStringLiteral("label_24"));
        label_24->setGeometry(QRect(40, 420, 181, 20));
        label_24->setFont(font1);
        label_24->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        chercher_request = new QLineEdit(tab_2);
        chercher_request->setObjectName(QStringLiteral("chercher_request"));
        chercher_request->setGeometry(QRect(240, 420, 113, 22));
        chercher_request->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
""));
        rechercher_4 = new QPushButton(tab_2);
        rechercher_4->setObjectName(QStringLiteral("rechercher_4"));
        rechercher_4->setGeometry(QRect(400, 420, 93, 28));
        rechercher_4->setStyleSheet(QLatin1String("QPushButton\n"
"{background-color: rgb(200,133,0);\n"
"color : white;\n"
"font: 10pt Arial;\n"
"            border-radius: 4px;\n"
"            text-shadow: 0 1px 1px rgba(0, 0, 0, 0.2);\n"
"border: 2px solid rgb(200,133,0);\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"border: 2px solid rgb(200,146,0);\n"
"background-color : rgb(200,149,47);\n"
"}"));
        sort_id = new QPushButton(tab_2);
        sort_id->setObjectName(QStringLiteral("sort_id"));
        sort_id->setGeometry(QRect(470, 260, 121, 31));
        sort_id->setStyleSheet(QLatin1String("QPushButton\n"
"{background-color: rgb(200,133,0);\n"
"color : white;\n"
"font: 10pt Arial;\n"
"            border-radius: 4px;\n"
"            text-shadow: 0 1px 1px rgba(0, 0, 0, 0.2);\n"
"border: 2px solid rgb(200,133,0);\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"border: 2px solid rgb(200,146,0);\n"
"background-color : rgb(200,149,47);\n"
"}"));
        label_8 = new QLabel(tab_2);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(640, 270, 56, 16));
        label_8->setFont(font1);
        label_8->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        update_name = new QLineEdit(tab_2);
        update_name->setObjectName(QStringLiteral("update_name"));
        update_name->setGeometry(QRect(800, 330, 231, 22));
        update_name->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        update_mail = new QLineEdit(tab_2);
        update_mail->setObjectName(QStringLiteral("update_mail"));
        update_mail->setGeometry(QRect(800, 460, 231, 22));
        update_mail->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        update_num = new QLineEdit(tab_2);
        update_num->setObjectName(QStringLiteral("update_num"));
        update_num->setGeometry(QRect(800, 420, 231, 22));
        update_num->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        label_12 = new QLabel(tab_2);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(640, 360, 71, 16));
        label_12->setFont(font1);
        label_12->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        update_lastname = new QLineEdit(tab_2);
        update_lastname->setObjectName(QStringLiteral("update_lastname"));
        update_lastname->setGeometry(QRect(800, 300, 231, 22));
        update_lastname->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        label_20 = new QLabel(tab_2);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setGeometry(QRect(640, 420, 161, 21));
        label_20->setFont(font1);
        label_20->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        label_21 = new QLabel(tab_2);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setGeometry(QRect(640, 460, 61, 16));
        label_21->setFont(font1);
        label_21->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        label_10 = new QLabel(tab_2);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(640, 300, 91, 21));
        label_10->setFont(font1);
        label_10->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        update_adress = new QLineEdit(tab_2);
        update_adress->setObjectName(QStringLiteral("update_adress"));
        update_adress->setGeometry(QRect(800, 360, 231, 22));
        update_adress->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        label_11 = new QLabel(tab_2);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(640, 390, 91, 21));
        label_11->setFont(font1);
        label_11->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        label_9 = new QLabel(tab_2);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(640, 330, 56, 16));
        label_9->setFont(font1);
        label_9->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        update_request = new QLineEdit(tab_2);
        update_request->setObjectName(QStringLiteral("update_request"));
        update_request->setGeometry(QRect(800, 390, 231, 22));
        update_request->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        label_13 = new QLabel(tab_2);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(-330, -100, 1681, 811));
        label_13->setPixmap(QPixmap(QString::fromUtf8("../../../Downloads/lovepik-financial-real-estate-black-gold-background-image_400084852.jpg")));
        label_13->setScaledContents(true);
        read = new QPushButton(tab_2);
        read->setObjectName(QStringLiteral("read"));
        read->setGeometry(QRect(1190, 440, 93, 28));
        read->setStyleSheet(QLatin1String("QPushButton\n"
"{background-color: rgb(200,133,0);\n"
"color : white;\n"
"font: 10pt Arial;\n"
"            border-radius: 4px;\n"
"            text-shadow: 0 1px 1px rgba(0, 0, 0, 0.2);\n"
"border: 2px solid rgb(200,133,0);\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"border: 2px solid rgb(200,146,0);\n"
"background-color : rgb(200,149,47);\n"
"}"));
        pushButton_delete = new QPushButton(tab_2);
        pushButton_delete->setObjectName(QStringLiteral("pushButton_delete"));
        pushButton_delete->setGeometry(QRect(230, 520, 93, 28));
        pushButton_delete->setStyleSheet(QLatin1String("QPushButton\n"
"{background-color: rgb(200,133,0);\n"
"color : white;\n"
"font: 10pt Arial;\n"
"            border-radius: 4px;\n"
"            text-shadow: 0 1px 1px rgba(0, 0, 0, 0.2);\n"
"border: 2px solid rgb(200,133,0);\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"border: 2px solid rgb(200,146,0);\n"
"background-color : rgb(200,149,47);\n"
"}"));
        lineEdit_del = new QLineEdit(tab_2);
        lineEdit_del->setObjectName(QStringLiteral("lineEdit_del"));
        lineEdit_del->setGeometry(QRect(90, 520, 113, 21));
        lineEdit_del->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        update_id = new QLineEdit(tab_2);
        update_id->setObjectName(QStringLiteral("update_id"));
        update_id->setGeometry(QRect(800, 270, 231, 22));
        update_id->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        pushButton_2 = new QPushButton(tab_2);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(900, 500, 93, 28));
        pushButton_2->setStyleSheet(QLatin1String("QPushButton\n"
"{background-color: rgb(200,133,0);\n"
"color : white;\n"
"font: 10pt Arial;\n"
"            border-radius: 4px;\n"
"            text-shadow: 0 1px 1px rgba(0, 0, 0, 0.2);\n"
"border: 2px solid rgb(200,133,0);\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"border: 2px solid rgb(200,146,0);\n"
"background-color : rgb(200,149,47);\n"
"}"));
        comboBox = new QComboBox(tab_2);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(860, 550, 73, 22));
        comboBox->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        pushButton_3 = new QPushButton(tab_2);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(950, 540, 93, 31));
        pushButton_3->setStyleSheet(QLatin1String("QPushButton\n"
"{background-color: rgb(200,133,0);\n"
"color : white;\n"
"font: 10pt Arial;\n"
"            border-radius: 4px;\n"
"            text-shadow: 0 1px 1px rgba(0, 0, 0, 0.2);\n"
"border: 2px solid rgb(200,133,0);\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"border: 2px solid rgb(200,146,0);\n"
"background-color : rgb(200,149,47);\n"
"}"));
        mailling = new QPushButton(tab_2);
        mailling->setObjectName(QStringLiteral("mailling"));
        mailling->setGeometry(QRect(1190, 350, 93, 28));
        mailling->setStyleSheet(QLatin1String("QPushButton\n"
"{background-color: rgb(200,133,0);\n"
"color : white;\n"
"font: 10pt Arial;\n"
"            border-radius: 4px;\n"
"            text-shadow: 0 1px 1px rgba(0, 0, 0, 0.2);\n"
"border: 2px solid rgb(200,133,0);\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"border: 2px solid rgb(200,146,0);\n"
"background-color : rgb(200,149,47);\n"
"}"));
        tableView2 = new QTableView(tab_2);
        tableView2->setObjectName(QStringLiteral("tableView2"));
        tableView2->setGeometry(QRect(1070, 40, 231, 201));
        tableView2->setStyleSheet(QLatin1String("QTableView {border: 3px solid #5E749C;text-align: top;padding: 4px;border-radius: 7px;border-bottom-left-radius: 7px;background: QLinearGradient( x1: 0, y1: 0, x2: 1, y2: 0,stop: 0 #fff, stop: 1 #eee,stop: 0.5 #ddd,stop: 1 #eee );width: 15px;}\n"
"QTableView::item:focus{selection-background-color: yellow;}\n"
"\n"
"\n"
" QScrollBar{\n"
"         background: QLinearGradient( x1: 0, y1: 0, x2: 1, y2: 0,stop: 0 #fff, stop: 1 #eee,stop: 0.5 #ddd,stop: 1 #eee );\n"
" }\n"
"\n"
" QScrollBar:vertical {\n"
"     border: 3px solid #5E749C;\n"
"     padding: 4px;\n"
"     border-radius: 7px;\n"
"     border-bottom-left-radius: 7px;\n"
"     background: QLinearGradient( x1: 0, y1: 0, x2: 1, y2: 0,stop: 0 #fff, stop: 1 #eee,stop: 0.5 #ddd,stop: 1 #eee );\n"
"     width: 45px;\n"
"     margin: 48px 0 48px 0;\n"
" }\n"
"\n"
" QScrollBar::handle:vertical {\n"
"     background: dark blue;\n"
"     border: 3px solid #5E749C;\n"
"     padding: 0px;\n"
"     border-radius: 7px;\n"
"     border-bottom-left-radius: 7px;\n"
"     m"
                        "in-height: 40px;\n"
" }\n"
" QScrollBar::add-line:vertical {\n"
"     background: dark blue;\n"
"     border: 3px solid #5E749C;\n"
"     padding: 0px;\n"
"     border-radius: 7px;\n"
"     border-bottom-left-radius: 7px;\n"
"     height: 40px;\n"
"     subcontrol-position: bottom;\n"
"     subcontrol-origin: margin;\n"
" }\n"
"\n"
" QScrollBar::sub-line:vertical {\n"
"     background: dark blue;\n"
"     border: 3px solid #5E749C;\n"
"     padding: 0px;\n"
"     border-radius: 7px;\n"
"     border-bottom-left-radius: 7px;\n"
"     height: 40px;\n"
"     subcontrol-position: top;\n"
"     subcontrol-origin: margin;\n"
" }\n"
" QScrollBar::up-arrow:vertical, QScrollBar::down-arrow:vertical {\n"
"     border: 2px solid grey;\n"
"     width: 3px;\n"
"     height: 3px;\n"
"     background: white;\n"
" }\n"
"\n"
" QScrollBar::add-page:vertical, QScrollBar::sub-page:vertical {\n"
"     background: none;\n"
" }\n"
"QHeaderView::section{\n"
"    background-color:rgb(90,90,90);\n"
"      color:rgb(200,200,200);\n"
"   "
                        " border:1px solid rgb(60,60,60);\n"
"    border-bottom:1px solid rgb(70,70,70);\n"
"    height:27px;\n"
"    min-width:55px;\n"
"}\n"
"QHeaderView::section:hover\n"
"{\n"
"    background-color:rgb(80,80,80);\n"
"\n"
"}\n"
"QTableView\n"
"{\n"
"	background: rgb(55,55,55);\n"
"}\n"
"QTableView{\n"
"    selection-background-color:rgb(255,0,0);\n"
"    background-color:rgb(50,50,50);\n"
"    border:1px solid rgb(70,70,70);\n"
"    color:rgb(200,200,200)\n"
"}\n"
"\n"
"QTableView::item\n"
"{\n"
"       border:1px solid rgb(65,65,65);\n"
"	color:rgb(200,200,200);\n"
"\n"
"}\n"
"QTableView::item:hover\n"
"{\n"
"    background-color: rgb(30,30,30);\n"
"    font: 75 9pt \"Microsoft YaHei\";\n"
"    color:rgb(31,163,246);\n"
"}\n"
"QTableView::item::selected\n"
"{\n"
"    background-color: rgb(30,30,30);\n"
"    font: 75 9pt \"Microsoft YaHei\";\n"
"    color:rgb(31,163,246);\n"
"}"));
        label_7 = new QLabel(tab_2);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(1100, 10, 181, 16));
        label_7->setFont(font1);
        label_7->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        tabWidget->addTab(tab_2, QString());
        label_13->raise();
        tab_produit->raise();
        trier->raise();
        tri_stock->raise();
        trier_2->raise();
        rechercher_2->raise();
        label_22->raise();
        chercher_id->raise();
        label_23->raise();
        chercher_name->raise();
        rechercher_3->raise();
        label_24->raise();
        chercher_request->raise();
        rechercher_4->raise();
        sort_id->raise();
        label_8->raise();
        update_name->raise();
        update_mail->raise();
        update_num->raise();
        label_12->raise();
        update_lastname->raise();
        label_20->raise();
        label_21->raise();
        label_10->raise();
        update_adress->raise();
        label_11->raise();
        label_9->raise();
        update_request->raise();
        read->raise();
        pushButton_delete->raise();
        lineEdit_del->raise();
        update_id->raise();
        pushButton_2->raise();
        comboBox->raise();
        pushButton_3->raise();
        mailling->raise();
        tableView2->raise();
        label_7->raise();
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1337, 26));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Gestion des Clients", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "Add buyer", Q_NULLPTR));
        valider->setText(QApplication::translate("MainWindow", "Add", Q_NULLPTR));
        inserer_photo->setText(QApplication::translate("MainWindow", "import request", Q_NULLPTR));
        label_19->setText(QApplication::translate("MainWindow", "Mail", Q_NULLPTR));
        label_14->setText(QString());
        label_3->setText(QApplication::translate("MainWindow", "Lastname", Q_NULLPTR));
        label_55->setText(QApplication::translate("MainWindow", "request", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "adress", Q_NULLPTR));
        label_52->setText(QApplication::translate("MainWindow", "Num telephone", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "ID", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "Name", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "ID_AG", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Add", Q_NULLPTR));
        trier->setText(QApplication::translate("MainWindow", "sort by requsest", Q_NULLPTR));
        tri_stock->setText(QApplication::translate("MainWindow", "sort by name", Q_NULLPTR));
        trier_2->setText(QApplication::translate("MainWindow", "sort by adress", Q_NULLPTR));
        rechercher_2->setText(QApplication::translate("MainWindow", "Search", Q_NULLPTR));
        label_22->setText(QApplication::translate("MainWindow", "ID to find", Q_NULLPTR));
        label_23->setText(QApplication::translate("MainWindow", "Name to find", Q_NULLPTR));
        rechercher_3->setText(QApplication::translate("MainWindow", "Search", Q_NULLPTR));
        label_24->setText(QApplication::translate("MainWindow", "request to find ", Q_NULLPTR));
        rechercher_4->setText(QApplication::translate("MainWindow", "Search", Q_NULLPTR));
        sort_id->setText(QApplication::translate("MainWindow", "sort by id", Q_NULLPTR));
        label_8->setText(QApplication::translate("MainWindow", "ID", Q_NULLPTR));
        label_12->setText(QApplication::translate("MainWindow", "Adress", Q_NULLPTR));
        label_20->setText(QApplication::translate("MainWindow", "Num telephone", Q_NULLPTR));
        label_21->setText(QApplication::translate("MainWindow", "Mail", Q_NULLPTR));
        label_10->setText(QApplication::translate("MainWindow", "Lastname", Q_NULLPTR));
        label_11->setText(QApplication::translate("MainWindow", "Request", Q_NULLPTR));
        label_9->setText(QApplication::translate("MainWindow", "Name", Q_NULLPTR));
        label_13->setText(QString());
        read->setText(QApplication::translate("MainWindow", "Read", Q_NULLPTR));
        pushButton_delete->setText(QApplication::translate("MainWindow", "delete", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("MainWindow", "Update", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("MainWindow", "Read Info", Q_NULLPTR));
        mailling->setText(QApplication::translate("MainWindow", "Mailling", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainWindow", "Recommandation", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Read", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
