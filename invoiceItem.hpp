#include <string>

using namespace std;

class invoiceItem
{
private:
    int id;
    string name;
    int quantity;
    float price;
    float discount;
    float total;
	float productDiscount;
public:
    invoiceItem(int id, string name, int quantity, float price, float discount);
    int getId(void);
    float getTotal(void);
    void setQuantity(int quantity);
    void printItem(void);
    float totalPrice(void);
};
