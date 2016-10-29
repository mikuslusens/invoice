#include <string>

using namespace std;

class Product
{
public:
	Product(int id, string name, float price, float discount);
    int id;
	string name;
	float price;
	float discount;
};
