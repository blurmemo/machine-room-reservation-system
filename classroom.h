#ifndef CLASSROOM_H
#define CLASSROOM_H

#include<string>
using namespace std;


#include <QVariant>

class classroom
{
private:
    QVariant id;
    QVariant className;
    QVariant classroomType;
    QVariant maxPeople;
    QVariant aircondition;
    QVariant camera;
    QVariant state;

public:
    classroom();
    classroom(QVariant id, QVariant className, QVariant classroomType, QVariant maxPeople, QVariant aircondition, QVariant camera, QVariant state);

public:
    QVariant getId();
    QVariant getClassName();
    QVariant getClassroomType();
    QVariant getMaxPeople();
    QVariant getAircondition();
    QVariant getCamera();
    QVariant getState();

public:

};

#endif // CLASSROOM_H
