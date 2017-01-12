/*
 * odometer.cpp
 *
 *  Created on: Jan 11, 2017
 *      Author: aaron
 */

#include <iostream>
#include "odometer.h"

Odometer::Odometer(double m, float mpg, double gal){
	miles_driven = m;
	miles_per_gallon = mpg;
	gallons_used = gal;
}

void Odometer::resetMiles(void){
	miles_driven = 0;
}
void Odometer::resetMPG(void){
	miles_per_gallon = 0;
}
void Odometer::resetTank(void){
	gallons_used = 0;
}
void Odometer::addTank(double galConsumed){
	gallons_used += galConsumed;
}
void Odometer::setTank(double galConsumed){
	gallons_used = galConsumed;
}
void Odometer::resetOdometer(void){
	std::cout << "Reseting Odometer; clearing miles, MPG, and tank" << std::endl;
	resetMiles();
	resetMPG();
	resetTank();
	//miles_driven = 0;
	//miles_per_gallon = 0;
}
void Odometer::setMPG(float mpg){
	miles_per_gallon = mpg;
}
void Odometer::changeMPG(float mpg){
	addTank(getFuel_consumed());
	miles_per_gallon = mpg;
}
float Odometer::getMPG(void){
	return(miles_per_gallon);
}
void Odometer::addOdometer(double miles){
	miles_driven += miles;
}
double Odometer::getFuel_consumed(void){
	return(miles_driven / miles_per_gallon);
}




