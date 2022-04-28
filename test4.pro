QT       += core gui multimedia multimediawidgets sql location network serialport  \
quick

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets quickwidgets network qml
QT += widgets printsupport #quickwidgets network qml

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    activity.cpp \
    activityinfo.cpp \
    agent.cpp \
    arduino.cpp \
    buyer.cpp \
    camera.cpp \
    connection.cpp \
    dialog.cpp \
    email.cpp \
    exporttoexcelfile.cpp \
    list.cpp \
    listmanager.cpp \
    login.cpp \
    main.cpp \
    mainwindow.cpp \
    map.cpp \
    newactivitywindow.cpp \
    newlistwindow.cpp \
    notification.cpp \
    partners.cpp \
    property.cpp \
    qcustomplot.cpp \
    sellers.cpp \
    smtp.cpp \
    statistics.cpp \
    subactivity.cpp \
    subject.cpp \
    subscriptions.cpp

HEADERS += \
    activity.h \
    activityinfo.h \
    agent.h \
    arduino.h \
    buyer.h \
    camera.h \
    connection.h \
    dialog.h \
    email.h \
    exporttoexcelfile.h \
    list.h \
    listmanager.h \
    login.h \
    mainwindow.h \
    map.h \
    newactivitywindow.h \
    newlistwindow.h \
    notification.h \
    partners.h \
    property.h \
    qcustomplot.h \
    sellers.h \
    smtp.h \
    statistics.h \
    subactivity.h \
    subject.h \
    subscriptions.h \
    ui_email.h

FORMS += \
    activityinfo.ui \
    camera.ui \
    dialog.ui \
    email.ui \
    login.ui \
    mainwindow.ui \
    map.ui \
    newactivitywindow.ui \
    newlistwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    Incrypt.qss \
    test4.pro.user \
    test4.pro.user.39135a6

RESOURCES += \
    qml.qrc
