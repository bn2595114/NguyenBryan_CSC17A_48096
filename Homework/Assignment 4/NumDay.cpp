
#include "NumDay.h"

NumDays::NumDays(int h)
{
    hours = h;
}

NumDays::NumDays(float d)
{
    hours = d*8.0;
}

void NumDays::setHr(int h)
{
    h = getHr();
}

void NumDays::setDay(float d)
{
    d = getDay();
}

int NumDays::getHr()
{
    return hours;
}

float NumDays::getDay()
{
    return (hours/8.0);
}

NumDays NumDays::operator++(int)
{
    NumDays temp(hours);
    hours++;
    return temp;
}

NumDays NumDays::operator--(int)
{
    NumDays temp(hours);
    hours--;
    return temp;
}

NumDays& NumDays::operator++()
{
    ++hours;
    return *this;
}

NumDays& NumDays::operator--()
{
    --hours;
    return *this;
}