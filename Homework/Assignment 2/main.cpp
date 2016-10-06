/* 
 * File:   main.cpp
 * Author: Bryan
 *
 * Created on October 3, 2016, 8:21 PM
 */

#include <cstdlib>
#include <iostream>
using namespace std;

const int SIZE = 100;
const int MONTHS = 12;
const int PLAYERS = 12;
const int ACCOUNT = 10;
const int SPEAKER = 10;

#include "MovieData.h"
#include "MovieProfit.h"
#include "ComData.h"
#include "WeatherStatistics.h"
#include "Soccer.h"
#include "Accounts.h"
#include "Bureau.h"

void getData(MovieData&);
void getData(MovieProfit&);
void getData(ComData&);
void getData(Weather [], int);
void getData(Score [], int);
void getData(Account [], int);
void getData(Speaker [], int);
void display(MovieData);
void display(MovieProfit);
void display(ComData);
void display(Weather [], int);
void display(Score [], int);
void display(Account [], int, int&);
void display(Speaker [], int, int&);

void sort(Weather [], int);

int main(int argc, char** argv) {

    int num;
    cout << "Enter number to go to the program: " << endl;
    cout << "1) 11.1 Movie Data" << endl;
    cout << "2) 11.2 Movie Profit" << endl;
    cout << "3) 11.3 Corporate Sales Data" << endl;
    cout << "4) 11.4 Weather Statistics" << endl;
    cout << "5) 11.5 Weather Statistics Modification" << endl;
    cout << "6) 11.6 Soccer Scores" << endl;
    cout << "7) 11.7 Customer Accounts" << endl;
    cout << "8) 11.8 Search Function for Customer Accounts Program" << endl;
    cout << "9) 11.9 Speakers' Bureau" << endl;
    cin >> num;
    
    switch(num)
    {
        case 1: 
        {
            
            MovieData movie1, movie2;
            
            cin.ignore();
            getData(movie1); // get data
            display(movie1); // display data
            
            cin.ignore();
            getData(movie2); // get data
            display(movie2); // display data
        }
        case 2:
        {
            MovieProfit movie1, movie2;
            
            cin.ignore();
            getData(movie1); // get data
            display(movie1); // display data
            
            cin.ignore();
            getData(movie2); // get data
            display(movie2); // display data
        }
        case 3:
        {
            ComData data1, data2, data3, data4;
            cout << "Regarding the first company: " << endl;
            getData(data1); // gets and displays data
            cout << "Regarding the second company: " << endl;
            getData(data2); //gets and displays data
            cout << "Regarding the third company: " << endl;
            getData(data3); // gets and displays data
            cout << "Regarding the fourth company: " << endl;
            getData(data4); // gets and displays data
        }
        case 4:
        {
            Weather stat[MONTHS];
            getData(stat, MONTHS); // gets data and displays
        }
        case 5: 
        {
            Weather stat[MONTHS];
            getData(stat, MONTHS);
        }
        case 6: 
        {
            Score score[PLAYERS];
            getData(score, PLAYERS);
        }
        case 7: 
        {
            Account account[ACCOUNT];
            getData(account, SIZE);
        }
        case 8:
        {
            Account account[ACCOUNT];
            getData(account, SIZE);
        }
        case 9:
        {
            Speaker speaker[SPEAKER];
            getData(speaker, SIZE);
        }
        case 10:
        {
            Speaker speaker[SPEAKER];
            getData(speaker, SIZE);
        }
        
    }
    
 
   
    
    
    
    return 0;
}

void getData(MovieData &m1)
{
    cout << "Enter Movie Title: ";
    cin.getline(m1.title, SIZE);
    cout << "Enter Director Name: ";
    cin.getline(m1.dirctr, SIZE);
    cout << "Enter Movie Year: ";
    cin >> m1.year;
    cout << "Enter Movie RunTime: ";
    cin >> m1.runTime;
}

void getData(MovieProfit &m1)
{
    cout << "Enter Movie Title: ";
    cin.getline(m1.title, SIZE);
    cout << "Enter Director Name: ";
    cin.getline(m1.dirctr, SIZE);
    cout << "Enter Movie Year: ";
    cin >> m1.year;
    cout << "Enter Movie RunTime: ";
    cin >> m1.runTime;
    cout << "Enter Movie Production Cost: ";
    cin >> m1.prodCost;
    cout << "Enter first year revenues: ";
    cin >> m1.fRev;
}

