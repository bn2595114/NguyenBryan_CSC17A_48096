#include <cstring>
#include "PersonalData.h"

Data::Data(char* n, char* addr, int a, char* phone)
{
    name = n;
    address = addr;
    age = a;
    number = phone;
    
}

char *Data::getAddress() const 
{
    return address;
}

int Data::getAge() const
{
    return age;
}

char* Data::getName() const
{
    return name;
}

char* Data::getNumber() const
{
    return number;
}