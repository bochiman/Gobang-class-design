QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    checkbrd.cpp \
    checkbrd_ai.cpp \
    main.cpp \
    start.cpp

HEADERS += \
    checkbrd.h \
    checkbrd_ai.h \
    start.h

FORMS += \
    checkbrd.ui \
    checkbrd_ai.ui \
    start.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    image.qrc \
    image.qrc

DISTFILES += \
    image/black.png \
    image/chessBoard.jpg \
    image/white.png
