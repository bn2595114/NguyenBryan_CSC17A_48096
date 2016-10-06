/* 
 * File:   Accounts.h
 * Author: Bryan
 *
 * Created on October 5, 2016, 7:30 PM
 */

#ifndef ACCOUNTS_H
#define	ACCOUNTS_H

struct Account
{
    char name[SIZE];
    char addr[SIZE];
    char cSZ[SIZE];
    char phone[SIZE];
    float bal;
    char lastPay[SIZE];
};


#endif	/* ACCOUNTS_H */

