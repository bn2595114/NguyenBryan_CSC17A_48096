
/* 
 * File:   main.cpp
 * Author: Bryan Nguyen
 * Purpose: Review of chapter 3 - 4 C++
 * Created on August 31, 2016, 11:33 AM
 */



#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <ctime>
#include <fstream>
#include <string>
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
//Program 8
void output(int, int, int);
//Program 9
void sort(string [], int);
string getVal();
//Problem 10
void compare(int [], int, int);
void fill(int a[], int size);
int bSearch(const string [], int, string);

int main(int argc, char** argv) {
    
    srand(static_cast<unsigned int>(time(0)));
    
    int num;
    cout << "Select the number of the program" << endl;
    cout << "1) 3.12 Celsius to Fahrenheit" << endl; // convert c to F
    cout << "2) 3.13 Currency" << endl; // Convert to yen and euros
    cout << "3) 4.10 Days in a month" << endl; // Calculate leap year
    cout << "4) 4.11 Math Tutor" << endl; // Math addition
    cout << "5) 4.16 Running the Race" << endl; // Give places of runners
    cout << "6) 5.11 Population" << endl; // Estimate population size
    cout << "7) 6.7 Celsius Temperature Table" << endl; // Output given fahren.
    cout << "8) 7.6 Rain or Shine" << endl; // read from file and output R,S,C
    cout << "9) 8.7 Binary String Search" << endl; // binary search
    cout << "10) 7.4 Larger Than n" << endl; // output numbers larger than n
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
            break;
        }
        case 7:
        {
            float f;
            cout << "Enter a degree in Fahrenheit you wish to convert" << endl;
            cin >> f;
            celsius(f);
            break;
        }
        case 8:
        {
            const int N = 30; //columns
            const int R = 3;
            ifstream infile;
            infile.open("RainOrShine.txt");
            char a2D [R][N];
            int rJune = 0, cJune = 0, sJune = 0;
            int rJuly = 0, cJuly = 0, sJuly = 0;
            int rAug = 0, cAug = 0, sAug = 0;
            
            for (int i = 0; i < R; i++)
                for (int j = 0; j < N; j++)
                    infile >> a2D[i][j];
            
            for (int i = 0; i < R; i++)
            {
                if(i == 0)
                {
                    cout << "June: ";
                }
                if(i == 1)
                {
                    cout << "July: ";
                }
                if(i == 2)
                {
                    cout << "August: ";
                }
                for (int j = 0; j < N; j++)
                {
                    cout << a2D[i][j];
                        
                }
                cout << endl;
            }
            for(int j = 0; j < N; j++)
            {
                if(a2D[0][j] == 'R')
                        rJune++;
                    if(a2D[0][j] == 'C')
                        cJune++;
                    if(a2D[0][j] == 'S')
                        sJune++;
                    if(a2D[1][j] == 'R')
                        rJuly++;
                    if(a2D[1][j] == 'C')
                        cJuly++;
                    if(a2D[1][j] == 'S')
                        sJuly++;
                    if(a2D[2][j] == 'R')
                        rAug++;
                    if(a2D[2][j] == 'C')
                        cAug++;
                    if(a2D[2][j] == 'S')
                        sAug++;
            }
            cout << "June:" << endl;
            output(rJune, cJune,sJune);
            cout << "July:" << endl;
            output(rJuly,cJuly,sJuly);
            cout << "August:" << endl;
            output(rAug, cAug, sAug);
            
            if ((rJune > rJuly) && (rJune > rAug))
                cout << "June has most rainy days";
            if ((rAug > rJune) && (rAug > rJuly))
                cout << "August has most rainy days";
            if ((rJuly > rJune) && (rJuly > rAug))
                cout << "July has most rainy days";
            break;
        }
        case 9:
        {
            
            string name;
            const int NUM_NAMES = 20;
            string names[NUM_NAMES] = {"Collins, Bill", "Smith, Bart",
                                       "Allen, Jim", "Griffin,Jim", "Stamey Marty", 
                                       "Rose, Geri", "Taylor, Terri", "Johnson, Jill", 
                                       "Allison, Jeff", "Looney, Joe", "Wolfe, Bill", 
                                       "James, Jean", "Weaver, Jim", "Pore, Bob", 
                                       "Rutherford, Greg", "Javens Renee",
                                       "Harrison, Rose", "Setzer, Cathy", 
                                       "Pike, Gordon", "Holland, Beth"};
            sort(names, NUM_NAMES);
            cout << "Names in alphabetical order in last name: " << endl;
            for(int i = 0; i < NUM_NAMES; i++)
                cout << names[i] << endl;
            name = getVal();
            cout << "Your person is in index: " << bSearch(names, NUM_NAMES, name);
            break;
        }
        case 10: 
        {
            int size, ary [size], n;
            cout << "Enter the size of the array: ";
            cin >> size;
            cout << "The array will be filled with random numbers" << endl;
            cout << "What number would you like to compare? " << endl;
            cin >> n;
            fill(ary, size);
            cout << "Numbers greater than your number will now be displayed: ";
            cout << endl;
            compare(ary, size, n);
            break;
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

void sort(string name[], int size)
{
    string temp;
    for(int i = 0; i < size; i++)
        for (int j = i+ 1; j < size; j++)
        {
            if(name[i] > name[j])
            {
                temp = name[i];
                name[i] = name[j];
                name[j] = temp;
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

void output(int a, int b, int c)
{
    cout << "Rainy Days: " << a << endl;
    cout << "Cloudy Days: " << b << endl;
    cout << "Sunny Days : " << c << endl << endl;
   
}

int bSearch(const string array[], int num, string name)
{
    int first = 0, last = num - 1, middle, position = -1;
    bool found = false;
    
    while(!found && first <= last)
    {
        middle = (first + last) / 2;
        if (array[middle] == name)
        {
            found = true;
            position = middle;
        }
        else if(array[middle] > name)
            last = middle - 1;
        else 
            first = middle + 1;
    }
    return position;
}

string getVal()
{
    string input;
    cout << "Enter last name, first name: ";
    cin.ignore();
    getline(cin, input);
    return input;
}

void compare(int a[], int size, int n)
{
    
    for(int i = 0; i < size; i++)
    {
        if (a[i] > n)
            cout << a[i] << "  ";
        if(i % 10 == 9)
            cout << endl;
    }
}

void fill(int a[], int size)
{
    for(int i = 0; i < size; i++)
        a[i] = rand()%100;
}