/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Bryan Nguyen
 *
 * Created on April 19, 2017, 12:57 PM
 */

#include <cstdlib>
#include <iostream>
#include <cstring>
using namespace std;
#include "Game.h"

void seq(char*);  // code sequence
void guess(char*, int);

int main(int argc, char** argv) {
    srand(static_cast<unsigned int>(time(0)));
    char* code;
    code = new char[5];
    seq(code);
    guess(code, 0);
    
    
    
    delete[] code;
    return 0;
}

void seq(char* c)
{
    char color[8] = {'R', 'O', 'Y', 'G', 'B', 'I', 'V', 'W'};
    for(int i=0; i < 4; i++)
        c[i] = color[rand()%8];
    c[4] = '\0';
}

void guess(char* code, int count)
{
    char resp;
    char* guess = new char[strlen(code)];
    char color[8] = {'R', 'O', 'Y', 'G', 'B', 'I', 'V', 'W'};
    Guess g;
    int trial = 10;
    cout << "Characters: R, O, Y, G, B, I, V, W" << endl;
    cout << "You have " << trial << " attempts ";
    cout << "to guess your " << strlen(code) << " character long ";
    cout << "code" << endl;
    char* temp = new char[5];
    for(int i = 0; i < strlen(code); i++)
        temp[i] = code[i];
    for(int i = 0; i < trial; i++)
    {
        cout << "Attempt " << i+1 << endl;
        cout << "Enter Your Characters(no space): " << endl;
        
        cin >> guess;
        
        do{
        for(int j = 0; j < strlen(guess); j++)
        {
            count = 0;
            for(int k = 0; k < 8; k++)
            {
                if(toupper(guess[j]) == color[k])
                    count++;
            }
            if(count != 1)
            {
                cout << "One or more of your characters are not in the ";
                cout << "array. Please enter a valid code." << endl;
                cin >> guess;
            }
        }
        }while(count != 1);
        
        while(strlen(guess) > strlen(code))
        {
            cout << "Too many characters! Please enter a valid combination.";
            cout << endl;
            cin >> guess;
        }
        while(strlen(guess) < strlen(code))
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

        g.setMatch(count);
        
        cout << "There are " << g.getMatch() << " characters ";
        cout << "that are in the correct position and ";
        count = 0;
        int mult = 0; // for unwanted bonus count
        for(int j = 0; j < strlen(code); j++)
        {
            for(int k = 0; k < strlen(code); k++)
            {
                if(g.getGuess()[j] == temp[k])
                {
                    ++mult;
                    temp[k] = ' ';
                }
            }
            count += mult;
                mult = 0;
        }
        for(int j = 0; j < strlen(code); j++)
        temp[j] = code[j];
        g.setIn(count);       
        cout << g.getIn() << " correct characters in your guess";
        cout << endl;
        
        if(strcmp(code, g.getGuess()) == 0)
        {
            cout << "Congratulations! You win!" << endl;
            
            delete[] temp;
            return;
        }
    }
    cout << "You lose!" << endl;
        delete[] temp;
}