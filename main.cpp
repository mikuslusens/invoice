#include "invoice.hpp"
#include "product.hpp"
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    Invoice *invoice1 = new Invoice(1);
    invoice1->reciever = "Elkor";
    invoice1->sender = "Samsung Latvia";
    invoice1->invoiceDiscount = 15;

    Product *prod1 = new Product(1, "Samsung Galaxy S6", 450, 25);

	Product *prod2 = new Product(2, "Samsung X56GH55", 150, 0);

	vector<Product*> prodList;

	prodList.push_back(prod1);
	prodList.push_back(prod2);

	invoice1->addProduct(prodList, 1, 1);
	invoice1->addProduct(prodList, 2, 1);
	invoice1->addProduct(prodList, 1, 3);
	invoice1->addProduct(prodList, 2, 3);



/*
    prod1->name = "Samsung Galaxy S6";
    prod1->quantity = 10;
    prod1->price = 150;
    prod1->discount=15;
    prod1->totalPrice();
*/

   invoice1->printInvoice();



    return 0;
}
