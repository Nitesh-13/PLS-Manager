QT       += core gui
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    atominstall.cpp \
    cppselect.cpp \
    editors.cpp \
    javaselect.cpp \
    main.cpp \
    mainwindow.cpp \
    pythonselect.cpp \
    sublimeinstall.cpp \
    vsinstall.cpp

HEADERS += \
    atominstall.h \
    cppselect.h \
    editors.h \
    javaselect.h \
    mainwindow.h \
    pythonselect.h \
    sublimeinstall.h \
    vsinstall.h

FORMS += \
    atominstall.ui \
    cppselect.ui \
    editors.ui \
    javaselect.ui \
    mainwindow.ui \
    pythonselect.ui \
    sublimeinstall.ui \
    vsinstall.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    assets.qrc

win32{
    RC_FILE = winadmin.rc
}
