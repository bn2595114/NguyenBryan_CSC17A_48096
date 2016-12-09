/* 
 * File:   Absolute.h
 * Author: Bryan
 *
 * Created on December 3, 2016, 7:47 PM
 */

#ifndef ABSOLUTE_H
#define	ABSOLUTE_H

template <class T>
T Absolute(T num)
{
    if(num < 0) return num*(-1);
    else return num;
}


#endif	/* ABSOLUTE_H */

