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
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionPlay;
    QWidget *centralwidget;
    QTabWidget *tabWidget_2;
    QWidget *tab_3;
    QFrame *frame;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QPushButton *pushButton_4_databaseprop;
    QPushButton *pushButton;
    QPushButton *pushButton_3;
    QPushButton *pushButton_2;
    QPushButton *pushButton_4;
    QPushButton *pushButton_18;
    QPushButton *pushButton_19;
    QPushButton *pushButton_20;
    QPushButton *pushButton_21;
    QWidget *page_2;
    QWidget *tab_4;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLabel *label_3;
    QLineEdit *lineEdit_longitude_prop;
    QLineEdit *lineEdit_price_pro;
    QLabel *label_4;
    QLabel *label_5;
    QLineEdit *lineEdit_latitude_prop;
    QLineEdit *lineEdit_Id_prop;
    QLineEdit *lineEdit_Type_prop;
    QLabel *label_2;
    QLabel *label;
    QPushButton *pushButton_22;
    QLineEdit *lineEdit;
    QPushButton *pushButton_database_insert;
    QTableView *tableView_2;
    QPushButton *pushButton_6;
    QLineEdit *lineEdit_delete_prop;
    QComboBox *comboBox;
    QPushButton *pushButton_7;
    QComboBox *comboBox_2;
    QComboBox *comboBox_3;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLineEdit *lineEdit_find_id_prop;
    QLineEdit *lineEdit_find_type_prop;
    QLineEdit *lineEdit_find_price_prop;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QPushButton *pushButton_10;
    QPushButton *pushButton_11;
    QPushButton *pushButton_12;
    QPushButton *pushButton_13;
    QPlainTextEdit *plainTextEdit;
    QLabel *label_12;
    QPushButton *pushButton_5;
    QWidget *tab;
    QGroupBox *groupBox_2;
    QLabel *label_6;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QPushButton *pushButton_16;
    QPushButton *pushButton_17;
    QStackedWidget *stackedWidget_2;
    QWidget *page_5;
    QWidget *page_6;
    QMenuBar *menubar;
    QMenu *menuProperty_Management;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(994, 670);
        actionPlay = new QAction(MainWindow);
        actionPlay->setObjectName(QStringLiteral("actionPlay"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/new/prefix1/audio_02.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        actionPlay->setIcon(icon);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        tabWidget_2 = new QTabWidget(centralwidget);
        tabWidget_2->setObjectName(QStringLiteral("tabWidget_2"));
        tabWidget_2->setGeometry(QRect(10, 20, 961, 631));
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        frame = new QFrame(tab_3);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(40, 310, 120, 80));
        frame->setStyleSheet(QStringLiteral("background-image: url(C:/Users/Souid/Downloads/Qtvideo.mp4);"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        stackedWidget = new QStackedWidget(tab_3);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(0, 0, 831, 561));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        pushButton_4_databaseprop = new QPushButton(page);
        pushButton_4_databaseprop->setObjectName(QStringLiteral("pushButton_4_databaseprop"));
        pushButton_4_databaseprop->setGeometry(QRect(630, 470, 181, 23));
        pushButton_4_databaseprop->setStyleSheet(QLatin1String("QPushButton\n"
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
        pushButton = new QPushButton(page);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(560, 140, 75, 23));
        pushButton->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        pushButton_3 = new QPushButton(page);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(230, 200, 150, 36));
        pushButton_3->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_3->setStyleSheet(QStringLiteral(""));
        pushButton_2 = new QPushButton(page);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(560, 170, 75, 23));
        pushButton_2->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        pushButton_4 = new QPushButton(page);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(560, 290, 75, 23));
        pushButton_4->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        pushButton_18 = new QPushButton(page);
        pushButton_18->setObjectName(QStringLiteral("pushButton_18"));
        pushButton_18->setGeometry(QRect(100, 390, 75, 23));
        pushButton_19 = new QPushButton(page);
        pushButton_19->setObjectName(QStringLiteral("pushButton_19"));
        pushButton_19->setGeometry(QRect(220, 390, 75, 23));
        pushButton_20 = new QPushButton(page);
        pushButton_20->setObjectName(QStringLiteral("pushButton_20"));
        pushButton_20->setGeometry(QRect(100, 450, 75, 23));
        pushButton_21 = new QPushButton(page);
        pushButton_21->setObjectName(QStringLiteral("pushButton_21"));
        pushButton_21->setGeometry(QRect(230, 450, 75, 23));
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        stackedWidget->addWidget(page_2);
        tabWidget_2->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        groupBox = new QGroupBox(tab_4);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(20, 200, 331, 301));
        groupBox->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        lineEdit_longitude_prop = new QLineEdit(groupBox);
        lineEdit_longitude_prop->setObjectName(QStringLiteral("lineEdit_longitude_prop"));
        lineEdit_longitude_prop->setStyleSheet(QStringLiteral("color : rgb(255, 255, 255) ;"));

        gridLayout->addWidget(lineEdit_longitude_prop, 4, 1, 1, 1);

        lineEdit_price_pro = new QLineEdit(groupBox);
        lineEdit_price_pro->setObjectName(QStringLiteral("lineEdit_price_pro"));
        lineEdit_price_pro->setStyleSheet(QStringLiteral("color : rgb(255, 255, 255) ;"));

        gridLayout->addWidget(lineEdit_price_pro, 2, 1, 1, 1);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 4, 0, 1, 1);

        lineEdit_latitude_prop = new QLineEdit(groupBox);
        lineEdit_latitude_prop->setObjectName(QStringLiteral("lineEdit_latitude_prop"));
        lineEdit_latitude_prop->setStyleSheet(QStringLiteral("color : rgb(255, 255, 255) ;"));

        gridLayout->addWidget(lineEdit_latitude_prop, 3, 1, 1, 1);

        lineEdit_Id_prop = new QLineEdit(groupBox);
        lineEdit_Id_prop->setObjectName(QStringLiteral("lineEdit_Id_prop"));
        lineEdit_Id_prop->setStyleSheet(QStringLiteral("color : rgb(255, 255, 255) ;"));

        gridLayout->addWidget(lineEdit_Id_prop, 0, 1, 1, 1);

        lineEdit_Type_prop = new QLineEdit(groupBox);
        lineEdit_Type_prop->setObjectName(QStringLiteral("lineEdit_Type_prop"));
        lineEdit_Type_prop->setStyleSheet(QStringLiteral("color : rgb(255, 255, 255) ;"));

        gridLayout->addWidget(lineEdit_Type_prop, 1, 1, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        pushButton_22 = new QPushButton(groupBox);
        pushButton_22->setObjectName(QStringLiteral("pushButton_22"));

        gridLayout->addWidget(pushButton_22, 5, 0, 1, 1);

        lineEdit = new QLineEdit(groupBox);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        gridLayout->addWidget(lineEdit, 5, 1, 1, 1);

        pushButton_database_insert = new QPushButton(tab_4);
        pushButton_database_insert->setObjectName(QStringLiteral("pushButton_database_insert"));
        pushButton_database_insert->setGeometry(QRect(0, 520, 191, 23));
        pushButton_database_insert->setStyleSheet(QLatin1String("QPushButton\n"
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
        tableView_2 = new QTableView(tab_4);
        tableView_2->setObjectName(QStringLiteral("tableView_2"));
        tableView_2->setGeometry(QRect(0, 0, 831, 192));
        tableView_2->setStyleSheet(QLatin1String("QTableView {border: 3px solid #5E749C;text-align: top;padding: 4px;border-radius: 7px;border-bottom-left-radius: 7px;background: QLinearGradient( x1: 0, y1: 0, x2: 1, y2: 0,stop: 0 #fff, stop: 1 #eee,stop: 0.5 #ddd,stop: 1 #eee );width: 15px;}\n"
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
" }"));
        pushButton_6 = new QPushButton(tab_4);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(630, 510, 116, 23));
        pushButton_6->setStyleSheet(QLatin1String("QPushButton\n"
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
        lineEdit_delete_prop = new QLineEdit(tab_4);
        lineEdit_delete_prop->setObjectName(QStringLiteral("lineEdit_delete_prop"));
        lineEdit_delete_prop->setGeometry(QRect(750, 510, 116, 20));
        lineEdit_delete_prop->setStyleSheet(QStringLiteral("color : rgb(255, 255, 255) ;"));
        comboBox = new QComboBox(tab_4);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(360, 520, 71, 31));
        comboBox->setStyleSheet(QStringLiteral("color : rgb(255, 255, 255) ;"));
        pushButton_7 = new QPushButton(tab_4);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setGeometry(QRect(240, 520, 111, 23));
        pushButton_7->setStyleSheet(QLatin1String("QPushButton\n"
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
        comboBox_2 = new QComboBox(tab_4);
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));
        comboBox_2->setGeometry(QRect(420, 210, 62, 22));
        comboBox_2->setStyleSheet(QStringLiteral("color : rgb(255, 255, 255) ;"));
        comboBox_3 = new QComboBox(tab_4);
        comboBox_3->setObjectName(QStringLiteral("comboBox_3"));
        comboBox_3->setGeometry(QRect(420, 240, 62, 22));
        comboBox_3->setStyleSheet(QStringLiteral("color : rgb(255, 255, 255) ;"));
        label_7 = new QLabel(tab_4);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(370, 210, 47, 14));
        label_7->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        label_8 = new QLabel(tab_4);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(370, 240, 47, 14));
        label_8->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        label_9 = new QLabel(tab_4);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(500, 200, 141, 41));
        label_9->setStyleSheet(QStringLiteral("color : rgb(255, 255, 255) ;"));
        label_10 = new QLabel(tab_4);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(500, 240, 141, 41));
        label_10->setStyleSheet(QStringLiteral("color : rgb(255, 255, 255) ;"));
        label_11 = new QLabel(tab_4);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(500, 280, 151, 41));
        label_11->setStyleSheet(QStringLiteral("color : rgb(255, 255, 255) ;"));
        lineEdit_find_id_prop = new QLineEdit(tab_4);
        lineEdit_find_id_prop->setObjectName(QStringLiteral("lineEdit_find_id_prop"));
        lineEdit_find_id_prop->setGeometry(QRect(700, 210, 111, 31));
        lineEdit_find_type_prop = new QLineEdit(tab_4);
        lineEdit_find_type_prop->setObjectName(QStringLiteral("lineEdit_find_type_prop"));
        lineEdit_find_type_prop->setGeometry(QRect(700, 250, 111, 31));
        lineEdit_find_price_prop = new QLineEdit(tab_4);
        lineEdit_find_price_prop->setObjectName(QStringLiteral("lineEdit_find_price_prop"));
        lineEdit_find_price_prop->setGeometry(QRect(700, 290, 111, 31));
        pushButton_8 = new QPushButton(tab_4);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        pushButton_8->setGeometry(QRect(850, 210, 75, 23));
        pushButton_8->setStyleSheet(QLatin1String("QPushButton\n"
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
        pushButton_9 = new QPushButton(tab_4);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));
        pushButton_9->setGeometry(QRect(850, 250, 75, 23));
        pushButton_9->setStyleSheet(QLatin1String("QPushButton\n"
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
        pushButton_10 = new QPushButton(tab_4);
        pushButton_10->setObjectName(QStringLiteral("pushButton_10"));
        pushButton_10->setGeometry(QRect(850, 290, 75, 23));
        pushButton_10->setStyleSheet(QLatin1String("QPushButton\n"
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
        pushButton_11 = new QPushButton(tab_4);
        pushButton_11->setObjectName(QStringLiteral("pushButton_11"));
        pushButton_11->setGeometry(QRect(850, 30, 81, 23));
        pushButton_11->setStyleSheet(QLatin1String("QPushButton\n"
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
        pushButton_12 = new QPushButton(tab_4);
        pushButton_12->setObjectName(QStringLiteral("pushButton_12"));
        pushButton_12->setGeometry(QRect(850, 70, 81, 23));
        pushButton_12->setStyleSheet(QLatin1String("QPushButton\n"
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
        pushButton_13 = new QPushButton(tab_4);
        pushButton_13->setObjectName(QStringLiteral("pushButton_13"));
        pushButton_13->setGeometry(QRect(850, 110, 81, 23));
        pushButton_13->setStyleSheet(QLatin1String("QPushButton\n"
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
        plainTextEdit = new QPlainTextEdit(tab_4);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));
        plainTextEdit->setGeometry(QRect(520, 340, 431, 141));
        label_12 = new QLabel(tab_4);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(370, 390, 151, 41));
        label_12->setStyleSheet(QStringLiteral("color : rgb(255, 255, 255) ;"));
        pushButton_5 = new QPushButton(tab_4);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(380, 300, 75, 23));
        pushButton_5->setStyleSheet(QLatin1String("QPushButton\n"
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
        tabWidget_2->addTab(tab_4, QString());
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        groupBox_2 = new QGroupBox(tab);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(0, 10, 361, 361));
        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(20, 40, 47, 14));
        scrollArea = new QScrollArea(groupBox_2);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setGeometry(QRect(80, 70, 201, 261));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 199, 259));
        scrollArea->setWidget(scrollAreaWidgetContents);
        pushButton_16 = new QPushButton(tab);
        pushButton_16->setObjectName(QStringLiteral("pushButton_16"));
        pushButton_16->setGeometry(QRect(630, 440, 50, 42));
        pushButton_16->setStyleSheet(QLatin1String("QPushButton \n"
"{\n"
"url(:/new/prefix1/audio_02.jpg)\n"
"}"));
        pushButton_17 = new QPushButton(tab);
        pushButton_17->setObjectName(QStringLiteral("pushButton_17"));
        pushButton_17->setGeometry(QRect(720, 440, 50, 42));
        pushButton_17->setStyleSheet(QStringLiteral(""));
        stackedWidget_2 = new QStackedWidget(tab);
        stackedWidget_2->setObjectName(QStringLiteral("stackedWidget_2"));
        stackedWidget_2->setGeometry(QRect(690, 60, 120, 80));
        page_5 = new QWidget();
        page_5->setObjectName(QStringLiteral("page_5"));
        stackedWidget_2->addWidget(page_5);
        page_6 = new QWidget();
        page_6->setObjectName(QStringLiteral("page_6"));
        stackedWidget_2->addWidget(page_6);
        tabWidget_2->addTab(tab, QString());
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 994, 22));
        menuProperty_Management = new QMenu(menubar);
        menuProperty_Management->setObjectName(QStringLiteral("menuProperty_Management"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuProperty_Management->menuAction());
        menuProperty_Management->addAction(actionPlay);
        menuProperty_Management->addSeparator();

        retranslateUi(MainWindow);

        tabWidget_2->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        actionPlay->setText(QApplication::translate("MainWindow", "Play", Q_NULLPTR));
        pushButton_4_databaseprop->setText(QApplication::translate("MainWindow", "DatabaseConnectionProp", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "valider", Q_NULLPTR));
        pushButton_3->setText(QString());
        pushButton_2->setText(QApplication::translate("MainWindow", "quitter", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("MainWindow", "map", Q_NULLPTR));
        pushButton_18->setText(QApplication::translate("MainWindow", "arduino1", Q_NULLPTR));
        pushButton_19->setText(QApplication::translate("MainWindow", "arduino2", Q_NULLPTR));
        pushButton_20->setText(QApplication::translate("MainWindow", "arduino3", Q_NULLPTR));
        pushButton_21->setText(QApplication::translate("MainWindow", "arduino4", Q_NULLPTR));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_3), QApplication::translate("MainWindow", "Show Property", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("MainWindow", "Property ", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "Property price", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "longitude", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "latitude", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "Property Type", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "Id_maison", Q_NULLPTR));
        pushButton_22->setText(QApplication::translate("MainWindow", "addvideopath", Q_NULLPTR));
        pushButton_database_insert->setText(QApplication::translate("MainWindow", "InsertingtoDatabase", Q_NULLPTR));
        pushButton_6->setText(QApplication::translate("MainWindow", "Delete Property", Q_NULLPTR));
        pushButton_7->setText(QApplication::translate("MainWindow", "update", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainWindow", "buyer", Q_NULLPTR));
        label_8->setText(QApplication::translate("MainWindow", "seller", Q_NULLPTR));
        label_9->setText(QApplication::translate("MainWindow", "Search by ID", Q_NULLPTR));
        label_10->setText(QApplication::translate("MainWindow", "Search by Type", Q_NULLPTR));
        label_11->setText(QApplication::translate("MainWindow", "Search by exact Price", Q_NULLPTR));
        pushButton_8->setText(QApplication::translate("MainWindow", "Search", Q_NULLPTR));
        pushButton_9->setText(QApplication::translate("MainWindow", "Search", Q_NULLPTR));
        pushButton_10->setText(QApplication::translate("MainWindow", "Search", Q_NULLPTR));
        pushButton_11->setText(QApplication::translate("MainWindow", "Sort by ID", Q_NULLPTR));
        pushButton_12->setText(QApplication::translate("MainWindow", "Sort by Type", Q_NULLPTR));
        pushButton_13->setText(QApplication::translate("MainWindow", "Sort by Price", Q_NULLPTR));
        label_12->setText(QApplication::translate("MainWindow", "House Description :", Q_NULLPTR));
        pushButton_5->setText(QApplication::translate("MainWindow", "Empty", Q_NULLPTR));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_4), QApplication::translate("MainWindow", "Add Property", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "GroupBox", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        pushButton_16->setText(QString());
        pushButton_17->setText(QString());
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab), QApplication::translate("MainWindow", "VideoDisplay", Q_NULLPTR));
        menuProperty_Management->setTitle(QApplication::translate("MainWindow", "Property Management", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
