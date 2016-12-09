/* 
 * File:   Count.h
 * Author: Bryan
 *
 * Created on December 9, 2016, 1:29 AM
 */
#include <string>
using namespace std;
#ifndef COUNT_H
#define	COUNT_H

class TotalG
{
private:
    static int games;
public:
    TotalG()
    {games = 0;}
    TotalG(string)
    {games++;}
    int getPCount() const
    {return games;}
    void setG(int g)
    {games = g;}
    
};


#endif	/* COUNT_H */

