/********************************************************************************
** Form generated from reading UI file 'newlistwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWLISTWINDOW_H
#define UI_NEWLISTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_newListWindow
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit2;

    void setupUi(QDialog *newListWindow)
    {
        if (newListWindow->objectName().isEmpty())
            newListWindow->setObjectName(QStringLiteral("newListWindow"));
        newListWindow->resize(365, 155);
        buttonBox = new QDialogButtonBox(newListWindow);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(100, 100, 171, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(newListWindow);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 20, 121, 21));
        label->setStyleSheet(QStringLiteral("font: 11pt \"MS Shell Dlg 2\";"));
        label_2 = new QLabel(newListWindow);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 50, 101, 41));
        label_2->setStyleSheet(QStringLiteral("font: 11pt \"MS Shell Dlg 2\";"));
        lineEdit = new QLineEdit(newListWindow);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(130, 20, 201, 21));
        lineEdit2 = new QLineEdit(newListWindow);
        lineEdit2->setObjectName(QStringLiteral("lineEdit2"));
        lineEdit2->setGeometry(QRect(130, 60, 201, 21));

        retranslateUi(newListWindow);
        QObject::connect(buttonBox, SIGNAL(accepted()), newListWindow, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), newListWindow, SLOT(reject()));

        QMetaObject::connectSlotsByName(newListWindow);
    } // setupUi

    void retranslateUi(QDialog *newListWindow)
    {
        newListWindow->setWindowTitle(QApplication::translate("newListWindow", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("newListWindow", "Name of the list", Q_NULLPTR));
        label_2->setText(QApplication::translate("newListWindow", "Type of the list", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class newListWindow: public Ui_newListWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWLISTWINDOW_H
