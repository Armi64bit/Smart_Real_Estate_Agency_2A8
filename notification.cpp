#include "notification.h"

Notification::Notification()
{

}

void Notification::notification_ajoutab()
{

    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
    notifyIcon->show();
    notifyIcon->showMessage("Seller Management "," new seller added ",QSystemTrayIcon::Information,15000);
}

void Notification::notification_supprimerab(){
    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
    notifyIcon->show();
    notifyIcon->showMessage("Seller Management "," seller deleted ",QSystemTrayIcon::Information,15000);
}


void Notification::notification_modifierab(){
    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
    notifyIcon->show();
    notifyIcon->showMessage("Seller Management "," seller modified ",QSystemTrayIcon::Information,15000);

}
