/*
 * order.cpp
 *
 *  Created on: Jan 25, 2017
 *      Author: aaron
 */

#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <iomanip>
#include "order.h"

void Order::addOrder(Pizza pz){
	pizza_order.push_back(pz);
}

void Order::removeOrder(int entry_number){
	//pizza_order.remove(entry_number);
	pizza_order.erase(pizza_order.begin()+entry_number);
}

void Order::viewOrder(){
	// the printout alignment could be improved...
	int size = pizza_order.size();
	int i = 0;
	int num = 0;
	float totalPrice = 0;
	//std::cout << "Pizza Type: " << "    " << "Pizza Size: " << "    " << "Number of Toppings: " << "    " << "Discount: " << "    " << "Final Price: " << std::endl;
	std::cout << "Pizza Type: " << std::setw(20) << "Pizza Size: " << std::setw(25) << "Number of Toppings: " << std::setw(20) << "Discount: " << std::setw(20) << "Final Price: " << std::endl;
	while(i < size){
		std::cout << pizza_order[i].getType() << std::setw(20) << pizza_order[i].getSize() << std::setw(25) << pizza_order[i].get_num_Toppings() << std::setw(20) << pizza_order[i].getDiscount() << std::setw(20) << "$" << pizza_order[i].getPrice() << std::endl;
		num++;
		totalPrice += pizza_order[i].getPrice();
		i++;
	}
	std::cout << "Number of Pizzas: " << num << " Final Price: $" << totalPrice << std::endl;
}

int Order::verifyOrder(){
	int size = pizza_order.size();
	int i = 0;
	int status = 0;
	float totalPrice = 0;
	while(i < size){
		totalPrice += pizza_order[i].getPrice();
		i++;
	}
	if(totalPrice < 0){
		std::cout << "We encountered and error processing your order" << std::endl;
		std::cout << "Please specify the size using small/medium/large" << std::endl;
		std::cout << "We are going to redo the order now" << std::endl;
		status = 1; // Error detected
	}
	else{
		//std::cout << " Final Price: $" << totalPrice << std::endl;
		status = 0; // No detected errors in this routine
	}
	return(status);
}

float Order::priceOrder(){
	int size = pizza_order.size();
	int i = 0;
	float totalPrice = 0;
	while(i < size){
		totalPrice += pizza_order[i].getPrice();
		i++;
	}
	return(totalPrice);
}

void Order::resetOrder(){
	std::cout << "Reseting Order..." << std::endl;
	pizza_order.clear();
}





