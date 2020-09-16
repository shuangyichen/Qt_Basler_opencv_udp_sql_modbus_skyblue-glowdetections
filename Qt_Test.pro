#-------------------------------------------------
#
# Project created by QtCreator 2017-08-09T09:32:36
#
#-------------------------------------------------

QT       += core gui sql network serialbus serialport multimedia virtualkeyboard

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Qt_Test
TEMPLATE = app


SOURCES += main.cpp\
    confirm.cpp \
    dialog.cpp \
        mainwindow.cpp \
    BaslerCamer.cpp \
    my_modbus.cpp \
    setting.cpp \
    sql_server.cpp \
    udp.cpp \
    waterdi.cpp

HEADERS  += mainwindow.h \
    BaslerCamer.h \
    confirm.h \
    dialog.h \
    my_modbus.h \
    setting.h \
    sql_server.h \
    udp.h \
    waterdi.h

FORMS    += mainwindow.ui \
    confirm.ui \
    dialog.ui \
    setting.ui \
    waterdi.ui



INCLUDEPATH +=$$quote(C:/Basler/pylon 6/Development/include)
LIBS +=$$quote(-LC:/Basler/pylon 6/Development/lib/x64)

#INCLUDEPATH += C:/Users/ThinkPad/AppData/Local/Programs/Python/Python36/libs
#DEPENDPATH += C:/Users/ThinkPad/AppData/Local/Programs/Python/Python36/libs

#INCLUDEPATH += C:/Users/ThinkPad/AppData/Local/Programs/Python/Python36/include
#LIBS += C:/Users/ThinkPad/AppData/Local/Programs/Python/Python36/libs/python36.lib
#LIBS += C:/Users/ThinkPad/AppData/Local/Programs/Python/Python36/libs/python36_d.lib
INCLUDEPATH += $$quote(C:/opencv/build/include)
#INCLUDEPATH += C:/Users/ThinkPad/AppData/Local/Programs/Python/Python36/Lib/site-packages/numpy/core/include
CONFIG(debug, debug|release): {
LIBS += -LC:/opencv/build/x64/vc14/lib \
-lopencv_world411d \
} else:CONFIG(release, debug|release): {
LIBS += -LC:/opencv/build/x64/vc14/lib \
-lopencv_world411 \
}

DISTFILES +=

RESOURCES += \
    res.qrc
