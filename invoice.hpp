#include <string>
#include <vector>
#include "invoiceItem.hpp"

//#include "product.hpp"

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
	vector<invoiceItem*> invProdList;
	void addProduct(vector<Product*> prodList, int id, int quantity);
	void printInvoice(void);
};
