#include "notification.h"

Notification::Notification()
{

}

void Notification::notification_ajoutab()
{

    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
   // notifyIcon->setIcon(QIcon(":/new/prefix1/MyResources/computer-icons-avatar-user-login-avatar.jpg"));
    notifyIcon->show();
    notifyIcon->showMessage("Security ","Door opened",QSystemTrayIcon::Information,15000);
}
void Notification::notification_modifierab(){
    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

   // notifyIcon->setIcon(QIcon(":/new/prefix1/MyResources/computer-icons-avatar-user-login-avatar.jpg"));
    notifyIcon->show();
    notifyIcon->showMessage("Security ","door closed",QSystemTrayIcon::Information,15000);

}
