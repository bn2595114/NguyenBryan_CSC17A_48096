/* 
 * File:   main.cpp
 * Author: Bryan
 *
 * Created on October 3, 2016, 8:21 PM
 */

#include <cstdlib>
#include <iostream>
using namespace std;

const int SIZE = 30;
const int MONTHS = 12;

#include "MovieData.h"
#include "MovieProfit.h"
#include "ComData.h"
#include "WeatherStatistics.h"

void getData(MovieData&);
void getData(MovieProfit&);
void getData(ComData&);
void getData(Weather [], int);
void display(MovieData);
void display(MovieProfit);
void display(ComData);
void display(Weather [], int);

void sort(Weather [], int);

int main(int argc, char** argv) {

    int num;
    cout << "Enter number to go to the program: " << endl;
    cout << "1) 11.1 Movie Data" << endl;
    cout << "2) 11.2 Movie Profit" << endl;
    cout << "3) 11.3 Corporate Sales Data" << endl;
    cout << "4) 11.4 Weather Statistics" << endl;
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
    
    for(int i = 0; i < size; i++)
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
    float avgTemp = 0, avgRain = 0, totRain = 0;
    for(int i = 0; i < size; i++)
    {
        cout << "Month " << i + 1 << " Statistics: " << endl;
        cout << "Total Rainfall: " << a[i].tRain << endl;
        cout << "Highest Temperature: " << a[i].hTemp << endl;
        cout << "Lowest Temperature: " << a[i].lTemp << endl;
        cout << "Average Temperature: " << a[i].aTemp << endl;
    }
    cout << endl;
    sort(a, size);
    
    for(int i = 0; i < size; i++)
        avgRain += a[i].tRain;
    avgRain /= size;
    for(int i = 0; i < size; i++)
        totRain += a[i].tRain;
    
    for(int i = 0; i < size; i++)
        avgTemp += a[i].aTemp;
    avgTemp /= size;
    cout << "Average rainfall of all months is: " << avgRain << endl;
    cout << "Total rainfall of all months is: " << totRain << endl;
    cout << "Highest Temperature is: " << a[size-1].hTemp << endl;
    cout << "Lowest Temperature is: " << a[size-1].lTemp << endl;
    cout << "Average of the average temperatures: " << avgTemp << endl;
   
}

void sort(Weather a[], int size)
{
    float temp;
    for(int i = 0; i < size; i++)
        for(int j = i+1; j < size; j++)
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