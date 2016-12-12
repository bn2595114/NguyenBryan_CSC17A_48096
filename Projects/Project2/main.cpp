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
using namespace std;
#include "Score.h"
#include "Pattern.h"
#include "InGame.h"
#include "Cheater.h"
#include "BonusTemplate.h"
#include "Count.h"

string getName();
void instr();
void writex(Score&, ofstream&);
void readx(Score&, ifstream&);
void total(TotalG&, ofstream&);
void total(TotalG&, ifstream&);
Pattern diff(Pattern&, Points&, Hacker&);
int menu();
void guess(const Pattern&, Score&, int, Points&);
void bonus();
int item();

int main(int argc, char** argv) {
    
    srand(static_cast<unsigned int>(time(0)));
    ifstream infile;
    ofstream outfile;
    string name, g;
    int win = 0, lose = 0, game = 0, slct, points = 0;
    float avg = 0;
    char resp;
    Points pnt;
    name = getName();
    Score player(name, win, lose, avg, game, points);
    Rank rank;
    instr();
    Hacker ch;
    ch.inf();
    Pattern code;
    TotalG user(name);
    try{
    readx(player, infile);
    }
    catch(string exception)
    {
        cout << exception;
        writex(player, outfile);
    }
    try{
        total(user, infile);
    }
    catch(string exception)
    {
        cout << exception;
        total(user, outfile);
    }
    
    do{
        readx(player, infile);
        slct = menu();
        if(slct == 1)
        {
            player.setAvg(player.getWin(), player.getLose());
            player.out();
            rank.setRank(player.getAvg());
            cout << "Rank: " << rank.getRank() << endl;
        }
        if(slct == 3)
        {
            int sell = 0;
            Store buy;
            buy.setPoints(player.getPoints());
            sell = item();
            if(sell > 0 && sell < 7 && buy.getPoints() > 4)
            {
                buy.buy();
                cout << "You bought the item!" << endl;
            }
            else
                cout << "You do not have enough points!" << endl;
            player.setPoints(buy.getPoints());
            cout << "Points Remaining: " << player.getPoints() << endl;
        }
        cout << "Entering the game..." << endl;
        code = diff(code, pnt, ch);
        cin.ignore();
        guess(code, player, 0, pnt);
        player.setPoints(pnt.getPoints());
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
        string exception = "ERROR. Unable to open file\n";
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
        string exception = "Unable to find user. Creating File...\n";
        throw exception;
    }
    infile.read(reinterpret_cast<char*>(&play), sizeof(play));
    infile.close();
}

void total(TotalG& t, ofstream& outfile)
{
    outfile.open("TotalPlayers", ios::out | ios::binary);
    if(!outfile)
    {
        string exception = "ERROR. Unable to open file\n";
        throw exception;
    }
    outfile.write(reinterpret_cast<char*>(&t), sizeof(t));
    outfile.close();
}

