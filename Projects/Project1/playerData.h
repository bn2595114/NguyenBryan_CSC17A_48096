/* 
 * File:   playerData.h
 * Author: Bryan
 *
 * Created on October 27, 2016, 2:00 AM
 */

#ifndef PLAYERDATA_H
#define	PLAYERDATA_H

struct Player
{
    char* name;
    int easy;   // number of easy games
    int medium; // number of medium games
    int hard;   // number of hard games    
    int win;    // wins
    int lose;   // losses
    char* word; // word length
    float winL;   // win lose ratio
    int* guess;  // number of guesses in each game
    float avgG; // average number of guesses of all games
};


#endif	/* PLAYERDATA_H */

