/* 
 * File:   MinMax.h
 * Author: Bryan
 *
 * Created on December 3, 2016, 6:41 PM
 */

#ifndef MINMAX_H
#define	MINMAX_H

template <class T>
T Min(T first, T last)
{
    if(first < last) return first;
    else return last;
};

template <class T>
T Max(T first, T last)
{
    if(first < last) return last;
    else return first;
}


#endif	/* MINMAX_H */

