#include "classroom.h"

classroom::classroom()
{

}


classroom::classroom(QVariant id, QVariant className, QVariant classroomType, QVariant maxPeople, QVariant aircondition, QVariant camera, QVariant state)
{
    this->id = id;
    this->className = className;
    this->classroomType = classroomType;
    this->maxPeople = maxPeople;
    this->aircondition = aircondition;
    this->camera = camera;
    this->state = state;
}


QVariant classroom::getId()
{
    return this->id;
}
QVariant classroom::getClassName()
{
    return this->className;
}
QVariant classroom::getClassroomType()
{
    return this->classroomType;
}
QVariant classroom::getMaxPeople()
{
    return this->maxPeople;
}
QVariant classroom::getAircondition()
{
    return this->aircondition;
}
QVariant classroom::getCamera()
{
    return this->camera;
}
QVariant classroom::getState()
{
    return this->state;
}
