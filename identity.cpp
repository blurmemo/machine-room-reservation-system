#include "identity.h"
#include "mainwindow.h"
#include "adminqueryreservation.h"


identity::identity()
{

}

identity::identity(string id, string name, char gender, int age, string telephone, string academy, string office, string position)
{
    this->id = id;
    this->name = name;
    this->gender = gender;
    this->age = age;
    this->telephone = telephone;
    this->academy = academy;
    this->office = office;
    this->position = position;
}


void identity::queryReservation()
{
    adminqueryreservation *adq = new adminqueryreservation;
    adq->show();
}

void identity::exist()
{
    MainWindow *w = new MainWindow;
    w->show();
}



