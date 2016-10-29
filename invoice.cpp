#include "invoice.hpp"
#include "product.hpp"
#include <iostream>

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
                product = (*it);
                invProdList.push_back(new invoiceItem(product->id, product->name, quantity, product->price,
                                                              product->discount));
                cout << "Item added" <<endl;
                delete product;
        }

    }

}

void Invoice::printInvoice(void)
{
    cout << "\tPavadzimes numurs: " << this->id << endl;
    cout << "\tPiegadatajs: " << this->sender << endl;
    cout << "\tSanemejs:" << this->reciever << "\n" << endl;
    cout << "Pavadzimes preces:" << endl;
    cout << "Artikuls\t" << "Nosaukums\t" << "Cena\t" << "Atlaide" << endl;
    for(vector<invoiceItem*>::iterator it = invProdList.begin() ; it != invProdList.end(); ++it)
        (*it)->printItem();


}
