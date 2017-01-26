/*
 * pizza_shop.cpp
 *
 *  Created on: Jan 21, 2017
 *      Author: aaron
 */

#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <iomanip>
#include "pizza_shop.h"


Pizza::Pizza(std::string t, std::string s, float sr, float mr, float lr, float tr, float d){
	type = t;
	size = s;
	std::vector<std::string> topping_selection;
	num_toppings = 0;
	small_rate = sr;
	medium_rate = mr;
	large_rate = lr;
	topping_rate = tr;
	discount = d;
	//set_Toppings();
}
void Pizza::setType(std::string t){
	type = t;
}
std::string Pizza::getType(void){
	return(type);
}
void Pizza::setSize(std::string s){
	bool loop = true;
	while(loop){
		size = s;
		if(size == "small" || size == "Small" || size == "SMALL" || size == "s" || size == "S"){
			loop = false;
		}
		else if(size == "medium" || size == "Medium" || size == "MEDIUM" || size == "m" || size == "M"){
			loop = false;
		}
		else if(size == "large" || size == "Large" || size == "LARGE" || size == "l" || size == "L"){
			loop = false;
		}
		else{
			// being terrible and hijacking input here if an incorrect entry is detected
			loop = true;
			std::cout << "Please specify the size using small/medium/large" << std::endl;
			std::cin >> s;
			std::cout << std::endl;
		}
	}
}
std::string Pizza::getSize(void){
	return(size);
}

void Pizza::set_Toppings(void){
	std::string topping;
	std::string input;
	int n = 0;
	//while((topping != "/n") || (topping != "/r") || (topping != "/n/r")){
	std::cout << "Please enter the toppings you would like separated with a space: ";
	/*
	getline(std::cin, input);
	std::stringstream s (input);
	while(s >> topping){
		topping_selection.push_back(topping);
		n++;
	}
	*/
	std::cin.ignore();
	getline(std::cin, input);
	std::string temp;
	//vector <string> cds;
	std::stringstream s (input);
	while(s>> temp){
		topping_selection.push_back(temp);
		n++;
	}
	set_num_Toppings(n);
	std::cout << std::endl;
}

void Pizza::list_Toppings(void){
	int size = topping_selection.size();
	int i = 0;
	while(i < size){
		std::cout << topping_selection[i] << " ";
		i++;
	}
}

void Pizza::reset_Toppings(void){
	topping_selection.clear();
	num_toppings = 0;
}
void Pizza::remove_Last_Topping(void){
	if((num_toppings > 0) && (topping_selection.size() >0)){
		topping_selection.pop_back();
		num_toppings--;
	}
	else{
		std::cout << "We have detected an error while processing your order, please contact a sales associate" << std::endl;
	}
}

void Pizza::set_num_Toppings(int num){
	num_toppings = num;
}
int Pizza::get_num_Toppings(void){
	return(num_toppings);
}
float Pizza::getPrice(void){
	// Currently all types of crust the same size
	float sRate = 0;
	float price = 0;
	float total = 0;
	if(size == "small" || size == "Small" || size == "SMALL" || size == "s" || size == "S"){
		sRate = small_rate;
	}
	else if(size == "medium" || size == "Medium" || size == "MEDIUM" || size == "m" || size == "M"){
		sRate = medium_rate;
	}
	else if(size == "large" || size == "Large" || size == "LARGE" || size == "l" || size == "L"){
		sRate = large_rate;
	}
	else{
		std::cout << "We had an issue computing the price, this error seems related to the size" << std::endl;
		std::cout << "Please specify the size using small/medium/large" << std::endl;
	}

	price = sRate + num_toppings * topping_rate;
	total = price * (1 - discount);
	return(total);
}
//void pizza::setRate(std::string type, float type_base, std::string size, float size_base, int numT, float numT_base);
void Pizza::setSizeRate(std::string type, float type_base){
	std::cout << "Please enter the size ('large/medium/small) followed by the price: ";
	std::cin >> type;
	std::cin >> type_base;
	if(type == "small"){
		small_rate = type_base;
	}
	else if(type == "medium"){
		medium_rate = type_base;
	}
	else if(type == "large"){
		large_rate = type_base;
	}
	else{
		std::cout << "You entered an invalid combination" << std::endl;
	}
}
void Pizza::setToppingRate(float type_num_base){
	topping_rate = type_num_base;
}
void Pizza::setDiscount(float percent_off){
	discount = percent_off;
}

float Pizza::getDiscount(void){
	return(discount);
}


// Order field

//Order::Order(){
//
//}

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


