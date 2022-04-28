/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_dialog
{
public:
    QWidget *centralwidget;
    QPushButton *deleteActivity;
    QPushButton *deleteList;
    QListWidget *vistaLista;
    QPushButton *newList;
    QPushButton *newAct;
    QListWidget *liste;
    QPushButton *return_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *dialog)
    {
        if (dialog->objectName().isEmpty())
            dialog->setObjectName(QStringLiteral("dialog"));
        dialog->resize(877, 639);
        centralwidget = new QWidget(dialog);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        deleteActivity = new QPushButton(centralwidget);
        deleteActivity->setObjectName(QStringLiteral("deleteActivity"));
        deleteActivity->setGeometry(QRect(520, 440, 91, 31));
        QFont font;
        font.setFamily(QStringLiteral("Arial"));
        font.setPointSize(10);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        deleteActivity->setFont(font);
        deleteActivity->setCursor(QCursor(Qt::PointingHandCursor));
        deleteActivity->setStyleSheet(QLatin1String("QPushButton\n"
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
        deleteList = new QPushButton(centralwidget);
        deleteList->setObjectName(QStringLiteral("deleteList"));
        deleteList->setGeometry(QRect(100, 440, 81, 31));
        deleteList->setFont(font);
        deleteList->setCursor(QCursor(Qt::PointingHandCursor));
        deleteList->setStyleSheet(QLatin1String("QPushButton\n"
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
        vistaLista = new QListWidget(centralwidget);
        vistaLista->setObjectName(QStringLiteral("vistaLista"));
        vistaLista->setGeometry(QRect(290, 70, 551, 371));
        newList = new QPushButton(centralwidget);
        newList->setObjectName(QStringLiteral("newList"));
        newList->setGeometry(QRect(60, 40, 111, 31));
        QFont font1;
        font1.setFamily(QStringLiteral("Arial"));
        font1.setPointSize(10);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setUnderline(false);
        font1.setWeight(50);
        newList->setFont(font1);
        newList->setCursor(QCursor(Qt::PointingHandCursor));
        newList->setStyleSheet(QLatin1String("QPushButton\n"
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
        newAct = new QPushButton(centralwidget);
        newAct->setObjectName(QStringLiteral("newAct"));
        newAct->setGeometry(QRect(490, 40, 111, 31));
        newAct->setCursor(QCursor(Qt::PointingHandCursor));
        newAct->setStyleSheet(QLatin1String("QPushButton\n"
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
        liste = new QListWidget(centralwidget);
        liste->setObjectName(QStringLiteral("liste"));
        liste->setGeometry(QRect(10, 70, 271, 371));
        return_2 = new QPushButton(centralwidget);
        return_2->setObjectName(QStringLiteral("return_2"));
        return_2->setGeometry(QRect(734, 552, 111, 31));
        return_2->setStyleSheet(QLatin1String("QPushButton\n"
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
        dialog->setCentralWidget(centralwidget);
        menubar = new QMenuBar(dialog);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 877, 22));
        dialog->setMenuBar(menubar);
        statusbar = new QStatusBar(dialog);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        dialog->setStatusBar(statusbar);

        retranslateUi(dialog);

        QMetaObject::connectSlotsByName(dialog);
    } // setupUi

    void retranslateUi(QMainWindow *dialog)
    {
        dialog->setWindowTitle(QApplication::translate("dialog", "dialog", Q_NULLPTR));
        deleteActivity->setText(QApplication::translate("dialog", "Delete Activity ", Q_NULLPTR));
        deleteList->setText(QApplication::translate("dialog", "Delete List ", Q_NULLPTR));
        newList->setText(QApplication::translate("dialog", "Create New List", Q_NULLPTR));
        newAct->setText(QApplication::translate("dialog", "Add New Activity", Q_NULLPTR));
        return_2->setText(QApplication::translate("dialog", " Previous page", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class dialog: public Ui_dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
