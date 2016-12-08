/* 
 * File:   Cheater.h
 * Author: Bryan
 *
 * Created on December 8, 2016, 2:59 AM
 */

#ifndef CHEATER_H
#define	CHEATER_H

class Cheater
{
public:
    virtual int inf() = 0;
};

class Hacker : Cheater
{
private:
    int infin;
public:
    Hacker()
    {infin = 0;}
    int inf()
    {infin = 9999;}
    int getIn()
    {return infin;}
    
};

#endif	/* CHEATER_H */

