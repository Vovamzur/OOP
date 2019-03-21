#-------------------------------------------------
#
# Project created by QtCreator 2018-11-12T15:42:45
#
#-------------------------------------------------

QT       += core gui widgets

TARGET = AdventuresOfLolo
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        widget.cpp \
    lolo.cpp \
    game.cpp \
    staticgameobject.cpp \
    chest.cpp \
    bullet.cpp \
    enemy.cpp \
    map.cpp \
    heart.cpp \
    block.cpp \
    armedenemy.cpp \
    bulletfactory.cpp \
    bulletanimation.cpp \
    cheststate.cpp

HEADERS += \
        widget.h \
    lolo.h \
    game.h \
    staticgameobject.h \
    chest.h \
    bullet.h \
    enemy.h \
    map.h \
    drawable.h \
    heart.h \
    block.h \
    armedenemy.h \
    bulletfactory.h \
    bulletanimation.h \
    cheststate.h

FORMS += \
        widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc

DISTFILES +=
