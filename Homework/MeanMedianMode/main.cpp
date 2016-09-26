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

int main(int argc, char** argv) {
    
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

