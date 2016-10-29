#include <iostream>
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

void invoiceItem::setQuantity(int quantity)
{
    this->quantity = this->quantity + quantity;
}

void invoiceItem::printItem(void)
{
    cout << "Preces nosaukums: " << this->name << endl;
    cout << "Preces daudzums: " << this->quantity << endl;
}

void invoiceItem::totalPrice(void)
{
    productDiscount = ((this->price) * (this->quantity)) * ((this->discount) / 100);
    total = ((this->price) * (this->quantity)) - (this->productDiscount);
}
