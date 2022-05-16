#ifndef TEACHERMENU_H
#define TEACHERMENU_H

#include <QMainWindow>
#include "teacher.h"

namespace Ui {
class teachermenu;
}

class teachermenu : public QMainWindow
{
    Q_OBJECT

public:
    explicit teachermenu(QWidget *parent = nullptr);
    ~teachermenu();

private:
    Ui::teachermenu *ui;
    teacher *teacher;

private slots:
    void reserveClassrooms();
    void queryMyReservation();
    void queryAllClassrooms();
    void exist();

};

#endif // TEACHERMENU_H
