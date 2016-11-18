/* 
 * File:   Numbers.h
 * Author: Bryan
 *
 * Created on November 18, 2016, 12:05 AM
 */

#ifndef NUMBERS_H
#define	NUMBERS_H

class Numbers
{
private:
    int number;
public:
    void print();
    Numbers(int x)
    {
        number = x;
        print();
    }
    
};

#endif	/* NUMBERS_H */

