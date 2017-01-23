	/*
 * pizza.h
 *
 *  Created on: Jan 17, 2017
 *      Author: aaron.covrig
 */

#ifndef PIZZA_H_
#define PIZZA_H_

#include <string>

/*
 * UML diagram:
 *  Pizza class:
 *  	Private:
 *  		type
 *  		size
 *  		number of toppings
 *  		price for a small
 *  		price for a medium
 *  		price for a large
 *  		price per topping
 *  		discount (if any)
 *  	Public:
 *  		constructor
 *  		set pizza type
 *  		get pizza type
 *  		set pizza size
 *  		get pizza size
 *  		set the number of toppings
 *  		get the number of toppings
 *  		get the price of the pizza
 *  		set the size rate
 *  		set the topping rate
 *  		set the discount rate
 *  		get the discount rate
 */

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



#endif /* PIZZA_H_ */
