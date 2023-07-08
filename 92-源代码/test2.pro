QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    answer.cpp \
    error.cpp \
    introduction.cpp \
    jump.cpp \
    main.cpp \
    pkulife.cpp \
    welcome.cpp \
    widget.cpp

HEADERS += \
    answer.h \
    error.h \
    introduction.h \
    jump.h \
    pkulife.h \
    welcome.h \
    widget.h

FORMS += \
    answer.ui \
    error.ui \
    introduction.ui \
    jump.ui \
    pkulife.ui \
    welcome.ui \
    widget.ui

TRANSLATIONS += \
    test2_zh_CN.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    image.qrc