void total(TotalG& t, ifstream& infile)
{
    infile.open("TotalPlayers", ios::in | ios::binary);
    if(!infile) 
    {
        string exception = "Unable to open file. Creating File...\n";
        throw exception;
    }
    infile.read(reinterpret_cast<char*>(&t), sizeof(t));
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



Pattern diff(Pattern& mode, Points& p, Hacker& h)
{
    int inN;
    cout << "Please enter the number of the difficulty. " << endl;
    cout << "1) Easy" << endl;
    cout << "2) Medium" << endl;
    cout << "3) Hard" << endl;
    cout << "4) Custom Mode" << endl;
    cout << "5) Cheating Mode" << endl;
    cin >> inN;
    char color[8] = {'R', 'O', 'Y', 'G', 'B', 'I', 'V', 'W'};
    do{
    switch(inN)
    {
        case 1:
        {
            cout << "You get 1 point for playing easy mode!" << endl;
            bonus();
            p.setPoints(p.getPoints()+1);
            cout << "The code is 4 characters long!" << endl;
            mode.code = new char[5]; // hold the \0
            for(int i = 0; i < 4; i++)
                    mode.code[i] = color[rand()%8];
            mode.code[4] = '\0';
            break;
        }
        case 2:
        {
            cout << "You get 2 points for playing medium mode!" << endl;
            bonus();
            p.setPoints(p.getPoints()+2);
            cout << "The code is 5 characters long!" << endl;
            mode.code = new char[6];
            for(int i = 0; i < 5; i++)
                mode.code[i] = color[rand()%8];
            mode.code[5] = '\0';
            break;
        }
        case 3:
        {
            cout << "You get 3 point for playing hard mode!" << endl;
            bonus();
            p.setPoints(p.getPoints()+3);
            cout << "The code is 6 characters long!" << endl;
            mode.code = new char[7];
            for(int i = 0; i < 6; i++)
                mode.code[i] = color[rand()%8];
            mode.code[6] = '\0';
            break;
        }
        case 4:
        {
            int lng;
            cout << "You get to choose this round's mechanics!" << endl;
            cout << "No points will be awarded for this mode" << endl;
            cout << "How long do you want that character string to be?" << endl;
            cin >> lng;
            mode.code = new char[lng];
            for(int i = 0; i < lng; i++)
                mode.code[i] = color[rand()%8];
            mode.code[lng] = '\0';
            break;
        }
        case 5:
        {
            int lng;
            cout << "You chose the easiest mode! You have unlimited points" << endl;
            cout << "and are told at which position the characters " << endl;
            cout << "you guessed right are." << endl;
            p.setPoints(h.getIn());
            cout << "How long do you want your cstring to be?" << endl;
            cin >> lng;
            mode.code = new char[lng];
            for(int i = 0; i < lng; i++)
                mode.code[i] = color[rand()%8];
            mode.code[lng] = '\0';
            break;
        }
        default: 
        {
            cout << "Invalid input. Enter a valid difficulty." << endl;
            cin >> inN;
        }
    }
    }while(inN < 0 || inN > 5);
    
    return mode;
}

void guess(const Pattern& code, Score& player, int count, Points& p)
{
    char resp;
    char* guess = new char[strlen(code.code)];
    char color[8] = {'R', 'O', 'Y', 'G', 'B', 'I', 'V', 'W'};
    Guess g;
    int trial = 10;
    if((strlen(code.code) < 4) || (strlen(code.code) > 6))
    {
        cout << endl;
        cout << "How many guesses would you like to have?" << endl;
        cin >> trial;
    }
    cout << "Characters: R, O, Y, G, B, I, V, W" << endl;
    cout << "You have " << trial << " attempts ";
    cout << "to guess your " << strlen(code.code) << " character long ";
    cout << "code" << endl;
    char* temp = new char[5];
    for(int i = 0; i < strlen(code.code); i++)
        temp[i] = code.code[i];
    for(int i = 0; i < trial; i++)
    {
        g.setMatch(0);
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
        if(p.getPoints() > 9000)
        {
            cout << "The characters that are correct are in following ";
            cout << "indexes: ";
        }
        
        for(int j = 0; j < strlen(code.code); j++ )
        {
            if(code.code[j] == g.getGuess()[j])
            {
                ++count;
                if(p.getPoints() > 9000)
                    cout << j << " ";
            }
        }
        if(p.getPoints() > 9000)
            if(count == 0)
                cout << "None" << endl;
        cout << endl;
        g.setMatch(count);
        
        cout << "There are " << g.getMatch() << " characters ";
        cout << "that are in the correct position and ";
        count = 0;
        int mult = 0; // for unwanted bonus count
        for(int j = 0; j < strlen(code.code); j++) // DOES NOT COMPLETELY WORK                      AAAA
        {
            
            for(int k = 0; k < strlen(code.code); k++)
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
        for(int j = 0; j < strlen(code.code); j++)
        temp[j] = code.code[j];
        g.setIn(count);       
        cout << g.getIn() << " correct characters in your guess";
        cout << endl;
        
        if(strcmp(code.code, g.getGuess()) == 0)
        {
            cout << "Congratulations! You win!" << endl;
            
            if(strlen(code.code) == 6)
            {
                if(i == 4)
                {
                    cout << "You completed the round in 5 turns!" << endl;
                    cout << "You have received " << times2(3);
                    cout << " bonus points!" << endl;
                    p.setPoints(p.getPoints()+times2(3));
                }
                if(i == 3)
                {
                    cout << "You completed the round in 5 turns!" << endl;
                    cout << "You have received " << times3(3);
                    cout << " bonus points!" << endl;
                    p.setPoints(p.getPoints()+times3(3));
                }
                if(i <= 2)
                {
                    cout << "You completed the round in 5 turns!" << endl;
                    cout << "You have received " << times5(3);
                    cout << " bonus points!" << endl;
                    p.setPoints(p.getPoints()+times5(3));
                }
            }
            
            if(strlen(code.code) == 5)
            {
                if(i == 5)
                {
                    cout << "You completed the round in 5 turns!" << endl;
                    cout << "You have received " << times2(2);
                    cout << " bonus points!" << endl;
                    p.setPoints(p.getPoints()+times2(2));
                }
                if(i == 3)
                {
                    cout << "You completed the round in 5 turns!" << endl;
                    cout << "You have received " << times3(2);
                    cout << " bonus points!" << endl;
                    p.setPoints(p.getPoints()+times3(2));
                }
                if(i <= 2)
                {
                    cout << "You completed the round in 5 turns!" << endl;
                    cout << "You have received " << times5(2);
                    cout << " bonus points!" << endl;
                    p.setPoints(p.getPoints()+times5(2));
                }
            }
            if(strlen(code.code) == 4)
            {
                if(i == 4)
                {
                    cout << "You completed the round in 5 turns!" << endl;
                    cout << "You have received " << times2(1);
                    cout << " bonus points!" << endl;
                    p.setPoints(p.getPoints()+times2(1));
                }
                if(i == 3)
                {
                    cout << "You completed the round in 5 turns!" << endl;
                    cout << "You have received " << times3(1);
                    cout << " bonus points!" << endl;
                    p.setPoints(p.getPoints()+times3(1));
                }
                if(i <= 2)
                {
                    cout << "You completed the round in 5 turns!" << endl;
                    cout << "You have received " << times5(1);
                    cout << " bonus points!" << endl;
                    p.setPoints(p.getPoints()+times5(1));
                }
            }
            if(player.getPoints() > 9000)
        {
                cout << endl;
                cout << "You have previously played Cheating Mode. " << endl;
                cout << "Your stats will now reset" << endl;
                p.setGame(0);
                p.setLose(0);
                p.setWin(0);
                p.setPoints(0);
                cout << endl;
        }
            player++;
            delete[] temp;
            return;
        }
        if(i == trial-1)
        {
            cout << "You ran out of tries! Would you like to use ";
            cout << "1 point for an additional attempt? y for YES and anything ";
            cout << "else for NO" << endl;
            cout << "Current points: " << p.getPoints() << endl;
            cin >> resp;
            if(p.getPoints() == 0)
                cout << "You have no more points!" << endl;
            if(tolower(resp) == 'y' && p.getPoints() > 0)
            {
                ++trial;
                p.loseP();
                cout << "You used up a point!" << endl;
                cout << "You now have " << p.getPoints() << "points!" << endl; 
            }
        }
    }
    cout << "You lose!" << endl;
        player--;
        delete[] temp;
    if(player.getPoints() > 9000)
        {
        cout << endl;
        cout << "You have previously played Cheating Mode. " << endl;
        cout << "Your stats will now reset" << endl;
        p.setGame(0);
        p.setLose(0);
        p.setWin(0);
        p.setPoints(0);
        cout << endl;
        }
}

int menu()
{
    char* r;
    cout << "Enter a number." << endl;
    cout << "1) View Player Statistics" << endl;
    cout << "2) Continue to Game" << endl;
    cout << "3) Enter the shop" << endl;
    cin >> r;
    while(atoi(r)!=1 && atoi(r)!=2 && atoi(r)!=3)
    {
        cout << "ERROR. INVALID INPUT. PLEASE ENTER A VALID NUMBER" << endl;
        cin >> r;
    }
    return atoi(r);
}

void bonus()
{
    cout << "If you complete this round in 5 rounds, you will";
    cout << " receive 2 times bonus points!" << endl;
    cout << "Finishing in 4 rounds, 3 times! And 3 rounds and under,";
    cout << " 5 times!" << endl;
}

int item()
{
    char *r;
    cout << "Welcome to the shop! Here are our selected items." << endl;
    cout << "1) Hat     (5 points)" << endl;
    cout << "2) Gloves  (5 points)" << endl;
    cout << "3) Hammer  (5 points)" << endl;
    cout << "4) Shoes   (5 points)" << endl;
    cout << "5) Pants   (5 points)" << endl;
    cout << "6) Shirt   (5 points)" << endl;
    cout << "Please enter the number to purchase and anything else to exit";
    cout << endl;
    cin >> r;
    if(atoi(r) > 0 && atoi(r) < 7)
        return atoi(r);
    else
        return 0;
}