//============================================================================
// Name        : HW_2b.cpp
// Author      : Aaron Covrig
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <queue>
#include "pizza.h"
#include "order.h"
//using namespace std;

int main() {
	// Currently locked in perpetual order loop intentionally
	std::cout << "Loading PizzaTron..." << std::endl; // prints

	std::queue <Order> current_orders;

	std::vector<Order> daily_record;
	bool loop = true;
	int i = 0;
	std::string input;
	while(loop){
		Order order;
		bool choosing = true;
		while(choosing){
			Pizza pi;
			std:: cout << "Your order number is: #" << i << std::endl;
			std::cout << "What type of pizza crust do you want? " << std::endl;
			getline(std::cin, input);
			pi.setType(input);
			std::cout << "What size of pizza would you like (small/medium/large)? " << std::endl;
			std::cin >> input;
			pi.setSize(input);
			bool topping_selection = true;
			while(topping_selection){
				pi.set_Toppings();
				std::cout << "You have selected the following toppings: ";
				pi.list_Toppings();
				std::cout << std::endl;
				std::cout << "Is this correct? (Y/n): ";
				std::cin >> input;
				std::cout << std::endl;
				if(input == "N" || input == "n" || input == "No" || input == "NO" || input == "no"){
					std::cout << "Clearing the selected toppings" << std:: endl;
				}
				else{
					// Default action
					topping_selection = false;
				}
			}
			order.addOrder(pi);
			std::cout << "The cost for this pizza is: $" << pi.getPrice() << std::endl;
			std::cout << "Would you like to add another pizza? (Y/n): ";
			std::cin >> input;
			std::cout << std::endl;
			if(input == "N" || input == "n" || input == "No" || input == "NO" || input == "no"){
				std::cout << "Processing order..." << std:: endl;
				if(order.verifyOrder() == 0){
					// no error in order detected
					choosing = false;
				}
				else{
					// reseting if an error detected
					choosing = true;
					order.resetOrder();
				}
			}
			else{
				// Default action
				choosing = true;
			}
			std::cin.ignore();
		}
		std::cout << "Your order is: " << std::endl;
		order.viewOrder();
		std::cout << "Is the above order correct? (Y/n): ";
		std::cin >> input;
		std::cout << std::endl;
		if(input == "N" || input == "n" || input == "No" || input == "NO" || input == "no"){
			std::cout << "Ok, reseting the order" << std:: endl;
			order.resetOrder();
		}
		else{
			// Default action
			order.viewOrder();
			daily_record.push_back(order);
			current_orders.push (order);
			std::cout << "Your order number is: #" << i << std::endl;
			i++;
			std::cout << std::endl;
			std::cout << "Thank you for shopping at Pizza Land" << std::endl << std::endl;
			std::cin.ignore();
		}
	}

	return(0);
}
