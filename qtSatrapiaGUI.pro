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
    clases/gestor/ciudad.cpp \
    clases/gestor/nacion.cpp \
    clases/gestor/palacio.cpp \
    clases/recursos/cuartel.cpp \
    clases/recursos/estructura.cpp \
    clases/item.cpp \
    clases/jugador.cpp \
    clases/partida.cpp \
    clases/persistencia_item.cpp \
    clases/persistencia_partida.cpp \
    clases/persistencia_usuario.cpp \
    clases/posicion.cpp \
    clases/recursos/almacen.cpp \
    clases/recursos/edificio.cpp \
    clases/recursos/extractor.cpp \
    clases/recursos/fuente.cpp \
    clases/recursos/recurso.cpp \
    clases/recursos/residencia.cpp \
    clases/recursos/silo.cpp \
    clases/sgbd.cpp \
    clases/superv_partida.cpp \
    clases/superv_usuario.cpp \
    clases/usuario.cpp \
    main.cpp \
    mainwindow.cpp \
    partidawindow.cpp \
    testclases.cpp

HEADERS += \
    clases/gestor/ciudad.h \
    clases/gestor/nacion.h \
    clases/gestor/palacio.h \
    clases/recursos/cuartel.h \
    clases/recursos/estructura.h \
    clases/item.h \
    clases/jugador.h \
    clases/partida.h \
    clases/persistencia_item.h \
    clases/persistencia_partida.h \
    clases/persistencia_usuario.h \
    clases/posicion.h \
    clases/recursos/almacen.h \
    clases/recursos/edificio.h \
    clases/recursos/extractor.h \
    clases/recursos/fuente.h \
    clases/recursos/recurso.h \
    clases/recursos/residencia.h \
    clases/recursos/silo.h \
    clases/sgbd.h \
    clases/superv_partida.h \
    clases/superv_usuario.h \
    clases/usuario.h \
    mainwindow.h \
    partidawindow.h \
    testclases.h

FORMS += \
    mainwindow.ui \
    partidawindow.ui \
    testclases.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

SUBDIRS += \
    clases/satrapia_libreria.pro

DISTFILES += \

