#ifndef IDENTITY_H
#define IDENTITY_H

#include<string>
using namespace std;

class identity
{
private:
    string id;
    string name;
    char gender;
    int age;
    string telephone;
    string academy;
    string office;
    string position;

public:
    identity();
    identity(string id, string name, char gender, int age, string telephone, string academy, string office, string position);

public:
    void queryReservation();
    void exist();
};

#endif // IDENTITY_H
