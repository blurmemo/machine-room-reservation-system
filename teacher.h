#ifndef TEACHER_H
#define TEACHER_H

#include "identity.h"

class teacher : public identity

{
public:
    teacher();
    teacher(string id, string name, char gender, int age, string telephone, string academy, string office, string position);

public:
    void reserve();
    void queryMyReservation();
    void teacherQueryAllClassrooms();
};

#endif // TEACHER_H
