/* Import the header file */
#include "Product.h"

/* This function sets all Product attributes at once. It takes the PLU, name,
type, price, and inventory in that order and stores them in the corresponding
private member variables. */
void Product::setProductAttributes(string productPLU, string productName,
								   int productType, double productPrice,
								   int productInventory) {
	PLU = productPLU;
	name = productName;
	type = productType;
	price = productPrice;
	inventory = productInventory;
}

/* This function sets the inventory member variable for the Product object. It
takes an integer inventory value and stores it as the current inventory. */
void Product::setInventory(int productInventory) {
	inventory = productInventory;
}

/* This function returns the PLU code stored in the Product object. */
string Product::getPLU() const {
	return PLU;
}

/* This function returns the name stored in the Product object. */
string Product::getName() const {
	return name;
}

/* This function returns the sales type stored in the Product object. */
int Product::getType() const {
	return type;
}

/* This function returns the unit price stored in the Product object. */
double Product::getPrice() const {
	return price;
}

/* This function returns the current inventory stored in the Product object. */
int Product::getInventory() const {
	return inventory;
}