/* 
 * File:   Date.h
 * Author: Bryan
 *
 * Created on November 14, 2016, 10:15 PM
 */

#ifndef DATE_H
#define	DATE_H

class Date
{
private:
    int month, day, year;
public:
    void setMonth(int);
    void setDay(int);
    void setYear(int);
    int getMonth() const;
    int getDay() const;
    int getYear() const;
};

#endif	/* DATE_H */

