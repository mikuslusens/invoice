#include "product.hpp"
#include <iostream>

using namespace std;

Product::Product(int id, string name, float price, float discount)
{
	this->id = id;
	this->name = name;
	this->price = price;
	this->discount = discount;
}


