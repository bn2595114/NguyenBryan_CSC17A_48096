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
#include "InGame.h"

string getName();
void instr();
void writex(Score&, ofstream&);
void readx(Score&, ifstream&);
Pattern diff();
void guess(Pattern&, Score&);

int main(int argc, char** argv) {

    srand(static_cast<unsigned int>(time(0)));
    ifstream infile;
    ofstream outfile;
    string name;
    int win = 0, lose = 0, game = 0;
    float avg = 0;
    name = getName();
    Score player(name, win, lose, avg, game);
    instr();
    try{
    readx(player, infile);
    }
    catch(string exception)
    {
        cout << exception;
        writex(player, outfile);
    }
    cout << endl;
    Pattern code;
    code = diff();
    cout << code.code << endl;
    guess(code, player);
    player.out();
    writex(player, outfile);
    delete[] code.code;
    return 0;
}

string getName()
{
    string name;
    cout << "What is your name?" << endl;
    cin >> name;
    cout << endl;
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

void instr()
{
    cout << "Welcome to MasterMind!" << endl;
    cout << "You will have 10 tries to guess the full combo."<< endl;
    cout << "If you guess the correct code in the correct order," <<endl;
    cout << "you win! If not, you lose. Enter a 4 code combo with" << endl;
    cout << "the given characters presented. Characters ARE repeatable." << endl;
    cout << "You will be informed about how many of the characters are " << endl;
    cout << "correct and how many are both correct and right order." << endl;
    cout << "Good luck!" << endl << endl;;
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
    do{
    switch(inN)
    {
        case 1:
        {
            cout << "The code is 4 characters long!" << endl;
            mode.code = new char[4];
            for(int i = 0; i < 4; i++)
                    mode.code[i] = color[rand()%8];
            break;
        }
        case 2:
        {
            cout << "The code is 6 characters long!" << endl;
            mode.code = new char[6];
            for(int i = 0; i < 6; i++)
                mode.code[i] = color[rand()%8];
            break;
        }
        case 3:
        {
            cout << "The code is 8 characters long!" << endl;
            mode.code = new char[8];
            for(int i = 0; i < 8; i++)
                mode.code[i] = color[rand()%8];
            break;
        }
        default: 
        {
            cout << "Invalid input. Enter a valid difficulty." << endl;
            cin >> inN;
        }
    }
    }while(inN < 0 || inN > 3);
    return mode;
}

void guess(Pattern& code, Score& player)
{
    char* guess;
    Guess g;
    cout << "Characters: R, O, Y, G, B, I, V, W" << endl;
    int match = 0;
    for(int i = 0; i < 10; i++)
    {
        cout << "Attempt " << i+1 << endl;
        cout << "Enter Your Characters(no space): " << endl;
        cin >> guess;
        g.setGuess(guess);
        if(g.getGuess() == code.code)
        {
            cout << "Congratulations! You win!" << endl;
            player++;
            return;
        }
    }
    cout << "You lose!" << endl;
        player--;
}