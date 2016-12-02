#include <iostream>
using namespace std;

#include "Time.h"


MilTime::MilTime(int t)
{
    
    try{
        if((t < 0) || (t > 2359))
            cout << "Invalid Input. Program Terminating";
        if(t <= 1200)
        {
            hour = t/100;
            min = t%100;
        }
        else
        {
            hour = (t-1200)/100;
            min = t%100;
        }
        
    }
    catch(char *msg)
    {
            cout << "ERROR" << endl;
    }
    milHours = t;
}
