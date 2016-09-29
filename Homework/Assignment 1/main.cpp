/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Bryan Nguyen
 * Purpose: return mean, median, mode, and homework problems
 * Created on September 26, 2016, 12:45 PM
 */

#include <cstdlib>
#include <iostream>
using namespace std;

 
int *mode(int *ary, int size);
float mean(int *, int);
void sort(int *, int);
void prntAry(int *, int);
float med(int *, int);
int arySize(int);
int *allocate(int);
void ascSort(int *, int);
int doSomething(int *, int *);
string *allName(int);
int *reverse(int [], int);
int *crtAry(int [], int);
int *shift(int [], int);
void desSort(int *a, int size);
int main(int argc, char** argv) {
    int num;
    cout << "Choose the number" << endl;
    cout << "1) Mean Median Mode" << endl;
    cout << "2) 9.1 Array Allocator" << endl;
    cout << "3) 9.2 Test Scores #1" << endl;
    cout << "4) 9.3 Drop Lowest Score" << endl;
    cout << "5) 9.4 Test Scores #2" << endl;
    cout << "6) 9.5 Pointer Rewrite" << endl;
    cout << "7) 9.10 Reverse Array" << endl;
    cout << "8) 9.11 Array Expander" << endl;
    cout << "9) 9.12 Element Shifter" << endl;
    cout << "10) 9.6 Case Study Modification #1" << endl;
    cout << "11) 9.7 Case Study Modification #2" << endl;
    cin >> num;
    
    switch (num)
    {
            case 1: 
            {
    const int SIZE = 8;
    int *a;
    int *array = new int[SIZE];
    array[0] = 1;
    array[1] = 2;
    array[2] = 3;
    array[3] = 1;
    array[4] = 2;
    array[5] = 3;
    array[6] = 1;
    array[7] = 2;
    
    sort(array, SIZE);
    prntAry(array, SIZE);
    
    a = mode(array, SIZE);
    
    cout << "Mean is: " << mean(array, SIZE) << endl;
    cout << "Median is: " << med(array, SIZE) << endl;
    
    for(int i = 0; i < 4; i++)
    {
        if(i == 0)
            cout << "Number of Modes: " << a[i] << endl;
        if(i == 1)
            cout << "Frequency of Modes: " << a[i] << endl;
        if(i == 2)
            cout << "Modes: ";
        if(i > 1)
            cout << a[i] << " ";
    }
    delete[] a;
    delete[] array;
    break;
            }
            
            case 2:
            {
                int *ary;
                int num = 0;
                num = arySize(num);
                ary = allocate(num);
                
                for(int i = 0; i < num; i++)
                    cout << ary[i] << " ";
                delete []ary; 
                break;
            }
        case 3:
        {
            int scores, *ary;
            cout << "How many tests?" << endl;
            cin >> scores;
            ary = allocate(scores);
            sort(ary, scores);
            
            cout << "Test Scores in Ascending Order: " << endl;
            for (int i = 0; i < scores; i++)
                cout << ary[i] << " ";
            cout << endl;
            cout << "Average is: " << mean(ary, scores);
            delete[] ary;
            break;
        }
        case 4:
        {
            int scores, *ary, *drop;
            cout << "How many tests?" << endl;
            cin >> scores;
            ary = allocate(scores);
            sort(ary, scores);
            
            drop = new int[scores - 1];
            
            for(int i = 1; i < scores; i++)
                drop[i-1] = ary[i];
            
            cout << "Test Scores in Ascending Order: " << endl;
            for (int i = 0; i < scores - 1; i++)
                cout << drop[i] << " ";
            cout << endl;
            cout << "Average is: " << mean(drop, scores - 1) << endl;
            delete[] ary;
            delete[] drop;
            break;
        }
        case 5: 
        {
            int scores, *ary;
            string *names;
            cout << "How many test takers??" << endl;
            cin >> scores;
            names = allName(scores);
            ary = allocate(scores);
            sort(ary, scores);
            
            cout << "Test Scores in Ascending Order: " << endl;
            for (int i = 0; i < scores; i++)
            {
                cout << names[i] << ": ";
                cout << ary[i] << " " << endl;
            }
                
            cout << endl;
            cout << "Average is: " << mean(ary, scores);
            delete[] ary;
            delete[] names;
            break;
        }
        case 6: 
        {
            int x, y;
            cout << "Enter any number (will be multipled by 10): ";
            cin >> x;
            cout << "Enter another number (will be multiplied by 10: ";
            cin >> y;
            cout << x << " + " << y << " = " << doSomething(&x,&y);
            break;
        }
        case 7:
        {
            int *rev;
            const int SIZE = 5;
            int array[SIZE] = {1, 2, 3, 4, 5};
            rev = reverse(array, SIZE);
            
            cout << "Array in order: ";
            for(int i = 0; i < SIZE; i++)
                cout << array[i] << " ";
            cout << endl;
            cout << "Array in reverse: ";
            for(int i = 0; i < SIZE; i++)
                cout << rev[i] << " ";
            
            delete[] rev; 
            break;
        }
        case 8:
        {
            int *doubl;
            const int SIZE = 5;
            int ary[SIZE] = {1, 2, 3, 4, 5};
            cout << "Original Array: ";
            for(int i = 0; i < SIZE; i++)
                cout << ary[i] << " ";
            cout << endl;
            cout << "Doubled Array Size: ";
            doubl = crtAry(ary, SIZE);
            for(int i = 0; i < SIZE*2; i++)
                cout << doubl[i] << " ";
            delete[] doubl;
            break;
        }
        case 9:
        {
            const int SIZE = 5;
            int ary[SIZE] = {1, 2, 3, 4, 5};
            int *shift1;
            
            cout << "Original Array: ";
            for(int i = 0; i < SIZE; i++)
                cout << ary[i] << " ";
            cout << endl;
            cout << "Shifted Array: ";
            shift1 = shift(ary, SIZE);
            for(int i = 0; i < SIZE + 1; i ++)
                cout << shift1[i] << " ";
            delete[] shift1;
            break;
        }
        case 10:
        {
            int size, *donate;
            cout << "Input Size of Array: ";
            cin >> size;
            donate = new int[size];
            for(int i = 0; i < size; i++)
            {
                cout << "Enter Donation " << i + 1 << ": ";
                cin >> donate[i];
            }
            cout << "Sorted: ";
            sort(donate, size);
            for(int i = 0; i < size; i++)
                cout << donate[i] << "  ";
            
            
            delete []donate;
        }
        case 11: 
        {
            int size, *donate;
            cout << "Input Size of Array: ";
            cin >> size;
            donate = new int[size];
            for(int i = 0; i < size; i++)
            {
                cout << "Enter Donation " << i + 1 << ": ";
                cin >> donate[i];
            }
            cout << "Descending Sort: ";
            desSort(donate, size);
            for(int i = 0; i < size; i++)
                cout << donate[i] << "  ";
            
            
            delete []donate;
        }
    }
    return 0;
} 

