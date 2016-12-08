#include <iostream>
#include <fstream>
#include <cstring>
#include <string>

using namespace std;
#include "Score.h"

Score::Score(string n, int w, int l, float a, int g)
{
    name = n;
    wins = w;
    losses = l;
    avg = a;
    games = g;
}

void Score::out()
{
    cout << "Stats: " << endl;
    cout << "Name: " << name << endl;
    cout << "Wins: " << wins << endl;
    cout << "Losses: " << losses << endl;
    cout << "Win Lose Average: " << avg << endl;
    cout << "Games Played: " << games << endl << endl;
    
}

Score Score::operator ++(int)
{
    Score temp(name, wins, losses, avg, games);
    wins++;
    games++;
    return temp;
}

Score Score::operator --(int)
{
    Score temp(name, wins, losses, avg, games);
    losses++;
    games++;
    return temp;
}