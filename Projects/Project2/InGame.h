/* 
 * File:   InGame.h
 * Author: Bryan
 *
 * Created on December 5, 2016, 8:45 PM
 */

#ifndef INGAME_H
#define	INGAME_H

class Guess
{
private:
    char* guess;
public:
    void setGuess(char* g)
    {guess = g;}
    char* getGuess()
    {return guess;}
};

#endif	/* INGAME_H */

