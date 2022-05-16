#include "reservation.h"

Reservation::Reservation()
{

}

Reservation::Reservation(classroom room, teacher teach, QDateTime submitTime, QDateTime reserveTime)
{
    this->room = room;
    this->teach = teach;
    this->submitTime = submitTime;
    this->reserveTime = reserveTime;
}


Reservation::Reservation(classroom room, QDateTime submitTime, QDateTime reserveTime)
{
    this->room = room;
    this->submitTime = submitTime;
    this->reserveTime = reserveTime;
}
