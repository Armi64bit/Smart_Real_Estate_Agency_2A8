/********************************************************************************
** Form generated from reading UI file 'email.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EMAIL_H
#define UI_EMAIL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_email
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *nomLabel;
    QLineEdit *uname;
    QLabel *prenomLabel;
    QLineEdit *passwd_2;
    QLabel *recipientLabel;
    QLineEdit *recipient_2;
    QLabel *subjectLabel;
    QLineEdit *subjectLineEdit_2;
    QTextEdit *message_2;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *envoyer_dialog_2;
    QPushButton *annuler_mail_2;

    void setupUi(QDialog *email)
    {
        if (email->objectName().isEmpty())
            email->setObjectName(QStringLiteral("email"));
        email->resize(896, 598);
        layoutWidget = new QWidget(email);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(80, 40, 551, 401));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        nomLabel = new QLabel(layoutWidget);
        nomLabel->setObjectName(QStringLiteral("nomLabel"));

        formLayout->setWidget(0, QFormLayout::LabelRole, nomLabel);

        uname = new QLineEdit(layoutWidget);
        uname->setObjectName(QStringLiteral("uname"));
        uname->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));

        formLayout->setWidget(0, QFormLayout::FieldRole, uname);

        prenomLabel = new QLabel(layoutWidget);
        prenomLabel->setObjectName(QStringLiteral("prenomLabel"));

        formLayout->setWidget(1, QFormLayout::LabelRole, prenomLabel);

        passwd_2 = new QLineEdit(layoutWidget);
        passwd_2->setObjectName(QStringLiteral("passwd_2"));
        passwd_2->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));

        formLayout->setWidget(1, QFormLayout::FieldRole, passwd_2);

        recipientLabel = new QLabel(layoutWidget);
        recipientLabel->setObjectName(QStringLiteral("recipientLabel"));

        formLayout->setWidget(2, QFormLayout::LabelRole, recipientLabel);

        recipient_2 = new QLineEdit(layoutWidget);
        recipient_2->setObjectName(QStringLiteral("recipient_2"));
        recipient_2->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));

        formLayout->setWidget(2, QFormLayout::FieldRole, recipient_2);

        subjectLabel = new QLabel(layoutWidget);
        subjectLabel->setObjectName(QStringLiteral("subjectLabel"));

        formLayout->setWidget(3, QFormLayout::LabelRole, subjectLabel);

        subjectLineEdit_2 = new QLineEdit(layoutWidget);
        subjectLineEdit_2->setObjectName(QStringLiteral("subjectLineEdit_2"));
        subjectLineEdit_2->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));

        formLayout->setWidget(3, QFormLayout::FieldRole, subjectLineEdit_2);


        verticalLayout->addLayout(formLayout);

        message_2 = new QTextEdit(layoutWidget);
        message_2->setObjectName(QStringLiteral("message_2"));
        message_2->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));

        verticalLayout->addWidget(message_2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        envoyer_dialog_2 = new QPushButton(layoutWidget);
        envoyer_dialog_2->setObjectName(QStringLiteral("envoyer_dialog_2"));

        horizontalLayout->addWidget(envoyer_dialog_2);

        annuler_mail_2 = new QPushButton(layoutWidget);
        annuler_mail_2->setObjectName(QStringLiteral("annuler_mail_2"));

        horizontalLayout->addWidget(annuler_mail_2);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(email);

        QMetaObject::connectSlotsByName(email);
    } // setupUi

    void retranslateUi(QDialog *email)
    {
        email->setWindowTitle(QApplication::translate("email", "Dialog", Q_NULLPTR));
        nomLabel->setText(QApplication::translate("email", "Username", Q_NULLPTR));
        uname->setText(QApplication::translate("email", "buyeragentreal@gmail.com", Q_NULLPTR));
        prenomLabel->setText(QApplication::translate("email", "Password", Q_NULLPTR));
        passwd_2->setText(QApplication::translate("email", "12300azer", Q_NULLPTR));
        recipientLabel->setText(QApplication::translate("email", "Recipient", Q_NULLPTR));
        subjectLabel->setText(QApplication::translate("email", "Subject", Q_NULLPTR));
        envoyer_dialog_2->setText(QApplication::translate("email", "Envoyer", Q_NULLPTR));
        annuler_mail_2->setText(QApplication::translate("email", "Annuler", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class email: public Ui_email {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EMAIL_H
