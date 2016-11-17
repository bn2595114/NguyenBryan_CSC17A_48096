/* 
 * File:   RetailItem.h
 * Author: Bryan
 *
 * Created on November 16, 2016, 8:25 PM
 */

#ifndef RETAILITEM_H
#define	RETAILITEM_H

class RetailItem
{
private:
    char* description;
    int unitsOnHand;
    float price;
public:
    RetailItem(char*, int, float);
    char* getDes() const;
    int getUnits() const;
    float getPrice() const;
};

#endif	/* RETAILITEM_H */

