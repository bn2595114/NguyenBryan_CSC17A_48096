/* 
 * File:   Days.h
 * Author: Bryan
 *
 * Created on November 18, 2016, 12:59 AM
 */

#ifndef DAYS_H
#define	DAYS_H

class DayOfYear
{
private:
    int day;
public:
    void print();
    DayOfYear(int d)
    {
        day = d;
        print();
    }
};


#endif	/* DAYS_H */