void getData(ComData &a)
{
    cin.ignore();
    
    cout << "Enter Division Name: ";
    cin.getline(a.name, SIZE);
    cout << "Enter First Quarter Sales: ";
    cin >> a.q1Sale;
    while(a.q1Sale < 0)
    {
        cout << "Negative Numbers are not permitted. Please re enter ";
        cout << "a number";
        cin >> a.q1Sale;
    }
    cout << "Enter Second Quarter Sales: ";
    cin >> a.q2Sale;
    while(a.q2Sale < 0)
    {
        cout << "Negative Numbers are not permitted. Please re enter ";
        cout << "a number";
        cin >> a.q2Sale;
    }
    cout << "Enter Third Quarter Sales: ";
    cin >> a.q3Sale;
    while(a.q3Sale < 0)
    {
        cout << "Negative Numbers are not permitted. Please re enter ";
        cout << "a number";
        cin >> a.q3Sale;
    }
    cout << "Enter Fourth Quarter Sales: ";
    cin >> a.q4Sale;
    while(a.q4Sale < 0)
    {
        cout << "Negative Numbers are not permitted. Please re enter ";
        cout << "a number";
        cin >> a.q4Sale;
    }
    
    a.tSale = a.q1Sale + a.q2Sale + a.q3Sale + a.q4Sale;
    a.avgSale = a.tSale / 4;
    
    cout << "Data will now be displayed: " << endl;
    display(a);
}

void getData(Weather a[], int size)
{
    enum Months {
        JANUARY, FEBRUARY, MARCH, APRIL, MAY, JUNE, JULY, AUGUST,
        SEPTEMBER, OCTOBER, NOVEMBER, DECEMBER
    };
    for(int i = JANUARY; i <= DECEMBER; i++)
    {
        cout << "Enter Total Rainfall for Month " << i + 1 << ": ";
        cin >> a[i].tRain;
        cout << "Enter Highest Temperature for Month " << i + 1 << ": ";
        cin >> a[i].hTemp;
        while(a[i].hTemp > 139)
        {
            cout << "Temperature too high. Enter another temp: ";
            cin >> a[i].hTemp;
        }
        cout << "Enter Lowest Temperature for Month " << i + 1 << ": ";
        cin >> a[i].lTemp;
        while(a[i].lTemp < -99)
        {
            cout << "Temperature too low. Enter another temp: ";
            cin >> a[i].lTemp;
        }
        a[i].aTemp = (a[i].hTemp + a[i].lTemp) / 2;
    }
    display(a, size);
}

void getData(Score a[], int size)
{
    int total  = 0;
    for(int i = 0; i < size; i++)
    {
        cin.ignore();
        cout << "Enter Player " << i+1 << " Name: ";
        cin.getline(a[i].name, size);
        cout << "Enter Player " << i+1 << " Number: ";
        cin >> a[i].num;
        cout << "Enter Player " << i+1 << " Score: ";
        cin >> a[i].score;
        while(a[i].score < 0)
        {
            cout << "Enter a valid positive number: ";
            cin >> a[i].score;
        }
    }
    cout << endl;
    display(a, size);
}

void getData(Account a[], int size)
{
    string reply;
    char name[size];
    int num, count = 0, track = 0;
    do{
    cout << "1) Enter New Account" << endl;
    cout << "2) Edit Existing Account" << endl;
    cout << "3) Display All Accounts" << endl;
    cout << "4) Search by Name" << endl;
    cin >> num;
   
    
    if(num == 1)
        {
            cin.ignore();
            cout << "Enter Account Name: ";
            cin.getline(a[count].name, size);
            cout << "Enter Address: ";
            cin.getline(a[count].addr, size);
            cout << "Enter City, State, and Zip: ";
            cin.getline(a[count].cSZ, size);
            cout << "Enter Telephone Number: ";
            cin.getline(a[count].phone, size);
            cout << "Enter Account Balance: ";
            cin >> a[count].bal;
            while(a[count].bal < 0)
            {
                cout << "Enter a non negative balance: ";
                cin >> a[count].bal;
            }
            cin.ignore();
            cout << "Enter Date of Last Payment: ";
            cin.getline(a[count].lastPay, size);
            count++;
        }
    if(num == 2)
        {
            display(a, size, count);
            cout << "Enter the Name of the Account to edit: ";
            cin.ignore();
            cin.getline(name, size);
            for(int i = 0; i < count; i++)
            {
                if(name == a[i].name)
                    track = i;
            }
            cout << "Enter the number of what you would like to change: " << endl;
            cout << "1) Name" << endl;
            cout << "2) Address" << endl;
            cout << "3) City, State, Zip" << endl;
            cout << "4) Telephone Number" << endl;
            cout << "5) Account Balance" << endl;
            cout << "6) Date of Last Payment" << endl;
            cin >> num;
            cin.ignore();
            if(num == 1)
            {
                cout << "Enter New Name: ";
                
                cin.getline(a[track].name, size);
            }
            if(num == 2)
            {
                cout << "Enter New Address: ";
                cin.getline(a[track].addr, size);
            }
            if (num == 3)
            {
                cout << "Enter New City, State, Zip: ";
                cin.getline(a[track].cSZ, size);
            }
            if(num == 4)
            {
                cout << "Enter New Telephone Number: ";
                cin.getline(a[track].phone, size);
            }
            if(num == 5)
            {
                cout << "Enter New Account Balance: ";
                cin >> a[track].bal;
            }
            if(num == 6)
            {
                cout << "Enter New Date of Last Payment: ";
                cin.getline(a[track].lastPay, size);
            }
        }
    if(num == 3)
        display(a, size, count);
    if(num == 4)
    {
        cin.ignore();
        cout << "Enter Name: ";
        cin.getline(name, size);
        cout << endl;
        for(int i = 0; i < count; i++)
            {
                if(name == a[i].name)
                {
                    track = i;
                }
            }
        if(track < 10 || track > 0)
        {
        cout << name << " has been found!" << endl;
        cout << "Name: " << a[track].name << endl;
        cout << "Address: " << a[track].addr << endl;
        cout << "City, State, and ZIP: " << a[track].cSZ << endl;
        cout << "Telephone Number: " << a[track].phone << endl;
        cout << "Date of Last Payment: " << a[track].lastPay << endl;
        cout << endl;
        }
        else
            cout << "Name Not Found." << endl;
        
        
    }
    cout << "Continue? 'Yes' or 'No'" << endl;
    cin >> reply;
    }while(reply != "No");
}

