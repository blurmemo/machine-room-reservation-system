#ifndef ADMIN_H
#define ADMIN_H

#include "identity.h"

class admin : public identity
{
public:
    admin();
    admin(string id, string name, char gender, int age, string telephone, string academy, string office, string position);
    ~admin();

public:
    void checkReservation();
    void updateUser();
    void adminQueryAllClassrooms();
};

#endif // ADMIN_H
