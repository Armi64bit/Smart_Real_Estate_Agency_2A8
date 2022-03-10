#include "video.h"
#include "ui_video.h"
#include <QApplication>

#include <QMediaPlayer>
#include <QVideoWidget>
video::video(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::video)
{
    ui->setupUi(this);

}


video::~video()
{
    delete ui;
}
