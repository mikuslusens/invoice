#include "invoice.hpp"
#include "product.hpp"
#include <iostream>
#include <cstdio>

using namespace std;

Invoice::Invoice(int id)
{
	this->id = id;
}

void Invoice::addProduct(vector<Product*> prodList, int id, int quantity)
{
    Product *product;
    bool found = false;
    if (invProdList.size() != 0) {
        for(vector<invoiceItem*>::iterator it = invProdList.begin() ; it != invProdList.end(); it++) {
            if((*it)->getId() == id) {
                (*it)->setQuantity(quantity);
                found = true;
                break;
            }
        }
    }
    if(found == true)
        cout << "Quantity modified" << endl;
    else {
    for(vector<Product*>::iterator it = prodList.begin() ; it != prodList.end(); ++it) {
            if((*it)->id == id)
            {
                product = (*it);
                invProdList.push_back(new invoiceItem(product->id, product->name, quantity, product->price,
                                                              product->discount));
                cout << "Item added" <<endl;
             ///   delete product;
             break;
            }
        }
    }
}

void Invoice::removeProduct(int id)
{
    for(vector<invoiceItem*>::iterator it = invProdList.begin() ; it != invProdList.end(); it++) {
        if((*it)->getId() == id) {
            invProdList.erase(it);
            cout << "Item deleted" <<endl;
            break;
        }
    }
}


float Invoice::sumInvoiceTotal(void)
{
    for(vector<invoiceItem*>::iterator it = invProdList.begin() ; it != invProdList.end(); it++)
    invoiceTotal = invoiceTotal + (*it)->getTotal();
    return invoiceTotal;
}

float Invoice::sumInvoiceTotalDiscount(void)
{
    invoiceTotalDiscount = invoiceTotal - (invoiceTotal * invoiceDiscount)/100;
    return invoiceTotalDiscount;
}

void Invoice::printInvoice(void)
{
    cout << "\tPavadzimes numurs: " << this->id << endl;
    cout << "\tPiegadatajs: " << this->sender << endl;
    cout << "\tSanemejs: " << this->reciever << endl;
    cout << "\tAtlaide: " << this->invoiceDiscount << "%" << "\n" <<endl;
    cout << "Pavadzimes preces:" << endl;
    printf("%10s%15s%10s%10s%10s%10s", "Artikuls", "Nosaukums", "Cena", "Atlaide", "Daudzums", "Kopaa");
    printf("\n");
    printf("%10s%15s%10s%10s%10s%10s", "--------", "---------", "----", "------", "--------", "-----");
    printf("\n");
    for(vector<invoiceItem*>::iterator it = invProdList.begin() ; it != invProdList.end(); ++it)
        (*it)->printItem();
    printf("%10s%15s%10s%10s%10s%10s", "--------", "---------", "----", "------", "--------", "-----");
    printf("\n");
    printf("%55s%10.2f", "Kopaa:", this->sumInvoiceTotal());
    printf("\n");
    printf("%55s%10.2f", "Kopaa ar atlaidi:", this->sumInvoiceTotalDiscount());


}
