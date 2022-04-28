/********************************************************************************
** Form generated from reading UI file 'newactivitywindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWACTIVITYWINDOW_H
#define UI_NEWACTIVITYWINDOW_H

#include <QtCore/QDate>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_newActivityWindow
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit2;
    QDateEdit *dateEdit;
    QCheckBox *checkBox;

    void setupUi(QDialog *newActivityWindow)
    {
        if (newActivityWindow->objectName().isEmpty())
            newActivityWindow->setObjectName(QStringLiteral("newActivityWindow"));
        newActivityWindow->resize(400, 222);
        buttonBox = new QDialogButtonBox(newActivityWindow);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(30, 180, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(newActivityWindow);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 20, 141, 16));
        label->setStyleSheet(QStringLiteral("font: 11pt \"MS Shell Dlg 2\";"));
        label_2 = new QLabel(newActivityWindow);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(30, 60, 131, 16));
        label_2->setStyleSheet(QStringLiteral("font: 11pt \"MS Shell Dlg 2\";"));
        label_3 = new QLabel(newActivityWindow);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(30, 100, 60, 16));
        label_3->setStyleSheet(QStringLiteral("font: 11pt \"MS Shell Dlg 2\";"));
        label_4 = new QLabel(newActivityWindow);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(30, 150, 91, 16));
        label_4->setStyleSheet(QStringLiteral("font: 11pt \"MS Shell Dlg 2\";"));
        lineEdit = new QLineEdit(newActivityWindow);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(170, 20, 113, 24));
        lineEdit2 = new QLineEdit(newActivityWindow);
        lineEdit2->setObjectName(QStringLiteral("lineEdit2"));
        lineEdit2->setGeometry(QRect(170, 60, 113, 24));
        dateEdit = new QDateEdit(newActivityWindow);
        dateEdit->setObjectName(QStringLiteral("dateEdit"));
        dateEdit->setGeometry(QRect(170, 100, 121, 25));
        dateEdit->setCalendarPopup(true);
        dateEdit->setTimeSpec(Qt::LocalTime);
        dateEdit->setDate(QDate(2018, 3, 1));
        checkBox = new QCheckBox(newActivityWindow);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setGeometry(QRect(170, 150, 21, 22));

        retranslateUi(newActivityWindow);
        QObject::connect(buttonBox, SIGNAL(accepted()), newActivityWindow, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), newActivityWindow, SLOT(reject()));

        QMetaObject::connectSlotsByName(newActivityWindow);
    } // setupUi

    void retranslateUi(QDialog *newActivityWindow)
    {
        newActivityWindow->setWindowTitle(QApplication::translate("newActivityWindow", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("newActivityWindow", "Name of the activity", Q_NULLPTR));
        label_2->setText(QApplication::translate("newActivityWindow", "Name of the author", Q_NULLPTR));
        label_3->setText(QApplication::translate("newActivityWindow", "Date", Q_NULLPTR));
        label_4->setText(QApplication::translate("newActivityWindow", "Important", Q_NULLPTR));
        checkBox->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class newActivityWindow: public Ui_newActivityWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWACTIVITYWINDOW_H
