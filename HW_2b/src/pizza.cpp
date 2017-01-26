/*
 * pizza.cpp
 *
 *  Created on: Jan 25, 2017
 *      Author: aaron
 */

#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <iomanip>
#include "pizza.h"


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



