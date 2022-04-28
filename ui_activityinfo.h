/********************************************************************************
** Form generated from reading UI file 'activityinfo.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ACTIVITYINFO_H
#define UI_ACTIVITYINFO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_activityinfo
{
public:
    QPushButton *add;
    QLineEdit *lineEdit;
    QLabel *label_5;
    QLabel *Name;
    QLabel *Author;
    QLabel *Date;
    QLabel *Important;
    QListWidget *listWidget;
    QPushButton *remove;
    QCheckBox *checkBox;
    QLineEdit *nome;
    QLineEdit *autore;
    QCheckBox *importante;
    QDateEdit *data;
    QLabel *label;
    QPushButton *save;

    void setupUi(QDialog *activityinfo)
    {
        if (activityinfo->objectName().isEmpty())
            activityinfo->setObjectName(QStringLiteral("activityinfo"));
        activityinfo->resize(597, 421);
        add = new QPushButton(activityinfo);
        add->setObjectName(QStringLiteral("add"));
        add->setGeometry(QRect(510, 110, 41, 21));
        add->setCursor(QCursor(Qt::PointingHandCursor));
        add->setStyleSheet(QLatin1String("QPushButton\n"
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
        lineEdit = new QLineEdit(activityinfo);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(120, 110, 371, 31));
        label_5 = new QLabel(activityinfo);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, 110, 101, 31));
        label_5->setStyleSheet(QStringLiteral("font: 11pt \"MS Shell Dlg 2\";"));
        Name = new QLabel(activityinfo);
        Name->setObjectName(QStringLiteral("Name"));
        Name->setGeometry(QRect(10, 10, 141, 16));
        Name->setStyleSheet(QStringLiteral("font: 11pt \"MS Shell Dlg 2\";"));
        Author = new QLabel(activityinfo);
        Author->setObjectName(QStringLiteral("Author"));
        Author->setGeometry(QRect(10, 40, 131, 16));
        Author->setStyleSheet(QStringLiteral("font: 11pt \"MS Shell Dlg 2\";"));
        Date = new QLabel(activityinfo);
        Date->setObjectName(QStringLiteral("Date"));
        Date->setGeometry(QRect(10, 70, 61, 21));
        Date->setStyleSheet(QStringLiteral("font: 11pt \"MS Shell Dlg 2\";"));
        Important = new QLabel(activityinfo);
        Important->setObjectName(QStringLiteral("Important"));
        Important->setGeometry(QRect(470, 50, 71, 16));
        Important->setStyleSheet(QStringLiteral("font: 11pt \"MS Shell Dlg 2\";"));
        listWidget = new QListWidget(activityinfo);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(10, 150, 481, 231));
        remove = new QPushButton(activityinfo);
        remove->setObjectName(QStringLiteral("remove"));
        remove->setGeometry(QRect(500, 150, 41, 21));
        remove->setCursor(QCursor(Qt::PointingHandCursor));
        remove->setStyleSheet(QLatin1String("QPushButton\n"
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
        checkBox = new QCheckBox(activityinfo);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setGeometry(QRect(560, 10, 31, 31));
        nome = new QLineEdit(activityinfo);
        nome->setObjectName(QStringLiteral("nome"));
        nome->setGeometry(QRect(150, 10, 113, 21));
        autore = new QLineEdit(activityinfo);
        autore->setObjectName(QStringLiteral("autore"));
        autore->setGeometry(QRect(150, 40, 113, 21));
        importante = new QCheckBox(activityinfo);
        importante->setObjectName(QStringLiteral("importante"));
        importante->setGeometry(QRect(560, 50, 31, 22));
        data = new QDateEdit(activityinfo);
        data->setObjectName(QStringLiteral("data"));
        data->setGeometry(QRect(150, 70, 111, 25));
        label = new QLabel(activityinfo);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(490, 10, 60, 31));
        label->setStyleSheet(QStringLiteral("font: 11pt \"MS Shell Dlg 2\";"));
        save = new QPushButton(activityinfo);
        save->setObjectName(QStringLiteral("save"));
        save->setGeometry(QRect(500, 390, 81, 21));
        save->setStyleSheet(QLatin1String("QPushButton\n"
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

        retranslateUi(activityinfo);

        QMetaObject::connectSlotsByName(activityinfo);
    } // setupUi

    void retranslateUi(QDialog *activityinfo)
    {
        activityinfo->setWindowTitle(QApplication::translate("activityinfo", "Dialog", Q_NULLPTR));
        add->setText(QApplication::translate("activityinfo", "+", Q_NULLPTR));
        label_5->setText(QApplication::translate("activityinfo", " Subactivities : ", Q_NULLPTR));
        Name->setText(QApplication::translate("activityinfo", "Name of the activity", Q_NULLPTR));
        Author->setText(QApplication::translate("activityinfo", "Name of the author", Q_NULLPTR));
        Date->setText(QApplication::translate("activityinfo", "Date", Q_NULLPTR));
        Important->setText(QApplication::translate("activityinfo", "Important", Q_NULLPTR));
        remove->setText(QApplication::translate("activityinfo", "-", Q_NULLPTR));
        checkBox->setText(QString());
        importante->setText(QString());
        label->setText(QApplication::translate("activityinfo", "Done", Q_NULLPTR));
        save->setText(QApplication::translate("activityinfo", "Save", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class activityinfo: public Ui_activityinfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ACTIVITYINFO_H