void getData(Speaker a[], int size)
{
    string reply;
    char name[size];
    int num, count = 0, track = 0;
    do{
    cout << "1) Enter New Speaker Information" << endl;
    cout << "2) Edit Existing Speaker Information" << endl;
    cout << "3) Display All Speakers" << endl;
    cout << "4) Search by Name" << endl;
    cin >> num;
   
    
    if(num == 1)
        {
            cin.ignore();
            cout << "Enter Speaker Name: ";
            cin.getline(a[count].name, size);
            cout << "Enter Telephone Number: ";
            cin.getline(a[count].phone, size);
            cout << "Enter Speaking Topic: ";
            cin.getline(a[count].topic, size);
            cout << "Enter Fee Required: ";
            cin >> a[count].fee;
            while(a[count].fee < 0)
            {
                cout << "Enter a non negative balance: ";
                cin >> a[count].fee;
            }
            count++;
        }
    if(num == 2)
        {
            display(a, size, count);
            cout << "Enter the Name to edit: ";
            cin.ignore();
            cin.getline(name, size);
            for(int i = 0; i < count; i++)
            {
                if(name == a[i].name)
                    track = i;
            }
            cout << "Enter the number of what you would like to change: " << endl;
            cout << "1) Name" << endl;
            cout << "2) Telephone Number" << endl;
            cout << "3) Speaking Topic" << endl;
            cout << "4) Fee Required" << endl;
            cin >> num;
            cin.ignore();
            if(num == 1)
            {
                cout << "Enter New Name: ";
                
                cin.getline(a[track].name, size);
            }
            if(num == 2)
            {
                cout << "Enter New Address: ";
                cin.getline(a[track].phone, size);
            }
            if (num == 3)
            {
                cout << "Enter New City, State, Zip: ";
                cin.getline(a[track].topic, size);
            }
            if(num == 4)
            {
                cout << "Enter New Telephone Number: ";
                cin >> a[track].fee;
            }
        }
    if(num == 3)
        display(a, size, count);
    if(num == 4)
    {
        cin.ignore();
        cout << "Enter Name: ";
        cin.getline(name, size);
        cout << endl;
        for(int i = 0; i < count; i++)
            {
                if(name == a[i].name)
                {
                    track = i;
                }
            }
        if(track < 10 || track > 0)
        {
        cout << name << " has been found!" << endl;
        cout << "Name: " << a[track].name << endl;
        cout << "Telephone Number: " << a[track].phone << endl;
        cout << "Speaking Topic: " << a[track].topic << endl;
        cout << "Fee Required: " << a[track].fee << endl;
        cout << endl;
        }
        else
            cout << "Name Not Found." << endl;
        
        
    }
    cout << "Continue? 'Yes' or 'No'" << endl;
    cin >> reply;
    }while(reply != "No");
}



void display(MovieData a)
{
    cout << endl;
    cout << "Movie Data will now be displayed: " << endl;
    cout << "Title: " << a.title << endl;
    cout << "Director: " << a.dirctr << endl;
    cout << "Year: " << a.year << endl;
    cout << "Run Time: " << a.runTime << endl << endl;
}

