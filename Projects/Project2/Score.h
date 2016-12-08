/* 
 * File:   BinaryFile.h
 * Author: Bryan
 *
 * Created on December 5, 2016, 12:52 AM
 */
#include <string>
using namespace std;

#ifndef BINARYFILE_H
#define	BINARYFILE_H



class Score
{
private:
    string name;
    int wins;
    int losses;
    float avg;
    int games;
public:
    Score(string, int, int, float, int);
    string getName() const
    {return name;}
    void setWin(int w)
    {wins = w;}
    void setLose(int l)
    {losses = l;}
    void setAvg(int w, int l)
    {   
        if(l == 0 && w>l)
            avg = 1;
        avg = static_cast<float>(w/l);
    }
    void setGame(int g)
    {games = g;}
    void out();
    int getWin() const
    {return wins;}
    int getLose() const
    {return losses;}
    Score operator++(int); // for wins
    Score operator--(int); // for losses
};

#endif	/* BINARYFILE_H */

