#include "utils_inform.h"

utils_inform::utils_inform()
{

}


void utils_inform::info_warn(bool ok, QWidget *w, const char* info, const char* warn)
{
    if(ok)
    {

        QMessageBox::information(w ,w->tr("提示"), w->tr(info));
    }
    else{
        QMessageBox::warning(w, "警告", warn, QMessageBox::Yes);
    }
}

void utils_inform::info(QWidget *w, const char* info)
{
    QMessageBox::information(w ,w->tr("提示"), w->tr(info));
}


void utils_inform::warn(QWidget *w, const char* warn)
{
    QMessageBox::warning(w, "警告", warn, QMessageBox::Yes);
}
