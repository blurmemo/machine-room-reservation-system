#include "adminmenu.h"
#include "ui_adminmenu.h"
#include "admin.h"
#include "updateuser.h"

admin *administrator = new admin;

adminmenu::adminmenu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::adminmenu)
{
    ui->setupUi(this);
}

adminmenu::~adminmenu()
{
    delete ui;
}

void adminmenu::check_reservation()
{
    this->hide();
    administrator->checkReservation();
}



void adminmenu::query_all_classroom()
{
    this->hide();
    administrator->adminQueryAllClassrooms();
}

void adminmenu::query_reservation()
{
    this->hide();
    administrator->queryReservation();
}

void adminmenu::manage_user()
{
    this->hide();
    updateuser *up = new updateuser;
    up->show();
}

void adminmenu::exist()
{
    this->hide();
    administrator->exist();
}
