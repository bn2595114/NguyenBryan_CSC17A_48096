/* 
 * File:   main.cpp
 * Author: Bryan
 *
 * Created on October 17, 2016, 11:25 AM
 */

#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

int count(char*);
char* rev(char*);


int main(int argc, char** argv) {

    int n;
    cout << "Enter the number of the program you would like to run:" << endl;
    cout << "1) 10.1 String Length" << endl;
    cout << "2) 10.2 Backward String" << endl;
    cout << "3) 10.3 Word Counter" << endl;
    cout << "4) 10.4 Average Number of Letters" << endl;
    cout << "5) 10.6 Vowels and Consonants" << endl;
    
    cin >> n;
    switch(n)
    {
        case 1:
        {
            char* word = new char[50];
            cout << "Enter a word: ";
            cin >> word;
            cout << "Word Length: " << count(word);
            delete[] word;
            break;
        }
        case 2:
        {
            
        }
    }
    
    
    return 0;
}

int count(char* str)
{
    int count = 0;
    while(*str != '\0')
    {
        count++;
        str++;
    }
    return count;
}
