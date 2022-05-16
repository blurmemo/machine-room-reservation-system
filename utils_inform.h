#ifndef UTILS_INFORM_H
#define UTILS_INFORM_H

#include <QMessageBox>
#include <string>

class utils_inform
{
public:
    utils_inform();

public:
    void info_warn(bool ok, QWidget *w, const char* info, const char* warn);
    void info(QWidget *w, const char* info);
    void warn(QWidget *w, const char* warn);
};

#endif // UTILS_INFORM_H
