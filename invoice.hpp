#include <string>
#include <vector>
#include "invoiceItem.hpp"

using namespace std;

class Product;

class Invoice
{
public:
	Invoice(int id);
	int id;
	string reciever;
	string sender;
	float invoiceDiscount;
	float invoiceTotal;
	float invoiceTotalDiscount;
	vector<invoiceItem*> invProdList;
	void addProduct(vector<Product*> prodList, int id, int quantity);
	void removeProduct(int id);
	float sumInvoiceTotal(void);
	float sumInvoiceTotalDiscount(void);
	void printInvoice(void);
};
