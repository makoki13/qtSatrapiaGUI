QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

QT += sql

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
    ../QtSatrapia/item.cpp \
    ../QtSatrapia/jugador.cpp \
    ../QtSatrapia/partida.cpp \
    ../QtSatrapia/persistencia_item.cpp \
    ../QtSatrapia/persistencia_partida.cpp \
    ../QtSatrapia/persistencia_usuario.cpp \
    ../QtSatrapia/sgbd.cpp \
    ../QtSatrapia/superv_partida.cpp \
    ../QtSatrapia/superv_usuario.cpp \
    ../QtSatrapia/usuario.cpp \
    main.cpp \
    mainwindow.cpp \
    partidawindow.cpp

HEADERS += \
    ../QtSatrapia/item.h \
    ../QtSatrapia/jugador.h \
    ../QtSatrapia/partida.h \
    ../QtSatrapia/persistencia_item.h \
    ../QtSatrapia/persistencia_partida.h \
    ../QtSatrapia/persistencia_usuario.h \
    ../QtSatrapia/sgbd.h \
    ../QtSatrapia/superv_partida.h \
    ../QtSatrapia/superv_usuario.h \
    ../QtSatrapia/usuario.h \
    mainwindow.h \
    partidawindow.h

FORMS += \
    mainwindow.ui \
    partidawindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
