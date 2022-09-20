QT       += core gui network widgets sql

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    downloader.cpp \
    editors.cpp \
    github.cpp \
    main.cpp \
    mainwindow.cpp \
    proceedtab.cpp

HEADERS += \
    downloader.h \
    editors.h \
    github.h \
    mainwindow.h \
    proceedtab.h

FORMS += \
    editors.ui \
    github.ui \
    mainwindow.ui \
    proceedtab.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

VERSION = 1.2.0

RESOURCES += \
    assets.qrc

win32{
    RC_FILE = winadmin.rc
}
