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

    Product *prod1 = new Product(1, "Galaxy S6", 450, 25);
	Product *prod2 = new Product(2, "X56GH55", 150, 0);
	Product *prod3 = new Product(3, "RTH-523", 45, 15);
	Product *prod4 = new Product(4, "Galavy Note 7", 599.99, 15);
	Product *prod5 = new Product(5, "TYU-452", 125.99, 0);

	vector<Product*> prodList;

	prodList.push_back(prod1);
	prodList.push_back(prod2);
	prodList.push_back(prod3);
	prodList.push_back(prod4);
	prodList.push_back(prod5);

	invoice1->addProduct(prodList, 1, 1);
	invoice1->addProduct(prodList, 2, 1);
	invoice1->addProduct(prodList, 1, 3);
	invoice1->addProduct(prodList, 2, 3);
	invoice1->addProduct(prodList, 3, 5);
	invoice1->removeProduct(3);
	invoice1->addProduct(prodList, 5, 10);


    invoice1->printInvoice();



    return 0;
}
