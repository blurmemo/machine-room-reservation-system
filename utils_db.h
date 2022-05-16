#ifndef UTILS_DB_H
#define UTILS_DB_H

#include "globe.h"

class utils_db
{
public:
    utils_db();

public:
    QSqlDatabase getDatabase();

    bool queryUser(QString username, QString password, string type);

    bool queryUser(QString username);

    bool insertUser(QString username, QString password);

    bool deleteUser(QString username);

    bool updateUser(QString username, QString password);

    bool uppdateAdmin_ReservationTableState(QString classroomId, QString teacherId, QString reserveTime, QString type);

    bool delAdminCheckedReservation(QString classroomId, QString teacherId);

    bool updateClassroomState(QString classroomId, QString reserveTime, QString type);

    bool delClassroom(QString classroomId, QString reserveTime);

    bool setAllClassroomsEmpty();

    bool setAllClassroomsReserve();

    QVariantList queryAllClassrooms();

    bool teacherUpdatehisReserveTime(QString classroomId, QString reserveTime, QString upDateTime, QString state);

    bool teacherUpdatehisReserveClassroom(QString classroomId, QString reserveTime, QString upClassroomId, QString state);

    bool teacherDelSingleReservatiom(QString id, QString classroomId, QString reserveTime);

    bool teacherUpdatehisReserveCheck(QString classroomId, QString reserveTime, QString state);

    bool classroomStateUpdate(QString classroomId, QString reserveTime, QString state);

    bool addReservation(QString classroomId, QString teacherId, QString teacherName, QString submitTime, QString reserveTime);

    QString searchNameById(QString teacherId);

    QStringList queryALLClassroomIdByTimeandState(QString time, QString state);

    QStringList queryAbleReserveTimeByClassroomId(QString id, QString state);
};

#endif // UTILS_DB_H