float mean(int *a, int size)
{
    int sum = 0;
    float avg;
    for (int i = 0; i < size; i++)
        sum += a[i];
    avg = static_cast<float>(sum) / size;
    return avg;
}

void sort(int *a, int size)
{
    for (int i = 0; i < size; i++)
        for(int j = i+1; j < size; j++)
        {
            if(a[i] > a[j])
            {
                a[i] = a[i]^a[j];
                a[j] = a[i]^a[j];
                a[i] = a[i]^a[j];
            } 
        }   
}

void prntAry(int *a, int size)
{
    cout << endl;
    for (int i = 0; i < size; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

float med(int *a, int size)
{
    float med = 0;
    int mid;
    mid = size / 2;
    if (size%2 == 0)
    {
        med = (static_cast<float>(a[mid]) + a[mid - 1]) / 2;
    }
    else 
    {
        med = a[mid - 1];
    }
    return med;
}

int arySize(int size)
{
    cout << "Enter Size of Array: ";
    cin >> size;
    return size;
}

int *allocate(int size)
{
    int num;
    int *ary = new int[size];
    for (int i = 0; i < size; i++)
    {
        cout << "Enter number or test score " << i+1 << ": "  << endl;
        cin >> num;
        ary[i] = num;
    }
    return ary;
}

string *allName(int size)
{
    string n;
    string *ary = new string[size];
    for (int i = 0; i < size; i++)
    {
        cout << "Enter name of test taker " << i+1 << ": " << endl;
        cin >> n;
        ary[i] = n;
    }
    return ary;
}

int doSomething(int *x, int *y)
{
    int temp = *x;
    *x = *y * 10;
    *y = temp * 10;
    return *x+*y;
}

int *reverse(int ary[], int size)
{
    int *arry = new int[size];
    for(int i = 0; i < size; i++)
    {
        arry[i] = ary[size - 1 - i];
    }
    return arry;
}

int *crtAry(int ary[], int size)
{
    int *twice = new int[size*2];
    for(int i = 0; i < size; i++)
        twice[i] = ary[i];
    for(int i = size; i < size*2; i++)
        twice[i] = 0;
    return twice;
}

int *shift(int ary[], int size)
{
    int *arry = new int[size+1];
    arry[0] = 0;
    for(int i = 1; i < size + 1; i++)
        arry[i] = ary[i - 1];
    return arry;
}

int *mode(int *ary, int size)
{
    int count1 = 0, count2 = 0, temp = 0;
    int *freq = new int[size];
    int *top = new int[size];
    int *num = new int[size];
    int *mode = new int[4];
    sort(ary, size);
    for(int i = 0; i < size; i++)
        freq[i] = 0;
    for(int i = 0; i < size; i++)
    {
        if(i >= 1)
        {
            if(ary[i] == ary[i-1])
                count1++;
            if(ary[i] != ary[i-1])
            {
                if(count1 > count2 && count1 > 1)
                {
                count2 = count1;
                freq[i] = count2;
                
                }
                if(count1 == count2 && count1 > 1)
                    freq[i] = count2;
                count1 = 0;
            }
        }
        
    }
    
    for(int i = 0; i < size; i++)
    {
        if(freq[i] > temp)
            temp = freq[i];
    }
    
    
    for(int i = 0; i < size; i++)
    {
        if(freq[i] == temp)
            num[i] = ary[i-1];

    }
    
    sort(freq, size);
    for(int i = 1; i <= size; i++)
    {
        if(freq[i] > freq[i-1])
            top[i] = freq[i];
    }
    count1 = 0;
    sort(top, size);
    for(int i = 0; i < size; i++)
    {
        if(freq[i] == top[size-1])
            count1++;
    }
    mode[0] = count1;
    mode[1] = temp + 1;
    mode[2] = num[3];
    mode[3] = num[6];
    return mode;
}

void desSort(int *a, int size)
{
    for(int i = 0; i < size; i++)
        for(int j = i + 1; j < size; j++)
        {
            if(a[i] < a[j])
            {
                a[i] = a[i]^a[j];
                a[j] = a[i]^a[j];
                a[i] = a[i]^a[j];
            }
        }
}