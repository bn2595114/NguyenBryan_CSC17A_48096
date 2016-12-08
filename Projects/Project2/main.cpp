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
Pattern diff(Pattern&);
int menu();
void guess(const Pattern&, Score&, int);

int main(int argc, char** argv) {

    srand(static_cast<unsigned int>(time(0)));
    ifstream infile;
    ofstream outfile;
    string name;
    int win = 0, lose = 0, game = 0, slct;
    float avg = 0;
    char resp;
    
    instr();
    name = getName();
    Score player(name, win, lose, avg, game);
    
    try{
    readx(player, infile);
    }
    catch(string exception)
    {
        cout << exception;
        writex(player, outfile);
    }
    Pattern code;
    
    do{
        readx(player, infile);
        slct = menu();
        if(slct == 1)
        player.out();
        cout << "Entering the game..." << endl;
        code = diff(code);
        cin.ignore();
        cout << code.code;
        guess(code, player, 0);
        writex(player, outfile);
        cout << "Play again? y for YES, n for NO" << endl;
        cin >> resp;
    } while(tolower(resp) == 'y');
    
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



Pattern diff(Pattern& mode)
{
    int inN;
    cout << "Please enter the number of the difficulty. " << endl;
    cout << "1) Easy" << endl;
    cout << "2) Medium" << endl;
    cout << "3) Hard" << endl;
    cin >> inN;
    char color[8] = {'R', 'O', 'Y', 'G', 'B', 'I', 'V', 'W'};
    do{
    switch(inN)
    {
        case 1:
        {
            cout << "The code is 4 characters long!" << endl;
            mode.code = new char[5]; // hold the \0
            for(int i = 0; i < 4; i++)
                    mode.code[i] = color[rand()%8];
            mode.code[4] = '\0';
            break;
        }
        case 2:
        {
            cout << "The code is 5 characters long!" << endl;
            mode.code = new char[6];
            for(int i = 0; i < 5; i++)
                mode.code[i] = color[rand()%8];
            mode.code[5] = '\0';
            break;
        }
        case 3:
        {
            cout << "The code is 6 characters long!" << endl;
            mode.code = new char[7];
            for(int i = 0; i < 6; i++)
                mode.code[i] = color[rand()%8];
            mode.code[6] = '\0';
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

void guess(const Pattern& code, Score& player, int count)
{
    char* guess = new char[strlen(code.code)];
    Guess g;
    cout << "Characters: R, O, Y, G, B, I, V, W" << endl;
    for(int i = 0; i < 10; i++)
    {
        g.setMatch(0);
        cout << "Attempt " << i+1 << endl;
        cout << "Enter Your Characters(no space): " << endl;
        cin >> guess;
        while(strlen(guess) > strlen(code.code))
        {
            cout << "Too many characters! Please enter a valid combination.";
            cout << endl;
            cin >> guess;
        }
        while(strlen(guess) < strlen(code.code))
        {
            cout << "Too few characters! Please enter a valid combination.";
            cout << endl;
            cin >> guess;
        }
        for(int j = 0; j < strlen(guess); j++)
        {
            guess[j] = toupper(guess[j]);
        }
        g.setGuess(guess);
        count = 0;
        for(int j = 0; j < strlen(code.code); j++ )
        {
            if(code.code[j] == g.getGuess()[j])
                ++count;
        }
        g.setMatch(count);
        
        cout << "There are " << g.getMatch() << " characters ";
        cout << "that are in the correct position and ";
        count = 0;
        int mult; // for unwanted bonus count
        
        for(int j = 0; j < strlen(code.code); j++) // DOES NOT COMPLETELY WORK
        {
            mult = 0;
            for(int k = 0; k < strlen(code.code); k++)
            {
                if(g.getGuess()[j] == code.code[k])
                {
                    ++mult;
                if(mult == 1)
                    count++;
                }
            }
        }
        g.setIn(count);       
        cout << g.getIn() << " correct characters in your guess";
        cout << endl;
        
        if(strcmp(code.code, g.getGuess()) == 0)
        {
            cout << "Congratulations! You win!" << endl;
            player++;
            delete[] guess;
            return;
        }
    }
    cout << "You lose!" << endl;
        player--;
        delete[] guess;
}

int menu()
{
    char* r;
    cout << "Enter a number." << endl;
    cout << "1) View Player Statistics" << endl;
    cout << "2) Continue to Game" << endl;
    cin >> r;
    while(atoi(r)!=1 && atoi(r)!=2)
    {
        cout << "ERROR. INVALID INPUT. PLEASE ENTER A VALID NUMBER" << endl;
        cin >> r;
    }
    return atoi(r);
}