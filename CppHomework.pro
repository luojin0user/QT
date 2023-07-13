QT       += core gui
QT	+= charts
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    addinfo.cpp \
    core/device.cpp \
    core/factory.cpp \
    main.cpp \
    mainwindow.cpp \
    rtshow.cpp \
    tableshow.cpp

HEADERS += \
    addinfo.h \
    core/device.h \
    core/factory.h \
    core/struct_transfer.h \
    mainwindow.h \
    rtshow.h \
    tableshow.h

FORMS += \
    addinfo.ui \
    mainwindow.ui \
    rtshow.ui \
    tableshow.ui

TRANSLATIONS += \
    CppHomework_zh_CN.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
