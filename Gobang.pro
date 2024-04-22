QT       += core gui
QT       += multimedia
QT       += core gui network
QT       += core gui multimedia multimediawidgets
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    checkbrd.cpp \
    checkbrd_ai.cpp \
    confirm_exit.cpp \
    main.cpp \
    start.cpp \
    start1.cpp \
    start2.cpp

HEADERS += \
    checkbrd.h \
    checkbrd_ai.h \
    confirm_exit.h \
    start.h \
    start1.h \
    start2.h

FORMS += \
    checkbrd.ui \
    checkbrd_ai.ui \
    confirm_exit.ui \
    start.ui \
    start1.ui \
    start2.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    image.qrc
