/* 
 * File:   main.cpp
 * Author: Bryan Nguyen
 *
 * Created on October 27, 2016, 1:58 AM
 */

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <ctime>
#include <cstring>
using namespace std;

#include "playerData.h"

int SIZE = 10;
Player newPlay(Player);
void account(Player);
void instr(); // instructions
char dfclt(Player); // choose difficulty
int topic(); // choose topic to guess from
void enter(char, Player&); // enter level of difficulty
void eMode(Player&); // easy mode
string eAnim(); // easy animal topic vocabulary
string eCandy(); // easy candy topic vocabulary
string eFruit(); // easy flavor topic vocabulary
void mMode(Player&); // medium mode
string mAnim(); // medium animal topic vocabulary
string mCandy(); // medium candy topic vocabulary
string mFruit(); // medium flavor topic vocabulary
void hMode(Player&); // hard mode
string hAnim(); // hard animal topic vocabulary
string hCandy(); // hard candy topic vocabulary
string hFruit(); // hard flavor topic vocabulary
void play(string, Player&); // enter game of subject
void stats(Player&);

int main(int argc, char** argv) {
    
    srand(static_cast<unsigned int>(time(0)));
    int players = 0;
    Player play;
    instr();
    account(newPlay(play));
    fstream file;
    
    return 0;
}

Player newPlay(Player user)
{
    fstream acnt;
    string fName;
    cout << endl << "What is your name?" << endl;
    cin.getline(user.name, 50);
    fName = user.name;
    fName += ".dat";
    user.easy = 0;
    user.medium = 0;
    user.hard = 0;
    user.win =  0;
    user.lose = 0;
    
    user.avgG = 0;
    acnt.open(fName.c_str(), ios::in | ios::binary);
    acnt.read(reinterpret_cast<char*>(&user), sizeof(user));
    acnt.close();
    return user;
}

void account(Player user)
{
    char x;
    char stat;
    fstream acnt;
    string fName;
    fName = user.name;
    fName += ".dat";
    
    do{
    acnt.open(fName.c_str(), ios::out | ios::binary);
    if(!acnt)
        cout << "Unregistered Account. Creating your Account..." << endl;
    acnt.close();
    enter(dfclt(user), user);
    int games = user.easy+user.medium+user.hard;
        user.avgG += user.guess[games];
    
    user.avgG /= static_cast<float>(games);
    cout << "Enter 1 to play again and any other number to stop" << endl;
    cin >> x;
    while(isalpha(x))
    {
        cout << "Not a number. Enter a number" << endl;
        cin >> x;
    }
    } while(x=='1');
    
    cout << "View your stats? y/n" << endl;
    cin.ignore();
    cin >> stat;
    if(tolower(stat) == 'y')
        stats(user);
    acnt.open(fName.c_str(), ios::out | ios::binary);
    acnt.write(reinterpret_cast<char*>(&user), sizeof(user));
    acnt.close();
    acnt.open(fName.c_str(), ios::in | ios::binary);
    acnt.read(reinterpret_cast<char*>(&user), sizeof(user));
    acnt.close();
    delete[] user.guess;
}

void instr()
{
    cout << "Welcome to Hangman! First, choose a topic. Once you choose a topic, ";
    cout << endl << "a number of underscores will appear. This represents ";
    cout << endl << "the number of characters the word of the topic selected. ";
    cout << endl << "You will have as many tries to guess the word one ";
    cout << endl << "letter at a time until you make 10 incorrect letter choices ";
    cout << "\nIf you do not guess the word by that time, you lose!" << endl;
}

char dfclt(Player user)
{
    char dfclt;
    cout << "Choose a difficulty: " << endl;
    cout << "E - Easy" << endl << "M - Medium" << endl << "H - Hard" << endl;
    cin >> dfclt;
    while(isdigit(dfclt) || ((toupper(dfclt) != 'E') && (toupper(dfclt) != 'M')
          && (toupper(dfclt) != 'H')))
    {
        cout << "Enter a valid choice" << endl;
        cin >> dfclt;
    }
    dfclt = toupper(dfclt);
    if(dfclt == 'E')
        user.easy++;
    if(dfclt == 'M')
        user.medium++;
    if(dfclt == 'H')
        user.hard++;
    return dfclt;
}

int topic()
{
    char topic;
    cout << "What topic would you like to guess from?" << endl;
    cout << "1) Animals" << endl;
    cout << "2) Candy" << endl;
    cout << "3) Fruits" << endl;
    cin >> topic;
    while(isalpha(topic) || (topic != '1' && topic != '2' && topic != '3'))
    {
        cout << "Enter a valid number" << endl;
        cin >> topic;
    }
    return topic;
}

void enter(char dfclt, Player& user)
{
    
    switch(dfclt)
    {
            case 'E': ++user.easy;eMode(user);break;
            case 'M': ++user.medium;mMode(user);break;
            case 'H': ++user.hard;hMode(user);break; 
        default: cout << "Game will now exit" << endl;
    }
}

void eMode(Player& user)
{
    
    char choice = topic();
    if(choice == '1')
        play(eAnim(), user);
    if(choice == '2')
        play(eCandy(), user);
    if(choice == '3')
        play(eFruit(), user);  
}

string eAnim()
{
    string animal[SIZE] = {"Dog", "Cat", "Rabbit", "Bird", "Fish", "Chicken",
                           "Cow", "Horse", "Lion", "Pig"};
    int random = rand()%10;
    return animal[random];
   
}

