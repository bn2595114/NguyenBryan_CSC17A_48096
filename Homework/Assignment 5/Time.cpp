#include <iostream>
#include <string>
using namespace std;

#include "Time.h"


MilTime::MilTime(int t)
{
    
    
        if((t < 0) || (t > 2359))
        {
            string exceptionString = "Error: Invalid Input";
            throw exceptionString;
        }
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
        
    milHours = t;
}

TimeClock::TimeClock(int a, int z)
{
    if(a<z)
        elapse = z-a;
    else
        elapse = a-z;
    
}