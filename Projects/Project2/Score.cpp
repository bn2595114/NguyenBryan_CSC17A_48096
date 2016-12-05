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
    cout << "Average Turns Guessed: " << avg << endl;
    cout << "Games Played: " << games << endl;
    
}