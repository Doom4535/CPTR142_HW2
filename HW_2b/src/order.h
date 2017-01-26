/*
 * order.h
 *
 *  Created on: Jan 25, 2017
 *      Author: aaron
 */

#ifndef ORDER_H_
#define ORDER_H_

#include <vector>
#include "pizza.h"

/*
 * UML diagram:
 * 	Order class:
 * 		Private:
 * 			Order contents
 * 		Public:
 * 			//create order (using default)
 * 			add items to order
 * 			remove items from order
 * 			view the order (probably include the total price)
 * 			verify the order (some simple error checking)
 * 			price the order
 * 			reset the order
 * 			//place the order
*/


class Order{
	private:
		std::vector<Pizza> pizza_order;
	public:
		//Order();
		void addOrder(Pizza pz);
		void removeOrder(int entry_number);
		void viewOrder();
		int verifyOrder();
		float priceOrder();
		void resetOrder();
};





#endif /* ORDER_H_ */
