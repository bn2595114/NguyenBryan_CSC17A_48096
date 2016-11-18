#include <string>
#include <iostream>
using namespace std;
#include "Numbers.h"

void Numbers::print()
{
    int n;
    
    string lessThan20[20] = { "zero", "one", "two", "three", "four", "five", 
                              "six", "seven", "eight", "nine", "ten", "eleven", 
                              "twelve", "thirteen", "fourteen", "fifteen", 
                              "sixteen", "seventeen", "eighteen", "nineteen"};
    string tens[10] = { " ", "ten", "twenty", "thirty", "fourty", "fifty", 
                        "sixty", "seventy", "eighty", "ninety" };
    string hundred = "hundred";
    string thousand = "thousand";
    
    n = number/1000;
    if(n > 0)
        cout << lessThan20[n] << " " << thousand << " ";
    number %= 1000;
    
    n = number/100;
    if(n > 0)
        cout << lessThan20[n] << " " << hundred << " ";
    number %= 100;
    
    
    if(number >= 20)
    {
        n = number / 10;
    if(n > 0)
        cout << tens[n] << " ";
    }
    else if(number >= 10)
    {
        cout << lessThan20[number] << " ";
        return;
    }
    number %= 10;
    if(number > 0)
        cout << lessThan20[number] << " ";
}
