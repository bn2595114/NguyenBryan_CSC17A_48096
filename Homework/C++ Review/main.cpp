
/* 
 * File:   main.cpp
 * Author: Bryan Nguyen
 * Purpose: Review of chapter 3 - 4 C++
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

//Program 1
void toF (float); // Celsius to Farenheit
//Program 2
float dToYen(float); // US dollar to Yen
float dToEu(float); // US dollar to Euros
//Program 3
int days(int, int); //How many days are in a given month an year
//Program 4
bool isCor(int, int); // Checking if solution matches
//Program 5
void fillAry(string [], int [], int);
void mrkSort(int [], string [], int);
void outRun(string []);
//Program 6
void popul(int, float, int);
//Program 7
float celsius(float);

int main(int argc, char** argv) {
    
    int num;
    cout << "Select the number of the program" << endl;
    cout << "1) 3.12 Celsius to Fahrenheit" << endl;
    cout << "2) 3.13 Currency" << endl;
    cout << "3) 4.10 Days in a month" << endl;
    cout << "4) 4.11 Math Tutor" << endl;
    cout << "5) 4.16 Running the Race" << endl;
    cout << "6) 5.11 Population" << endl;
    cout << "7) 6.7 Celsius Temperature Table" << endl;
    cout << "8) 7.6 Rain or Shine" << endl;
    cout << "9) 8.7" << endl;
    cin >> num;
    
    
    switch(num)
    {
        case 1:
        {
    float c; // Celsius
    cout << "Please enter a degree in Celsius" << endl;
    cin >> c;
    toF(c);
    break;
        }
        case 2:
        {
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
        }
        case 3:
        {
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
        }  
        case 4:
        {
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
        case 5: 
        {
            const int SIZE = 3;
            string run[SIZE];
            int time[SIZE];
            
            fillAry(run, time, SIZE);
            mrkSort(time, run, SIZE);
            outRun(run);
            break;
        }  
        case 6:
        {
            int start, days;
            float avgIncr;
            
            cout << "Enter starting number of organisms (minimum 2): ";
            cin >> start;
            cout << "Enter average daily population increase percentage ";
            cout << "(1 = 100%, 2 = 200%...): " << endl;
            cin >> avgIncr;
            cout << "Enter the number of days the will multiply(1+): ";
            cin >> days;
            popul(start, avgIncr, days);
        }
        case 7:
        {
            float f;
            cout << "Enter a degree in Fahrenheit you wish to convert" << endl;
            cin >> f;
            celsius(f);
        }
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
            if(year % 100 > 0 && year % 4 == 0)
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

void fillAry(string a[], int b[], int size)
{
    
    for(int i = 1; i < size+1; i++)
    {
        cout << "Enter name of Runner " << i << ": ";
        cin >> a[i - 1]; // runner names
        cout << "Enter time of Runner " << i << ": ";
        cin >> b[i - 1]; // runner times
    }
}

void mrkSort(int a[],string b[], int size)
{
    string temp;
    for(int i = 0; i < size; i++)
        for (int j = i + 1; j < size; j++)
        {
            if(a[i] > a[j])
            {
                a[i]=a[i]^a[j];
                a[j]=a[i]^a[j];
                a[i]=a[i]^a[j];
                temp = b[i];
                b[i] = b[j];
                b[j] = temp;
            }
        }
}

void outRun(string name[])
{
    cout << "First Place is " << name[0] << endl;
    cout << "Second Place is " << name[1] << endl;
    cout << "Third Place is " << name[2] << endl;
}

void popul(int size, float incr, int days)
{
    
    if(size >= 2 && incr > 0 && days > 0)
        for (int i = 1; i <= days; i++)
        {
            cout << "In " << i << " day(s), the population size estimation: ";
            size = size + (incr * size);
            cout << size << endl;
            
        }
        
}

float celsius(float f)
{
    float temp;
    float convert = (5.0/9.0) * (f - 32);
    
    for (int i = 0; i <= 20; i++)
    {
        temp = (5.0/9) * (i - 32);
        cout << i << " degrees F is " << temp << " degrees C" << endl;
    }
    cout << endl;
    cout << f << " degrees F is " << convert << " degrees C" << endl;
    return convert;
}