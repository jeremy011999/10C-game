#-------------------------------------------------
#
# Project created by QtCreator 2019-05-24T16:08:57
#
#-------------------------------------------------

QT += core gui
QT += multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = IceBreakerApplication
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
    main.cpp \
    ball.cpp \
    bricks.cpp \
    game.cpp \
    greensnowflake.cpp \
    instructionswindow.cpp \
    levels_window.cpp \
    monster.cpp \
    mygui.cpp \
    optionswindow.cpp \
    paddle.cpp \
    resultswindow.cpp \
    snowflakes.cpp \
    welcome_window.cpp \
    powerupmeter.cpp \
    notifications.cpp \
    levelwonwindow.cpp \
    wingamewindow.cpp \
    event_filters.cpp

HEADERS += \
    ball.h \
    bricks.h \
    game.h \
    greensnowflake.h \
    instructionswindow.h \
    levels_window.h \
    monster.h \
    mygui.h \
    optionswindow.h \
    paddle.h \
    resultswindow.h \
    snowflakes.h \
    welcome_window.h \
    powerupmeter.h \
    notifications.h \
    levelwonwindow.h \
    paddle.h \
    wingamewindow.h \
    event_filters.h

RESOURCES += \
    rsources.qrc

DISTFILES +=

