#ifndef FORM_H
#define FORM_H

#include <QMainWindow>

namespace Ui {
class form;
}

class form : public QMainWindow
{
    Q_OBJECT

public:
    explicit form(QWidget *parent = nullptr);
    ~form();

private:
    Ui::form *ui;
};

#endif // FORM_H
