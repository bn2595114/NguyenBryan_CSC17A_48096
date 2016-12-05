/* 
 * File:   main.cpp
 * Author: Bryan
 *
 * Created on December 5, 2016, 12:25 AM
 */

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
#include "Score.h"

string getName();
void writex(Score&, ofstream&);
void readx(Score&, ifstream&);
int main(int argc, char** argv) {

    ifstream infile;
    ofstream outfile;
    string name;
    int win = 0, lose = 0, game = 0;
    float avg = 0;
    name = getName();
    Score player(name, win, lose, avg, game);
    readx(player, infile);
    player.out();
    return 0;
}

string getName()
{
    string name;
    cout << "What is your name?" << endl;
    cin >> name;
    return name;
}

void writex(Score& play, ofstream& outfile)
{
    outfile.open(play.getName().c_str(), ios::out | ios::binary);
    outfile.write(reinterpret_cast<char*>(&play), sizeof(play));
    outfile.close();
}

void readx(Score& play, ifstream& infile)
{
    infile.open(play.getName().c_str(), ios::in | ios::binary);
    infile.read(reinterpret_cast<char*>(&play), sizeof(play));
    infile.close();
}