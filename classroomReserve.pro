QT       += core gui
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17
RC_ICONS = logo.ico

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    admin.cpp \
    admincheckreservation.cpp \
    adminmanageclassrooms.cpp \
    adminmenu.cpp \
    adminqueryreservation.cpp \
    classroom.cpp \
    globe.cpp \
    identity.cpp \
    main.cpp \
    mainwindow.cpp \
    reservation.cpp \
    teacher.cpp \
    teachermanageclassrooms.cpp \
    teachermenu.cpp\
    teacherqueryhisreservation.cpp \
    teacherreserveclassroom.cpp \
    updateuser.cpp \
    utils_db.cpp \
    utils_inform.cpp \
    utils_tablemodel.cpp

HEADERS += \
    admin.h \
    admincheckreservation.h \
    adminmanageclassrooms.h \
    adminmenu.h \
    adminqueryreservation.h \
    classroom.h \
    globe.h \
    identity.h \
    mainwindow.h \
    reservation.h \
    teacher.h \
    teachermanageclassrooms.h \
    teachermenu.h\
    teacherqueryhisreservation.h \
    teacherreserveclassroom.h \
    updateuser.h \
    utils_db.h \
    utils_inform.h \
    utils_tablemodel.h

FORMS += \
    admincheckreservation.ui \
    adminmanageclassrooms.ui \
    adminmenu.ui \
    adminqueryreservation.ui \
    teachermanageclassrooms.ui \
    teachermenu.ui\
    mainwindow.ui \
    teacherqueryhisreservation.ui \
    teacherreserveclassroom.ui \
    updateuser.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
