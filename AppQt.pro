QT       += core gui multimedia multimediawidgets sql location \
    quick

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets quickwidgets network qml

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
    dialog.cpp \
    main.cpp \
    mainwindow.cpp \
    map.cpp \
    property.cpp \
    video.cpp

HEADERS += \
    dialog.h \
    mainwindow.h \
    map.h \
    property.h \
    video.h

FORMS += \
    dialog.ui \
    mainwindow.ui \
    map.ui \
    video.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    ../ressourcesgraphiques/resource.qrc \
    qml.qrc

win32: LIBS += -L$$PWD/../../../Downloads/mysqllib/mysql-connector-c++-8.0.28-win32/lib/vs14/ -lmysqlcppconn

INCLUDEPATH += $$PWD/../../../Downloads/mysqllib/mysql-connector-c++-8.0.28-win32/lib/vs14
DEPENDPATH += $$PWD/../../../Downloads/mysqllib/mysql-connector-c++-8.0.28-win32/lib/vs14

DISTFILES += \
    main.qml

