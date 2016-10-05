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

#include "MovieData.h"
#include "MovieProfit.h"
#include "ComData.h"

void getData(MovieData&);
void getData(MovieProfit&);
void getData(ComData&);
void display(MovieData);
void display(MovieProfit);
void display(ComData);

int main(int argc, char** argv) {

    int num;
    cout << "Enter number to go to the program: " << endl;
    cout << "1) 11.1 Movie Data" << endl;
    cout << "2) 11.2 Movie Profit" << endl;
    cout << "3) 11.3 Corporate Sales Data" << endl;
    cin >> num;
    
    switch(num)
    {
        case 1: 
        {
            
            MovieData movie1, movie2;
            
            cin.ignore();
            getData(movie1);
            display(movie1);
            
            cin.ignore();
            getData(movie2);
            display(movie2);
        }
        case 2:
        {
            MovieProfit movie1, movie2;
            
            cin.ignore();
            getData(movie1);
            display(movie1);
            
            cin.ignore();
            getData(movie2);
            display(movie2);
        }
        case 3:
        {
            ComData data1, data2, data3, data4;
            cout << "Regarding the first company: " << endl;
            getData(data1);
            cout << "Regarding the second company: " << endl;
            getData(data2);
            cout << "Regarding the third company: " << endl;
            getData(data3);
            cout << "Regarding the fourth company: " << endl;
            getData(data4);
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