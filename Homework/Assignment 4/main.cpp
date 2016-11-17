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
#include "RetailItem.h"

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
            
            Data myInfo(name, addr, age, phone);
            cout << endl;
            cout << "Your information: " << endl;
            cout << myInfo.getName() << endl;
            cout << myInfo.getAge() << endl;
            cout << myInfo.getAddress() << endl;
            cout << myInfo.getNumber() << endl;
            cout << endl;
            
            delete[] name;
            
            break;
        }
        case 3: 
        {
            char* des, *des1, *des2;
            int unit;
            float price;
            des = new char[100];
            des1 = new char[100];
            des2 = new char[100];
            cin.ignore();
            cout << "Enter the Description of product: ";
            cin.getline(des, 100);
            cout << "Enter the Units on hand of product: ";
            cin >> unit;
            cout << "Enter the price of product: ";
            cin >> price;
            RetailItem item1(des, unit, price);
            cin.ignore();
            cout << "Enter the Description of product: ";
            cin.getline(des1, 100);
            cout << "Enter the Units on hand of product: ";
            cin >> unit;
            cout << "Enter the price of product: ";
            cin >> price;
            RetailItem item2(des1, unit, price);
            cin.ignore();
            cout << "Enter the Description of product: ";
            cin.getline(des2, 100);
            cout << "Enter the Units on hand of product: ";
            cin >> unit;
            cout << "Enter the price of product: ";
            cin >> price;
            RetailItem item3(des2, unit, price);
            
            cout << "Item 1: " << endl;
            cout << item1.getDes() << endl;
            cout << item1.getUnits() << " Units" << endl;
            cout << item1.getPrice() << " Dollars" << endl << endl;
            cout << "Item 2: " << endl;
            cout << item2.getDes() << endl;
            cout << item2.getUnits() << " Units" << endl;
            cout << item2.getPrice() << " Dollars" << endl << endl;
            cout << "Item 3: " << endl;
            cout << item3.getDes() << endl;
            cout << item3.getUnits() << " Units" << endl;
            cout << item3.getPrice() << " Dollars" << endl << endl;
            delete[] des;
            delete[] des1;
            delete[] des2;
            break;
        }
        default: 
            cout << "You entered " << inN << " to exit.";
    }
    cout << endl << endl;
    } while(inN > 0 && inN < 11);
    return 0;
}

