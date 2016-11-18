
#include "Month.h"

int Month::getMonth()
{
    return monthNumber;
}

string Month::getName()
{
    return name;
}

Month Month::operator++(int)
{
    string month[13] = { " ", "January", "February", "March", "April", "May", 
                         "June", "July" , "August", "September", "October", 
                         "November", "December"};
    if(monthNumber == 13)
        monthNumber = 1;
    Month temp(monthNumber);
    name = month[monthNumber];
    monthNumber++;
    return temp;
}

Month Month::operator--(int)
{
    string month[13] = { " ", "January", "February", "March", "April", "May", 
                         "June", "July" , "August", "September", "October", 
                         "November", "December"};
    Month temp(monthNumber);
    name = month[monthNumber];
    monthNumber--;
    
    return temp;
}


Month &Month::operator++()
{
    string month[13] = { " ", "January", "February", "March", "April", "May", 
                         "June", "July" , "August", "September", "October", 
                         "November", "December"};
    ++monthNumber;
    if(monthNumber == 13)
        monthNumber = 1;
    name = month[monthNumber];
    return *this;
}

Month &Month::operator--()
{
    string month[13] = { " ", "January", "February", "March", "April", "May", 
                         "June", "July" , "August", "September", "October", 
                         "November", "December"};
    --monthNumber;
    name = month[monthNumber];
    return *this;
}