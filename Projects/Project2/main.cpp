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
#include "Pattern.h"

string getName();
void writex(Score&, ofstream&);
void readx(Score&, ifstream&);
Pattern diff();

int main(int argc, char** argv) {

    srand(static_cast<unsigned int>(time(0)));
    ifstream infile;
    ofstream outfile;
    string name;
    int win = 0, lose = 0, game = 0;
    float avg = 0;
    name = getName();
    Score player(name, win, lose, avg, game);
    
    try{
    readx(player, infile);
    }
    catch(string exception)
    {
        cout << exception;
    }
    if(!infile)
        writex(player, outfile);
    
    
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
    if(!outfile)
    {
        string exception = "ERROR. Unable to open file";
        throw exception;
    }
    outfile.write(reinterpret_cast<char*>(&play), sizeof(play));
    outfile.close();
}

void readx(Score& play, ifstream& infile)
{
    infile.open(play.getName().c_str(), ios::in | ios::binary);
    if(!infile) 
    {
        string exception = "Unable to find user. Creating File...";
        throw exception;
    }
    infile.read(reinterpret_cast<char*>(&play), sizeof(play));
    infile.close();
}

Pattern diff()
{
    int inN;
    cout << "Please enter the number of the difficulty. " << endl;
    cout << "1) Easy" << endl;
    cout << "2) Medium" << endl;
    cout << "3) Hard" << endl;
    
    cin >> inN;
    Pattern mode;
    char color[8] = {'R', 'O', 'Y', 'G', 'B', 'I', 'V', 'W'};
    switch(inN)
    {
        case 1:
        {
            mode.code = new char[4];
        }
        case 2:
        {
            mode.code = new char[6];
        }
        case 3:
        {
            mode.code = new char[8];
        }
        default:
            cout << "Invalid input. Program Terminating.";
    }
}
