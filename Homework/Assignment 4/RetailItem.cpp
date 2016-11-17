#include "RetailItem.h"

RetailItem::RetailItem(char* d, int u, float p)
{
    description = d;
    unitsOnHand = u;
    price = p;
}

char* RetailItem::getDes() const
{
    return description;
}

int RetailItem::getUnits() const
{
    return unitsOnHand;
}

float RetailItem::getPrice() const
{
    return price;
}