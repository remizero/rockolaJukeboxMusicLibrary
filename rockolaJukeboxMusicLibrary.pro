#-------------------------------------------------
#
# Project created by QtCreator 2020-06-01T18:58:22
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets sql

TARGET = rockolaJukeboxMusicLibrary
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
    src/main.cpp \
    src/MainWindow.cpp \
    src/RockolaDbManager.cpp \
    src/RockolaUtils.cpp \
    src/ConfigData.cpp \
    src/RockolaHeaderData.cpp \
    src/RockolaTreeMDL.cpp \
    src/RockolaTreeItem.cpp \
    src/StarRating.cpp \
    src/RockolaHeaderTooltipDLG.cpp \
    src/RockolaMainWindow.cpp \
    src/StarDelegate.cpp \
    src/ComboBoxDelegate.cpp \
    src/SpinBoxDelegate.cpp \
    src/ComboBoxItemModel.cpp \
    src/StarEditor.cpp

HEADERS += \
    src/MainWindow.h \
    src/RockolaDbManager.h \
    src/RockolaUtils.h \
    src/ConfigData.h \
    src/RockolaHeaderData.h \
    src/RockolaTreeMDL.h \
    src/RockolaTreeItem.h \
    src/StarRating.h \
    src/RockolaHeaderTooltipDLG.h \
    src/RockolaMainWindow.h \
    src/StarDelegate.h \
    src/ComboBoxDelegate.h \
    src/SpinBoxDelegate.h \
    src/ComboBoxItemModel.h \
    src/StarEditor.h

FORMS += \
    src/MainWindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    src/RockolaResources.qrc

DISTFILES +=
