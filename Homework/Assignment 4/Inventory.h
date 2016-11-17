/* 
 * File:   Inventory.h
 * Author: Bryan
 *
 * Created on November 16, 2016, 9:13 PM
 */

#ifndef INVENTORY_H
#define	INVENTORY_H

class Inventory
{
private:
    int itemNumber;
    int quantity;
    float cost;
    float totalCost;
public:
    void setTotalCost()
    {
        totalCost = quantity*cost;
    };
    Inventory();
    Inventory(int i, int q, float c)
    {
        itemNumber = i;
        quantity = q;
        cost = c;
        setTotalCost();
    };
    
    int getNum() const {return itemNumber;}
    int getQuan() const {return quantity;}
    float getCost() const {return cost;}
    float getTotal() const {return totalCost;}
};


#endif	/* INVENTORY_H */

