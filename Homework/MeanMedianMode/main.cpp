/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Bryan Nguyen
 * Purpose: return mean, median, mode
 * Created on September 26, 2016, 12:45 PM
 */

#include <cstdlib>
#include <iostream>
using namespace std;

 
int *mode(int *, int, float&, float&);

float mean(int *, int);
void sort(int *, int);
void prntAry(int *, int);
float med(int *, int);

int arySize(int);
int *allocate(int);

void ascSort(int *, int);
int main(int argc, char** argv) {
    int num;
    cout << "Choose the number" << endl;
    cout << "1) Mean Median Mode" << endl;
    cout << "2) 9.1 Array Allocator" << endl;
    cout << "3) 9.2 Test Scores #1" << endl;
    cout << "4) 9.3 Drop Lowest Score" << endl;
    cout << "5) 9.4 Test Scores #2" << endl;
    
    cin >> num;
    
    switch (num)
    {
            case 1: 
            {
    const int SIZE = 8;
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
    
    cout << "Mean is: " << mean(array, SIZE) << endl;
    cout << "Median is: " << med(array, SIZE);
    
    delete[] array;
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
        }
    }
    return 0;
}

int *mode(int *a, int size, float& avg, float& med)
{
    
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
        cout << "Enter number or test score: " << endl;
        cin >> num;
        ary[i] = num;
    }
    return ary;
}

