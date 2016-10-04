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

void getData(MovieData&);
void getData(MovieProfit&);
void display(MovieData);
void display(MovieProfit);

int main(int argc, char** argv) {

    int num;
    cout << "Enter number to go to the program: " << endl;
    cout << "1) 11.1 Movie Data" << endl;
    cout << "2) 11.2 Movie Profit" << endl;
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