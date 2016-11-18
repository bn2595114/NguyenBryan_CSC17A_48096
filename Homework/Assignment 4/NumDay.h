/* 
 * File:   NumDay.h
 * Author: Bryan
 *
 * Created on November 18, 2016, 12:42 PM
 */

#ifndef NUMDAY_H
#define	NUMDAY_H

class NumDays
{
private:
    int hours;
public:
    NumDays()
    {
        hours = 0;
    }
    NumDays(int);
    NumDays(float);
    void setHr(int);
    void setDay(float);
    int getHr();
    float getDay();
    operator float();
    NumDays operator++(int);
    NumDays operator--(int);
    NumDays& operator++();
    NumDays& operator--();
};

#endif	/* NUMDAY_H */

