#ifndef ADMINMENU_H
#define ADMINMENU_H

#include <QMainWindow>

namespace Ui {
class adminmenu;
}

class adminmenu : public QMainWindow
{
    Q_OBJECT

public:
    explicit adminmenu(QWidget *parent = nullptr);
    ~adminmenu();

private:
    Ui::adminmenu *ui;

private slots:
    void check_reservation();
    void query_all_classroom();
    void query_reservation();
    void manage_user();
    void exist();
};

#endif // ADMINMENU_H
