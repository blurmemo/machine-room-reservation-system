#include "teacher.h"
#include "teachermanageclassrooms.h"
#include "teacherqueryhisreservation.h"
#include "teacherreserveclassroom.h"

teacher::teacher()
{

}

teacher::teacher(string id, string name, char gender, int age, string telephone, string academy, string office, string position)
    : identity(id, name, gender, age, telephone, academy, office, position)
{

}



void teacher::reserve()
{
    teacherreserveclassroom *trc = new teacherreserveclassroom;
    trc->show();
}

void teacher::queryMyReservation()
{
    teacherqueryhisreservation *tqhs = new teacherqueryhisreservation;
    tqhs->show();
}

void teacher::teacherQueryAllClassrooms()
{
    teachermanageclassrooms *teacher = new teachermanageclassrooms;
    teacher->show();
}

