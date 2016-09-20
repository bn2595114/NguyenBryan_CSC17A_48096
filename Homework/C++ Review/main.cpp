/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Bryan Nguyen
 *
 * Created on August 31, 2016, 11:33 AM
 */

// Write a program converting Celsius to Farenheit f = (9/5) * c + 32

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

const float YEN_PER_DOLLAR = 98.83;
const float EUROS_PER_DOLLAR = 0.74;

void toF (float); // Celsius to Farenheit

float dToYen(float); // US dollar to Yen
float dToEu(float); // US dollar to Euros

int days(int, int); //How many days are in a given month an year

bool isCor(int, int); // Checking if solution matches

int main(int argc, char** argv) {
    
    int num;
    cout << "Select the number of the program" << endl;
    cout << "1) 3.12 Celsius to Farenheit" << endl;
    cout << "2) 3.13 Currency" << endl;
    cout << "3) 4.10 Days in a month" << endl;
    cout << "4) 4.11 Math Tutor" << endl;
    cin >> num;
    
    
    switch(num)
    {
        case 1:
    float c; // celsius
    cout << "Please enter a degree in Celsius" << endl;
    cin >> c;
    toF(c);
    break;
    
        case 2:
            char input; //user input
    float dollar;
    
    cout << "How much US dollars would you like the convert?" << endl;
    cin >> dollar;
    
    cout << "Enter the number of the conversion you would like" << endl;
    cout << "1. Dollars to Yen" << endl;
    cout << "2. Dollars to Euros" << endl;
    cin >> input;
    
    if (input == '1')
    {
        cout << "The amount you entered converts to " << dToYen(dollar) << 
                " yen";
    }
    else if (input == '2')
    {
        dToEu(dollar);
        cout << "The amount you entered converts to " << dToEu(dollar) <<
                " euros";
    }
    else
        cout << "Invalid input. Try again later" << endl;
    break;
    
        case 3:
            int month, year;
            cout << "Enter a month (1-12): ";
            cin >> month;
            cout << "Enter a year: ";
            cin >> year;
            if(days(month, year) == -1)
                cout << "Invalid month or year;";
            else 
                cout << days(month, year) << " days";
            break;
            
        case 4:
            srand(static_cast<unsigned int>(time(0)));
            int user, add1, add2, solve;
            add1 = rand()%1001;
            add2 = rand()%1001;
            solve = add1 + add2;
            
            cout << setw(5) << add1 << endl;
            cout << "+" << setw(4) << add2 << endl << "-----" << endl << " ";
            cin >> user; 
            if(isCor(user, solve))
                cout << "Congratulations!";
            else 
                cout << "Incorrect! Answer is " << solve;
            break;
    }
    return 0;
}

void toF(float celsius) // celsius to farenheit converter and output
{
    float f = (9/5) * celsius + 32;
    cout << celsius << " degrees Celsius is " << f << " degrees Farenheit"
            << endl;
}


float dToYen(float dollar) // conversion from dollar to yen
{
    float money;
    money = dollar * YEN_PER_DOLLAR;
    return money;
    
}

float dToEu(float dollar) // conversion from dollar to euro
{
    float money;
    money = dollar * EUROS_PER_DOLLAR;
    return money;
}

int days(int month, int year)
{
    if((month % 2 == 1 || month == 8) && month > 0 && month < 13 && year >= 0)
        return 31; 
    if(month % 2 == 0 && month > 0 && month < 13)
    {
        if(month == 2)
        {
            if(year % 100 == 0 && year % 400 == 0)
                return 29;
            if(year / 100 > 0 && year % 4 == 0)
                return 29; 
            return 28;
        }
        return 30;
    }
    return -1; //error check
}

bool isCor(int user, int comp) // is correct
{
    if(user == comp)
        return true;
    return false;
}