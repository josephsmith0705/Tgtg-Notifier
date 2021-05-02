QT       += core gui network mqtt

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    src/chatwindow.cpp \
    src/createlogin.cpp \
    src/main.cpp \
    src/mainwindow.cpp \
    src/userlist.cpp

HEADERS += \
    include/chatwindow.h \
    include/createlogin.h \
    include/mainwindow.h \
    include/userlist.h

FORMS += \
    ui/chatwindow.ui \
    ui/createlogin.ui \
    ui/mainwindow.ui \
    ui/userlist.ui



# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES +=


