#include <iostream>
#include <iomanip>
#include <cstdio>
#include "invoiceItem.hpp"


using namespace std;

invoiceItem::invoiceItem(int id, string name, int quantity, float price, float discount)
{
    this->id = id;
    this->name = name;
    this->quantity = quantity;
    this->price = price;
    this->discount = discount;
}

int invoiceItem::getId(void)
{
    return this->id;
}

float invoiceItem::getTotal(void)
{
    return this->total;
}

void invoiceItem::setQuantity(int quantity)
{
    this->quantity = this->quantity + quantity;
}

void invoiceItem::printItem(void)
{
    printf("%10d%15s%10.2f%9.0f%%%10d%10.2f", this->getId(), this->name.c_str(),
           this->price, this->discount, this->quantity, this->totalPrice());
    printf("\n");
}

float invoiceItem::totalPrice(void)
{
    productDiscount = ((this->price) * (this->quantity)) * ((this->discount) / 100);
    total = ((this->price) * (this->quantity)) - (this->productDiscount);
    return total;
}
