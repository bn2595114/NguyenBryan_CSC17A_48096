/* 
 * File:   Time.h
 * Author: Bryan
 *
 * Created on November 30, 2016, 9:51 PM
 */

#ifndef TIME_H
#define	TIME_H

class Time
{   
protected:
    int hour;
    int min;
public:
    Time()
        {hour = 0; min = 0;}
    Time(int h, int m, int s)
        {hour = h; min = m;}
    int getHr() const
        {return hour;}
    int getMin() const
        {return min;}
};

class MilTime : public Time
{
private:
    int milHours;
public:
    MilTime(int t);
    int getTime() const
        {return milHours;}
};

class TimeClock
{
private:
    int elapse;
public:
    TimeClock();
    TimeClock(int, int);
    int getElapse()
        {return elapse;}
};
#endif	/* TIME_H */

