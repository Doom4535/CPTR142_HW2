/*
 * pizza_shop.h
 *
 *  Created on: Jan 21, 2017
 *      Author: aaron
 */

#ifndef PIZZA_SHOP_H_
#define PIZZA_SHOP_H_

#include <string>
#include <vector>

class Pizza{
	private:
		std::string type;
		std::string size;
		int num_toppings;
		float small_rate; // = 10.00;
		float medium_rate; // = 14.00;
		float large_rate; // = 17.00;
		float topping_rate; // = 2.00;
		float discount; // = 0.00;	// Percent of (Price - Price * discount) = total
	public:
		Pizza(std::string t = "thin crust", std::string s = "medium", int num = 2, float sr = 10, float mr = 14, float lr = 17, float tr = 2, float d = 0);
		void setType(std::string t);
		std::string getType(void);
		void setSize(std::string s);
		std::string getSize(void);
		void set_num_Toppings(int num);
		int get_num_Toppings(void);
		float getPrice(void);
		//void setRate(std::string type, float type_base, std::string size, float size_base, int numT, float numT_base);
		void setSizeRate(std::string type, float type_base);
		void setToppingRate(float type_num_base);
		void setDiscount(float discout);
		float getDiscount(void);

};

/* Need to keep track of pizza order
 * UML diagram:
 * 	Order class:
 * 		Private:
 * 			Order contents
 * 		Public:
 * 			create order
 * 			add items to order
 * 			remove items from order
 * 			view the order (probably include the total price)
 * 			price the order
 * 			reset the order
 * 			place the order
*/


class Order{
	public:
		std::vector<Pizza> pizza_order;
	public:
		//Order();
		void addOrder(Pizza pz);
		void removeOrder(int entry_number);
		void viewOrder();
		void priceOrder();
		void resetOrder();
};



#endif /* PIZZA_SHOP_H_ */
