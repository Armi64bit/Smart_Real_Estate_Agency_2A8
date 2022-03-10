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
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QGroupBox *groupBox;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *lineEdit_ID;
    QLineEdit *lineEdit_type_prop;
    QLineEdit *lineEdit_price_prop;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->resize(577, 452);
        groupBox = new QGroupBox(Dialog);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(60, 40, 231, 191));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 40, 47, 14));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(30, 80, 47, 14));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(30, 120, 47, 14));
        lineEdit_ID = new QLineEdit(groupBox);
        lineEdit_ID->setObjectName(QStringLiteral("lineEdit_ID"));
        lineEdit_ID->setGeometry(QRect(90, 40, 113, 20));
        lineEdit_ID->setReadOnly(true);
        lineEdit_type_prop = new QLineEdit(groupBox);
        lineEdit_type_prop->setObjectName(QStringLiteral("lineEdit_type_prop"));
        lineEdit_type_prop->setGeometry(QRect(90, 80, 113, 20));
        lineEdit_type_prop->setReadOnly(true);
        lineEdit_price_prop = new QLineEdit(groupBox);
        lineEdit_price_prop->setObjectName(QStringLiteral("lineEdit_price_prop"));
        lineEdit_price_prop->setGeometry(QRect(90, 120, 113, 20));
        lineEdit_price_prop->setReadOnly(true);

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Show property", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("Dialog", "Show Property", Q_NULLPTR));
        label->setText(QApplication::translate("Dialog", "ID", Q_NULLPTR));
        label_2->setText(QApplication::translate("Dialog", "Type", Q_NULLPTR));
        label_3->setText(QApplication::translate("Dialog", "Price", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