string eCandy()
{
    
    string candy[SIZE] = {"Twix", "Starburst", "KitKat", "Crunch", 
                          "Butterfinger", "Snickers", "Hersheys", 
                          "Twizzlers", "Reeses", "Skittles"};
    int random = rand()%10;
    return candy[random];
}

string eFruit()
{
    string fruit[SIZE] = {"Apple", "Banana", "Pear", "Kiwi", "Orange", 
                          "Peach", "Lemon", "Cherry", "Grape", "Lime"};
    int random = rand()%10;
    return fruit[random];
}



void mMode(Player& user)
{
   
    int choice = topic();
    if(choice == '1')
        play(mAnim(), user);
    if(choice == '2')
        play(mCandy(), user);
    if(choice == '3')
        play(mFruit(), user); 
}

string mAnim()
{
    
    string animal[SIZE] = {"Elephant", "Kangaroo", "Monkey", "Penguin", 
                           "Cheetah", "Camel", "Squirrel", "Zebra", 
                           "Turtle", "Snail"};
    int random = rand()%10;
    return animal[random];
}

string mCandy()
{
    string candy[SIZE] = {"Candy Corn", "York Peppermint", "Jelly Belly", 
                          "Three Musketeers", "Tootsie Rolls", "Milky Way", 
                          "Swedish Fish", "Junior Mints", "Peeps", "Baby Ruth"};
    int random = rand()%10;
    return candy[random];
}

string mFruit()
{
    string fruit[SIZE] = {"Apricot", "Blackberry", "Coconut", "Cranberry", 
                          "Fig", "Guava", "Mango", "Papaya", "Strawberry", 
                          "Honeydew"};
    int random = rand()%10;
    return fruit[random];
}


void hMode(Player& user)
{
    
    int choice = topic();
    if(choice == '1')
        play(hAnim(), user);
    if(choice == '2')
        play(hCandy(), user);
    if(choice == '3')
        play(hFruit(), user);
}

string hAnim()
{
    
    string animal[SIZE] = {"Alligator", "Chimpanzee", "Crocodile",
                           "Giraffe", "Hippopotamus", "Octopus", "Scorpion", 
                           "Anaconda", "Chipmunk"};
    int random = rand()%10;
    return animal[random];
}

string hCandy()
{
    string candy[SIZE] = {"Atomic Fireball", "Almond Joy", "Pixie Stix", 
                          "Smarties", "Toblerone", "Jolly Ranchers", 
                          "Salt water taffy", "Jawbreakers", "Pocky",
                          "Sugar Daddy"};
    int random = rand()%10;
    return candy[random];
}

string hFruit()
{
    string fruit[SIZE] = {"Gooseberry", "Grapefruit", "Huckleberry", 
                          "Kumquat", "Loquat", "Mulberry", "Clementine", 
                          "Mandarin", "Persimmon", "Lychee"};
    int random = rand()%10;
    return fruit[random];
}

void play(string subj, Player& user)
{
    int games = user.easy+user.medium+user.hard;
    user.guess = new int[games];
    
    char guess[30], check[30];
    int fail = 0;
    char word[30];
    strcpy(word, subj.c_str());
    char* answer = new char[strlen(word)];
    
    for(int i = 0; i < strlen(word); i++)
    {
        if(isalpha(word[i]))
        {
            answer[i] = '_';
        }
        else
            answer[i] = ' ';
        cout << answer[i] << " ";
    }
    int x, count = 0, num = 0, space, y = 0;
    user.guess[games] = 0;
    while(fail < 10)
    {
        cout << endl << "Enter a letter: ";
        cin >> guess[y];
        user.guess[games]++;
        for(int i = 0; i < 30; i++)
            for(int i = 0; i < 30; i++)
                while(toupper(check[i]) == toupper(guess[y]))
                {
                cout << guess[i] << " has already been entered. "
                        "Choose a different letter." << endl;
                cin >> guess[y];
                }
        num++;
        for(int i = 0; i < strlen(word); i++)
        {
            if(answer[i] == ' ')
                space = 1;
            if(tolower(word[i]) == tolower(guess[y]))
            {
                answer[i] = word[i];
                x = i;
                count++;
            }
            cout << answer[i] << " ";
        }
        if(guess[y] != answer[x])
        {
            cout << endl << guess[y] << " is not in the word!" << endl;
            fail++;
            cout << "You have " << 10-fail << " tries left!" << endl;
            
        }
        if(space == 1)
        if(count+1 == strlen(word))
        {
            cout << endl << "Congratulations, You win!" << endl;
            user.win++;
            
            delete[] answer;
            return;
        }
        if(count == strlen(word))
        {
            cout << endl << "Congratulations, You win!" << endl;
            user.win++;
            delete[] answer;
            return;
        }
        check[y] = guess[y];
        y++;
    }
    cout << endl << "You lose! Better luck next time" << endl;
    user.lose++;
    delete[] answer;
}

void stats(Player& user)
{
    cout << user.name << "'s stats: " << endl;
    cout << "Wins: " << user.win << endl;
    cout << "Losses: " << user.lose << endl;
    cout << "Easy Games: " << user.easy << endl;
    cout << "Medium Games: " << user.medium << endl;
    cout << "Hard Games: " << user.hard << endl;
    cout << "Total Games: " << user.easy+user.medium+user.hard << endl;
    cout << "Average Total Guesses: " << user.avgG << endl << endl;
}