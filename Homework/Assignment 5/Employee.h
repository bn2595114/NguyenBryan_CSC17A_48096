/* 
 * File:   Employee.h
 * Author: Bryan
 *
 * Created on November 30, 2016, 8:26 PM
 */
#include <string>
using namespace std;
#ifndef EMPLOYEE_H
#define	EMPLOYEE_H

class Employee
{
private:
    string name;
    string number;
    string date;
public:
    string getName() const {return name;}
    string getNumber() const {return number;}
    string getDate() const {return date;}
    void setName(string n) {name = n;}
    void setNum(string n) {number = n;}
    void setDate(string d) {date = d;}
    
};

class ProductionWorker : public Employee
{
private:
    int shift;
    float payRate;
public:
    void setShift(int s) 
    { 
        shift = s;
    }
    void setPay(float p) {payRate = p;}
    int getShift() const {return shift;}
    int getPayRate() const {return payRate;}
   
};
#endif	/* EMPLOYEE_H */

