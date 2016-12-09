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
protected:
    string name;
    int wins;
    int losses;
    float avg;
    int games;
    int point;
public:
    Score();
    Score(string, int, int, float, int, int);
    string getName() const
    {return name;}
    void setWin(int w)
    {wins = w;}
    void setLose(int l)
    {losses = l;}
    void setAvg(int w, int l)
    {   
        if(l == 0 && w>0) avg = 999999;
        else if(l == 0 && w == 0) avg = 0;
        else avg = static_cast<float>(w)/l;
    }
    float getAvg()
    {return avg;}
    void setGame(int g)
    {games = g;}
    void out();
    int getWin() const
    {return wins;}
    int getLose() const
    {return losses;}
    void setPoints(int p)
    {point = p;}
    virtual int getPoints() const    // VIRTUAL
    {return point;}
    Score operator++(int); // for wins
    Score operator--(int); // for losses
};

class Rank : public Score
{
private:
    string rank;
public:
    Rank()
    {rank = " ";}
    void setRank(float);
    string getRank() const
    {return rank;}
};

class Points : public Score
{
public:
    Points() : Score()
    {point = 0;}
    Points(int p) : Score()
    {point = p;}
    void loseP()
    {point -= 1;}
    int getPoints() const
    {return point;}
};

class Store : public Score
{
public:
    Store()
    {point = 0;}
    void setPoints(int p)
    {point = p;}
    int getP() const
    {return point;}
    void buy()
    {
        point -= 5;
    }
};
#endif	/* BINARYFILE_H */