void display(MovieProfit a)
{
    cout << "Movie Data will now be displayed: " << endl;
    cout << "Title: " << a.title << endl;
    cout << "Director: " << a.dirctr << endl;
    cout << "Year: " << a.year << endl;
    cout << "Run Time: " << a.runTime << endl;
    cout << "Production Cost: " << a.prodCost << endl;
    cout << "First Year Revenue: " << a.fRev << endl << endl;
}

void display(ComData a)
{
    cout << "Division Name: " << a.name << endl;
    cout << "First Quarter Sales: " << a.q1Sale << endl;
    cout << "Second Quarter Sales: " << a.q2Sale << endl;
    cout << "Third Quarter Sales: " << a.q3Sale << endl;
    cout << "Fourth Quarter Sales: " << a.q4Sale << endl;
    cout << "Total Annual Sales: " << a.tSale << endl;
    cout << "Average Quarterly Sales: " << a.avgSale << endl << endl;
}

void display(Weather a[], int size)
{
 
    enum Months {
        JANUARY, FEBRUARY, MARCH, APRIL, MAY, JUNE, JULY, AUGUST,
        SEPTEMBER, OCTOBER, NOVEMBER, DECEMBER
    };
    float avgTemp = 0, avgRain = 0, totRain = 0;
    for(int i = JANUARY; i <= DECEMBER; i++)
    {
        cout << "Month " << i + 1 << " Statistics: " << endl;
        cout << "Total Rainfall: " << a[i].tRain << endl;
        cout << "Highest Temperature: " << a[i].hTemp << endl;
        cout << "Lowest Temperature: " << a[i].lTemp << endl;
        cout << "Average Temperature: " << a[i].aTemp << endl;
    }
    cout << endl;
    sort(a, size);
    
    for(int i = JANUARY; i <= DECEMBER; i++)
        avgRain += a[i].tRain;
    avgRain /= size;
    for(int i = JANUARY; i <= DECEMBER; i++)
        totRain += a[i].tRain;
    
    for(int i = JANUARY; i <= DECEMBER; i++)
        avgTemp += a[i].aTemp;
    avgTemp /= size;
    cout << "Average rainfall of all months is: " << avgRain << endl;
    cout << "Total rainfall of all months is: " << totRain << endl;
    cout << "Highest Temperature is: " << a[size-1].hTemp << endl;
    cout << "Lowest Temperature is: " << a[size-1].lTemp << endl;
    cout << "Average of the average temperatures: " << avgTemp << endl;
   
}

void display(Score a[], int size)
{
    string name, num;
    int total = 0;
    int max = 0;
    for(int i = 0; i < size; i++)
    {
        cout << "Player " << i+1 << " Name: " << a[i].name << endl;
        cout << "Player Number: " << a[i].num << endl;
        cout << "Points Scored: " << a[i].score << endl;
        total += a[i].score;
        if(a[i].score > max)
        {
            name = a[i].name;
            num = a[i].num;
            max = a[i].score;
        }
    }
    cout << endl;
    cout << "Total Points Scored: " << total << endl;
    cout << "Player with the most points: " << name;
    cout << ". Player number: " << num;
}

void display(Account a[], int size, int& count)
{
    cout << "Accounts found: " << endl;
    for(int i = 0; i < count; i++)
    {
        cout << "Name: " << a[i].name << endl;
        cout << "Address: " << a[i].addr << endl;
        cout << "City, State, and ZIP: " << a[i].cSZ << endl;
        cout << "Telephone Number: " << a[i].phone << endl;
        cout << "Date of Last Payment: " << a[i].lastPay << endl;
        cout << endl;
    }
    cout << endl;
}

void display(Speaker a[], int size, int& count)
{
    for(int i = 0; i < count; i++)
    {
        cout << "Name: " << a[i].name << endl;
        cout << "Telephone Number: " << a[i].phone << endl;
        cout << "Speaking Topic: " << a[i].topic << endl;
        cout << "Fee Required: " << a[i].fee << endl;
    }
    cout << endl;
}

void sort(Weather a[], int size)
{
    enum Months {
        JANUARY, FEBRUARY, MARCH, APRIL, MAY, JUNE, JULY, AUGUST,
        SEPTEMBER, OCTOBER, NOVEMBER, DECEMBER
    };
    float temp;
    for(int i = JANUARY; i <= DECEMBER; i++)
        for(int j = i+FEBRUARY; j <= DECEMBER; j++)
        {
            if(a[i].hTemp > a[j].hTemp)
            {
                temp = a[i].hTemp;
                a[i].hTemp = a[j].hTemp;
                a[j].hTemp = temp;
            }
            if(a[i].lTemp < a[j].lTemp)
            {
                temp = a[i].lTemp;
                a[i].lTemp = a[j].lTemp;
                a[j].lTemp = temp;
            }
                
        }
}