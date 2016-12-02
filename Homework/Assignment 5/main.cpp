/* 
 * File:   main.cpp
 * Author: Bryan
 *
 * Created on November 30, 2016, 8:25 PM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

#include "Employee.h"
#include "Time.h"

void problem1();
void problem2();
void problem3();
void problem4();
void problem5();
void problem6();
void problem7();
void problem8();
void problem9();
void problem10();
int main(int argc, char** argv) {

    int inN;
    
    do{
    cout << "Enter the number of the program: " << endl;
    cout << "1) Employee and ProductionWorker Classes" << endl;
    cout << "2) Time Format" << endl;
    
    cin >> inN;
    switch(inN)
    {
        case 1:{problem1();break;}
        case 2:{problem2();break;}
        /*case 3:{problem3();break;}
        case 4:{problem4();break;}
        case 5:{problem5();break;}
        case 6:{problem6();break;}
        case 7:{problem7();break;}
        case 8:{problem8();break;}
        case 9:{problem9();break;}
        case 10:{problem10();break;}*/
        
            default:cout<<"Program Exiting...";
    }
    cout << endl << endl << endl << endl;
    } while(inN >0 && inN < 11);
    return 0;
}

void problem1()
{
    string name, num, date;
    int shift;
    float pay;
    
    cout << "Enter name: ";
    cin >> name;
    cout << "Enter number: ";
    cin >> num;
    cout << "Enter date: ";
    cin >> date;
    cout << "Enter 1 for day shift and 2 for night shift: ";
    cin >> shift;
    while(shift < 1 || shift > 2)
    {
        cout << "Invalid Input. Enter Valid Number: ";
        cin >> shift;
    }
    cout << "Enter hourly pay: ";
    cin >> pay;
    
    ProductionWorker data;
    data.setName(name);
    data.setNum(num);
    data.setDate(date);
    data.setShift(shift);
    data.setPay(pay);
    
    cout << "Name: " << data.getName() << endl;
    cout << "Number: " << data.getNumber() << endl;
    cout << "Date: " << data.getDate() << endl;
    if(data.getShift() == 1)
        cout << "Day Shift" << endl;
    else
        cout << "Night Shift" << endl;
    cout << "Hourly Pay: " << data.getPayRate() << endl;
    
    
}

void problem2()
{
    int mili;
    cout << "Enter Time in military format: ";
    cin >> mili;
    MilTime time(mili);
    
    cout << "The time in standard format is: " << endl;
    cout << time.getHr() << ":" << time.getMin();
}