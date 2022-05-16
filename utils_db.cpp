#include "utils_db.h"
#include "classroom.h"

utils_db::utils_db()
{
    db.setHostName(QString::fromStdString(hostname));
    db.setPort(3306);
    db.setDatabaseName(QString::fromStdString(databaseName));
    db.setUserName(QString::fromStdString(databaseUsername));
    db.setPassword(QString::fromStdString(databasePassword));
    bool connectState = db.open();
    if (connectState){
        qDebug() << "success to connect databse system_db";
    }
    else {
        qDebug() << "fail to connect databse system_db";
    }
}

QSqlDatabase utils_db::getDatabase()
{
    return db;
}

bool utils_db::queryUser(QString username)
{
    QSqlQuery query(db);
    query.prepare("select * from user_teacher where username = ?");
    query.addBindValue(username);
    query.exec();
    return query.first();
}

bool utils_db::queryUser(QString username, QString password, string type)
{
    QSqlQuery query(db);
    if(type.compare("admin") == 0)
    {
        query.prepare("select * from user_admin where username = ? and password = ?");
    }
    else if(type.compare("teacher") == 0){
        query.prepare("select * from user_teacher where username = ? and password = ?");
    }
    else{
        return false;
    }
    query.addBindValue(username);
    query.addBindValue(password);
    query.exec();
    return query.first();
}

bool utils_db::insertUser(QString username, QString password)
{
    QSqlQuery insert(db);
    if(username == nullptr)
    {
        return false;
    }
    if(!queryUser(username, password, "teacher"))
    {
        insert.prepare("insert into user_teacher (username, password) values (?, ?)");
        insert.addBindValue(username);
        insert.addBindValue(password);
        return insert.exec();
    }
    return false;
}

bool utils_db::deleteUser(QString username)
{
    QSqlQuery del(db);
    del.prepare("delete from user_teacher where username = ?");
    del.addBindValue(username);
    return del.exec();
}

bool utils_db::updateUser(QString username, QString password)
{
    QSqlQuery update(db);
    if(!queryUser(username, password, "teacher"))
    {
        update.prepare("update user_teacher set username = ? , password = ? where username = ?");
        update.addBindValue(username);
        update.addBindValue(password);
        update.addBindValue(username);
        return update.exec();
    }
    return false;
}

bool utils_db::delAdminCheckedReservation(QString classroomId, QString teacherId)
{
     QSqlQuery del(db);
     del.prepare("delete from admin_reservation where classroomId = ? and teacherId = ?");
     del.addBindValue(classroomId);
     del.addBindValue(teacherId);
     return del.exec();

}

bool utils_db::updateClassroomState(QString classroomId, QString reserveTime, QString type)
{
    QSqlQuery update(db);
    update.prepare("update classroom set state = ? where id = ? and reserveTime = ?");
    update.addBindValue(type);
    update.addBindValue(classroomId);
    update.addBindValue(reserveTime);
    return update.exec();
}

bool utils_db::delClassroom(QString classroomId, QString reserveTime)
{
    QSqlQuery del(db);
    del.prepare("delete from classroom where id = ? and reserveTime = ?");
    del.addBindValue(classroomId);
    del.addBindValue(reserveTime);
    return del.exec();
}

bool utils_db::setAllClassroomsEmpty()
{
    QSqlQuery update(db);
    update.prepare("update classroom set state = '空置'");
    return update.exec();
}

bool utils_db::setAllClassroomsReserve()
{
    QSqlQuery update(db);
    update.prepare("update classroom set state = '已预约'");
    return update.exec();
}

QVariantList utils_db::queryAllClassrooms()
{
    QVariantList classrooms;
    QSqlQuery query(db);
    query.prepare("select * from classroom");
    query.exec();
    while(query.next())
    {
        QVariant id = query.value("id");
        QVariant className = query.value("className");
        QVariant classroomType = query.value("classroomType");
        QVariant maxPeople = query.value("maxPeople");
        QVariant aircondition = query.value("aircondition");
        QVariant camera = query.value("camera");
        QVariant state = query.value("state");
        classroom classroom(id, className, classroomType, maxPeople, aircondition, camera, state);
        classrooms.append(QVariant::fromValue(classroom));
    }
    return classrooms;
}

bool utils_db::uppdateAdmin_ReservationTableState(QString classroomId, QString teacherId, QString reserveTime, QString type)
{
    QSqlQuery update(db);
    update.prepare("update admin_reservation set state = ? where classroomId = ? and teacherId = ? and reserveTime = ?");
    update.addBindValue(type);
    update.addBindValue(classroomId);
    update.addBindValue(teacherId);
    update.addBindValue(reserveTime);
    return update.exec();
}

