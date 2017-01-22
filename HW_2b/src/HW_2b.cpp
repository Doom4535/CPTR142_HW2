//============================================================================
// Name        : HW_2b.cpp
// Author      : Aaron Covrig
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include "pizza_shop.h"
using namespace std;

int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	Pizza pi1, pi2;
	std::vector<Pizza> pi_order;
	pi_order.push_back(pi1);
	pi_order.push_back(pi2);
	std::cout << pi_order[0].getDiscount() << std::endl;

	Order mypizzaOrder;
	mypizzaOrder.addOrder(pi1);
	mypizzaOrder.addOrder(pi2);
	mypizzaOrder.viewOrder();
	Pizza pi3("Deep Dish", "large", 4);
	mypizzaOrder.addOrder(pi3);
	mypizzaOrder.viewOrder();

	return(0);
}
