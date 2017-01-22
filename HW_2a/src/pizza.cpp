/*
 * pizza.cpp
 *
 *  Created on: Jan 17, 2017
 *      Author: aaron.covrig
 */

#include <string>
#include <iostream>
#include "pizza.h"

Pizza::Pizza(std::string t, std::string s, int num, float sr, float mr, float lr, float tr, float d){
	type = t;
	size = s;
	num_toppings = num;
	small_rate = sr;
	medium_rate = mr;
	large_rate = lr;
	topping_rate = tr;
	discount = d;
}
void Pizza::setType(std::string t){
	type = t;
}
std::string Pizza::getType(void){
	return(type);
}
void Pizza::setSize(std::string s){
	size = s;
}
std::string Pizza::getSize(void){
	return(size);
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
	if(size == "small"){
		sRate = small_rate;
	}
	else if(size == "medium"){
		sRate = medium_rate;
	}
	else if(size == "large"){
		sRate = large_rate;
	}
	else{
		std::cout << "We had an issue computing the price, this error seems related to the size" << std::endl;
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

