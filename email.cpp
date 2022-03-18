#include "email.h"
#include "ui_email.h"
#include "smtp.h"
#include<QMessageBox>
#include <QtNetwork/qtnetworkglobal.h>
#include <QtCore/qiodevice.h>
#include <QtCore/qobject.h>
#include <QObject>
#include <QtCore/qdebug.h>
#include "email.h"
#include "smtp.h"
#include "ui_email.h"
email::email(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::email)
{
    ui->setupUi(this);
    connect(ui->envoyer_dialog_2, SIGNAL(clicked()),this, SLOT(sendMail()));
    connect(ui->annuler_mail_2, SIGNAL(clicked()),this, SLOT(close()));

}

email::email(QString e,QString n,QString s,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::email)
{
    QString contenu="Contenu";
    ui->setupUi(this);

    ui->recipient_2->setText(e);
    ui->uname->setText("buyeragentreal@gmail.com");
    ui->passwd_2->setText("12300azer");
    ui->passwd_2->setEchoMode(QLineEdit::Password);

    if (s=="Homme")
    {
        ui->message_2->setText("Cher Monsieur "+n+",\n\n"+contenu+"\n\n"+"Cordialement,\n");
    }
    else if (s=="Femme")
    {
        ui->message_2->setText("Chère Madame "+n+",\n\n"+contenu+"\n\n"+"Cordialement,\n");
    }

}
void email::on_envoyer_dialog_2_clicked()
{QString status;
    Smtp* smtp = new Smtp(ui->uname->text(), ui->passwd_2->text(), "smtp.gmail.com", 465);

    smtp->sendMail(ui->uname->text(), ui->recipient_2->text() , ui->subjectLineEdit_2->text() ,ui->message_2->toPlainText());

    if(status == "Message sent")
        QMessageBox::warning( 0, tr( "Qt Simple SMTP client" ), tr( "Message sent!\n\n" ) );
}
email::~email()
{
    delete ui;

}
