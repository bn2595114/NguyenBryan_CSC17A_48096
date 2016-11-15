/* 
 * File:   PersonalData.h
 * Author: Bryan
 *
 * Created on November 14, 2016, 11:39 PM
 */

#ifndef PERSONALDATA_H
#define	PERSONALDATA_H

class Data
{
private:
    char* name;
    char* address;
    int age;
    char* number;
public:
    Data(char*, char*, int, char*);
    char* getName() const;
    char* getAddress() const;
    int getAge() const;
    char* getNumber() const;
    
};


#endif	/* PERSONALDATA_H */

