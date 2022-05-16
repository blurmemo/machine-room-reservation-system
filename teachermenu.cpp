#include "teachermenu.h"
#include "ui_teachermenu.h"
#include "mainwindow.h"

teachermenu::teachermenu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::teachermenu)
{
    ui->setupUi(this);
}

teachermenu::~teachermenu()
{
    delete ui;
}


void teachermenu::reserveClassrooms()
{
    this->hide();
    teacher->reserve();
}

void teachermenu::queryMyReservation()
{
    this->hide();
    teacher->queryMyReservation();
}

void teachermenu::queryAllClassrooms()
{
    this->hide();
    teacher->teacherQueryAllClassrooms();
}

void teachermenu::exist()
{
    this->hide();
    teacher->exist();
}
