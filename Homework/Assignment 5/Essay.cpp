
#include "Essay.h"


char GradedActivity::getLetterGrade() const
{
    char letterGrade;
    
    if(score > 89)
        letterGrade = 'A';
    else if(score > 79)
        letterGrade = 'B';
    else if(score > 69)
        letterGrade = 'C';
    else if(score > 59)
        letterGrade = 'D';
    else
        letterGrade = 'F';
    return letterGrade;
}

Essay::Essay()
{
    grammar = 0;
    spelling = 0;
    length = 0;
    content = 0;
}

Essay::Essay(int g, int s, int l, int c)
{
    grammar = g;
    spelling = s;
    length = l;
    content = c;
}

int Essay::getTotal()
{
    int total;
    total = grammar+spelling+length+content;
    return total;
}