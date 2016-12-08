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
    int match;
    int in;
public:
    void setGuess(char* g)
    {guess = g;}
    char* getGuess() const
    {return guess;}
    void setMatch(int n) // matching characters
    {match = n;}
    int getMatch() const
    {return match;}
    void setIn(int i)
    {in = i;}
    int getIn() const
    {return in;}
    ~Guess()
    {delete[] guess;}
};

#endif	/* INGAME_H */

