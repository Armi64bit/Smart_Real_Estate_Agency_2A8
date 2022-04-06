/********************************************************************************
** Form generated from reading UI file 'video.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIDEO_H
#define UI_VIDEO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_video
{
public:
    QAction *actionPlay;
    QPushButton *pushButton;

    void setupUi(QDialog *video)
    {
        if (video->objectName().isEmpty())
            video->setObjectName(QStringLiteral("video"));
        video->resize(658, 467);
        actionPlay = new QAction(video);
        actionPlay->setObjectName(QStringLiteral("actionPlay"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/new/prefix1/audio_02.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        actionPlay->setIcon(icon);
        pushButton = new QPushButton(video);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(340, 200, 75, 23));
        pushButton->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"url(:/new/prefix1/audio_02.jpg)\n"
"}"));

        retranslateUi(video);

        QMetaObject::connectSlotsByName(video);
    } // setupUi

    void retranslateUi(QDialog *video)
    {
        video->setWindowTitle(QApplication::translate("video", "Dialog", Q_NULLPTR));
        actionPlay->setText(QApplication::translate("video", "Play", Q_NULLPTR));
        pushButton->setText(QApplication::translate("video", "PushButton", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class video: public Ui_video {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIDEO_H
