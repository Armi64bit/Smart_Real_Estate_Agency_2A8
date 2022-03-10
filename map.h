#ifndef MAP_H
#define MAP_H

#include <QDialog>
#include <QtQuick>
#include <QtNetwork>
#include <QSsl>
#include <QVariant>
#include <QApplication>
#include <QQuickWidget>
#include <QQmlContext>
#include "markermodel.h"

namespace Ui {
class map;
}

class map : public QDialog
{
    Q_OBJECT

public:
    explicit map(QWidget *parent = nullptr);
    ~map();

private:
    Ui::map *ui;
signals:
    void setPosition(QVariant ,QVariant);

};
#endif // MAP_H
