#include "admin.h"
#include "admincheckreservation.h"
#include "updateuser.h"
#include "adminmanageclassrooms.h"

admin::admin()
{

}

admin::admin(string id, string name, char gender, int age, string telephone, string academy, string office, string position)
    : identity(id, name, gender, age, telephone, academy, office, position)
{

}


void admin::checkReservation()
{
    admincheckreservation *check = new admincheckreservation;
    check->show();
}

void admin::updateUser()
{
    updateuser *update = new updateuser;
    update->show();
}

void admin::adminQueryAllClassrooms()
{
    adminmanageclassrooms *admc = new adminmanageclassrooms;
    admc->show();
}


