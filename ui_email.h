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
        QIcon icon;
        icon.addFile(QStringLiteral("../../../Downloads/279105962_364393082142777_3805701867299913099_n.png"), QSize(), QIcon::Normal, QIcon::Off);
        email->setWindowIcon(icon);
        layoutWidget = new QWidget(email);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(80, 40, 551, 401));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        recipientLabel = new QLabel(layoutWidget);
        recipientLabel->setObjectName(QStringLiteral("recipientLabel"));

        formLayout->setWidget(0, QFormLayout::LabelRole, recipientLabel);

        recipient_2 = new QLineEdit(layoutWidget);
        recipient_2->setObjectName(QStringLiteral("recipient_2"));
        recipient_2->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));

        formLayout->setWidget(0, QFormLayout::FieldRole, recipient_2);

        subjectLabel = new QLabel(layoutWidget);
        subjectLabel->setObjectName(QStringLiteral("subjectLabel"));

        formLayout->setWidget(1, QFormLayout::LabelRole, subjectLabel);

        subjectLineEdit_2 = new QLineEdit(layoutWidget);
        subjectLineEdit_2->setObjectName(QStringLiteral("subjectLineEdit_2"));
        subjectLineEdit_2->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));

        formLayout->setWidget(1, QFormLayout::FieldRole, subjectLineEdit_2);


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
        envoyer_dialog_2->setStyleSheet(QLatin1String("QPushButton\n"
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

        horizontalLayout->addWidget(envoyer_dialog_2);

        annuler_mail_2 = new QPushButton(layoutWidget);
        annuler_mail_2->setObjectName(QStringLiteral("annuler_mail_2"));
        annuler_mail_2->setStyleSheet(QLatin1String("QPushButton\n"
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

        horizontalLayout->addWidget(annuler_mail_2);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(email);

        QMetaObject::connectSlotsByName(email);
    } // setupUi

    void retranslateUi(QDialog *email)
    {
        email->setWindowTitle(QApplication::translate("email", "Dialog", Q_NULLPTR));
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
