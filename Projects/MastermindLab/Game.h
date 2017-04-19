/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Game.h
 * Author: rcc
 *
 * Created on April 19, 2017, 1:09 PM
 */

#ifndef GAME_H
#define GAME_H

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


#endif /* GAME_H */

