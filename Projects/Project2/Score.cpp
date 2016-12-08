#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <iomanip>
using namespace std;
#include "Score.h"

Score::Score()
{
    name = " ";
    wins = 0;
    losses = 0;
    avg = 0;
    games = 0;
    point = 0;
}

Score::Score(string n, int w, int l, float a, int g, int p)
{
    name = n;
    wins = w;
    losses = l;
    avg = a;
    games = g;
    point = p;
}


void Score::out()
{
    cout << "Stats: " << endl;
    cout << "Name: " << name << endl;
    cout << "Wins: " << wins << endl;
    cout << "Losses: " << losses << endl;
    cout << "Win Lose Average: " << setprecision(2) << fixed << avg << endl;
    cout << "Games Played: " << games << endl;
    cout << "Points: " << point << endl;
    
}

Score Score::operator ++(int)
{
    Score temp(name, wins, losses, avg, games, point);
    wins++;
    games++;
    return temp;
}

Score Score::operator --(int)
{
    Score temp(name, wins, losses, avg, games, point);
    losses++;
    games++;
    return temp;
}

void Rank::setRank(float a)
{
    if(a >= 5)
        rank = "Diamond";
    if(a >=4 && a < 5)
        rank = "Platinum";
    if(a >= 3 && a < 4)
        rank = "Gold";
    if(a >=2 && a < 3)
        rank = "Silver";
    if(a < 3) 
        rank = "BRONZE";
    
    
}

