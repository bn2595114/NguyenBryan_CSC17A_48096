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

struct MovieData
{
    char title[SIZE];
    char dirctr[SIZE];
    int year;
    int runTime;
};

void getData(MovieData&);
void display(MovieData);

int main(int argc, char** argv) {

    MovieData movie1, movie2;
    
    getData(movie1);
    display(movie1);
    cin.ignore();
    getData(movie2);
    display(movie2);
   
    
    
    
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

void display(MovieData a)
{
    cout << "Movie 1 Data will now be displayed: " << endl;
    cout << "Title: " << a.title << endl;
    cout << "Director: " << a.dirctr << endl;
    cout << "Year: " << a.year << endl;
    cout << "Run Time: " << a.runTime << endl << endl;
}