bool utils_db::teacherUpdatehisReserveTime(QString classroomId, QString reserveTime, QString upDateTime, QString state)
{
    QSqlQuery update(db);
    if(teacherUpdatehisReserveCheck(classroomId, upDateTime, "空置"))
    {
        classroomStateUpdate(classroomId, upDateTime, "已预约");
        classroomStateUpdate(classroomId, reserveTime, "空置");
        update.prepare("update admin_reservation set reserveTime = ? where classroomId = ? and reserveTime = ? and state = ?");
        update.addBindValue(upDateTime);
        update.addBindValue(classroomId);
        update.addBindValue(reserveTime);
        update.addBindValue(state);
        return update.exec();
    }
    return false;
}

bool utils_db::teacherUpdatehisReserveCheck(QString classroomId, QString reserveTime, QString state)
{
    QSqlQuery check(db);
    check.prepare("select * from classroom where id = ? and reserveTime = ? and state = ?");
    check.addBindValue(classroomId);
    check.addBindValue(reserveTime);
    check.addBindValue(state);
    check.exec();
    return check.first();
}


bool utils_db::teacherUpdatehisReserveClassroom(QString classroomId, QString reserveTime, QString upClassroomId, QString state)
{
    QSqlQuery update(db);
    if(teacherUpdatehisReserveCheck(upClassroomId, reserveTime, "空置"))
    {
        classroomStateUpdate(upClassroomId, reserveTime, "已预约");
        classroomStateUpdate(classroomId, reserveTime, "空置");
        update.prepare("update admin_reservation set classroomId = ? where classroomId = ? and reserveTime = ? and state = ?");
        update.addBindValue(upClassroomId);
        update.addBindValue(classroomId);
        update.addBindValue(reserveTime);
        update.addBindValue(state);
        return update.exec();
    }
    return false;
}

bool utils_db::teacherDelSingleReservatiom(QString id, QString classroomId, QString reserveTime)
{
    QSqlQuery del(db);
    del.prepare("delete from admin_reservation where teacherId = ? and classroomId = ? and reserveTime = ?");
    del.addBindValue(id);
    del.addBindValue(classroomId);
    del.addBindValue(reserveTime);
    return del.exec();
}

bool utils_db::classroomStateUpdate(QString classroomId, QString reserveTime, QString state)
{
    QSqlQuery update(db);
    update.prepare("update classroom set state = ? where id = ? and reserveTime = ?");
    update.addBindValue(state);
    update.addBindValue(classroomId);
    update.addBindValue(reserveTime);
    return update.exec();
}

bool utils_db::addReservation(QString classroomId, QString teacherId, QString teacherName, QString submitTime, QString reserveTime)
{
    QSqlQuery add(db);
    add.prepare("insert into admin_reservation (classroomId, teacherId, teacherName, submitTime, reserveTime, state) values (?, ?, ?, ?, ?, '待审核')");
    add.addBindValue(classroomId);
    add.addBindValue(teacherId);
    add.addBindValue(teacherName);
    add.addBindValue(submitTime);
    add.addBindValue(reserveTime);
    return add.exec();
}

QString utils_db::searchNameById(QString teacherId)
{
    QSqlQuery query(db);
    query.prepare("select name from teacher where id = ?");
    query.addBindValue(teacherId);
    query.exec();
    QSqlRecord rec = query.record();
    QString name;
    while(query.next())
    {
        rec = query.record();
        name = query.value("name").toString();
    }
    return name;
}


QStringList utils_db::queryALLClassroomIdByTimeandState(QString time, QString state)
{
    QSqlQuery query(db);
    query.prepare("select id from classroom where reserveTime = ? and state = ?");
    query.addBindValue(time);
    query.addBindValue(state);
    query.exec();
    QSqlRecord rec = query.record();
    QString name;
    QStringList ids;
    while(query.next())
    {
        rec = query.record();
        ids.append(query.value("id").toString());
    }
    return ids;
}

QStringList utils_db::queryAbleReserveTimeByClassroomId(QString id, QString state)
{
    QSqlQuery query(db);
    query.prepare("select reserveTime from classroom where id = ? and state = ?");
    query.addBindValue(id);
    query.addBindValue(state);
    query.exec();
    QSqlRecord rec = query.record();
    QString name;
    QStringList reserveTime;
    while(query.next())
    {
        rec = query.record();
        reserveTime.append(query.value("reserveTime").toString());
    }
    return reserveTime;
}
