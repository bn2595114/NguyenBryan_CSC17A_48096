/* 
 * File:   main.cpp
 * Author: Bryan
 *
 * Created on September 21, 2016, 5:11 PM
 */

#include <cstdlib>
#include <iostream>
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    int SIZE = 4;
    bool x[SIZE] = {true, true, false, false},
            y[SIZE] = {true, false, true, false};
    
    cout << "x y !x !y x&&y x||y x^y (x^y)^x (x^y)^y !(x&&y) ";
        cout << "!x||!y !(x||y) !x&&!y" << endl;
    for(int i = 0; i < SIZE; i++)
    {
        cout << (x[i]? 'T' : 'F') << " ";
        cout << (y[i]? 'T' : 'F') << "  ";
        cout << (!x[i]? 'T' : 'F') << "  ";
        cout << (!y[i]? 'T' : 'F') << "   ";
        cout << ((x[i] && y[i])? 'T' : 'F') << "    ";
        cout << ((x[i] || y[i])? 'T' : 'F') << "   ";
        cout << ((x[i]^y[i])? 'T' : 'F') << "     ";
        cout << ((x[i]^y[i])^y[i]? 'T' : 'F') << "        ";
        cout << ((x[i]^y[i])^x[i]? 'T' : 'F') << "      ";
        cout << (!(x[i] && y[i])? 'T' : 'F') << "       ";
        cout << (!x[i] || !y[i]? 'T' : 'F') << "      ";
        cout << (!(x[i] || y[i])? 'T' : 'F') << "       ";
        cout << (!x[i] && !y[i]? 'T' : 'F') << endl;
    }
    
    
    
    
    return 0;
}

