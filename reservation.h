#ifndef RESERVATION_H
#define RESERVATION_H

#include <string>
#include <QDateTime>
#include "classroom.h"
#include "teacher.h"
using namespace std;


class Reservation
{
private:
    classroom room;
    teacher teach;
    QDateTime submitTime;
    QDateTime reserveTime;


public:
    Reservation();
    Reservation(classroom room, teacher teach, QDateTime submitTime, QDateTime reserveTime);
    Reservation(classroom room, QDateTime submitTime, QDateTime reserveTime);
};

#endif // RESERVATION_H
