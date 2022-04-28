/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_login
{
public:
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QPushButton *login_2;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *type;
    QLabel *label_4;

    void setupUi(QDialog *login)
    {
        if (login->objectName().isEmpty())
            login->setObjectName(QStringLiteral("login"));
        login->resize(1104, 775);
        QIcon icon;
        icon.addFile(QStringLiteral("../../../Downloads/279105962_364393082142777_3805701867299913099_n.png"), QSize(), QIcon::Normal, QIcon::Off);
        login->setWindowIcon(icon);
        lineEdit = new QLineEdit(login);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(320, 220, 271, 51));
        lineEdit_2 = new QLineEdit(login);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(320, 300, 271, 51));
        login_2 = new QPushButton(login);
        login_2->setObjectName(QStringLiteral("login_2"));
        login_2->setGeometry(QRect(360, 490, 171, 51));
        label = new QLabel(login);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(190, 210, 101, 61));
        label_2 = new QLabel(login);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(190, 290, 101, 61));
        label_3 = new QLabel(login);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(220, 590, 571, 51));
        type = new QLineEdit(login);
        type->setObjectName(QStringLiteral("type"));
        type->setGeometry(QRect(320, 380, 271, 51));
        label_4 = new QLabel(login);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(190, 400, 91, 21));

        retranslateUi(login);

        QMetaObject::connectSlotsByName(login);
    } // setupUi

    void retranslateUi(QDialog *login)
    {
        login->setWindowTitle(QApplication::translate("login", "Dialog", Q_NULLPTR));
        login_2->setText(QApplication::translate("login", "login", Q_NULLPTR));
        label->setText(QApplication::translate("login", "Login", Q_NULLPTR));
        label_2->setText(QApplication::translate("login", "Password", Q_NULLPTR));
        label_3->setText(QApplication::translate("login", "<html><head/><body><p><span style=\" font-size:6pt; color:#000000;\">TextLabel</span></p></body></html>", Q_NULLPTR));
        label_4->setText(QApplication::translate("login", "Function", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class login: public Ui_login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
