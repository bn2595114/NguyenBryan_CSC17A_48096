/* 
 * File:   Month.h
 * Author: Bryan
 *
 * Created on November 18, 2016, 1:24 PM
 */

#ifndef MONTH_H
#define	MONTH_H
#include <string>
using std::string;

class Month
{
private:
    string name;
    int monthNumber;
public:
    Month()
    {
        name = "January";
        monthNumber = 1;
    }
    Month(string n)
    {
        name = n;
    }
    Month(int m)
    {
        monthNumber = m;
    }
    void setName(string n)
    {
        name = n;
    }
    void setMonth(int m)
    {
        monthNumber = m;
    }
    string getName();
    int getMonth();
    Month operator++(int);
    Month operator--(int);
    Month& operator++();
    Month& operator--();
};


#endif	/* MONTH_H */

