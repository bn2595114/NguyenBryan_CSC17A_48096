/* 
 * File:   main.cpp
 * Author: Bryan
 *
 * Created on November 14, 2016, 9:36 PM
 */

#include <cstdlib>
#include <iostream>
using namespace std;

#include "Date.h"
#include "PersonalData.h"

int main(int argc, char** argv) {

    int inN;
    
    do{
    cout << "Enter a number: " << endl;
    cout << "1) 13.1 Date" << endl;
    
    
    cin >> inN;
    
    switch(inN)
    {
        case 1:
        {
    Date date;
    const int SIZE = 13;
    int month, day, year;
    string months[SIZE] = {"0", "January", "February", "March", "April", "May", 
                           "June", "July", "August", "September", "October", 
                           "November", "December"};
    
    cout << "Please enter the month: ";
    cin >> month;
    cout << "Please enter the day: ";
    cin >> day;
    cout << "Please enter the year: ";
    cin >> year;
    cout << endl;
    
    date.setMonth(month);
    date.setDay(day);
    date.setYear(year);
    
    cout << date.getMonth() << "/" << date.getDay() << "/" << date.getYear();
    cout << endl;
    
    cout << months[date.getMonth()] << " " << date.getDay() << ",";
    cout << date.getYear() << endl;
    
    cout << date.getDay() << " " << months[date.getMonth()] << " ";
    cout << date.getYear() << endl;
    break;
        }
        case 2:
        {
            int age;
            char *name, *addr, *phone;
            name = new char[50];
            cin.ignore();
            cout << "Enter your name: ";
            cin.getline(name, 50);
            cout << "Enter your address: ";
            cin.getline(addr, 50);
            cout << "Enter your phone number: ";
            cin.getline(phone, 50);
            cout << "Enter your age: ";
            cin >> age;
            cout << name << endl;
            Data myInfo(name, addr, age, phone);
            cout << myInfo.getAge() << endl;
            cout << myInfo.getName();
            cout << endl;
            delete[] name;
            
            break;
        }
        default: 
            cout << "You entered " << inN << " to exit.";
    }
    cout << endl << endl;
    } while(inN > 0 && inN < 11);
    return 0;
}

