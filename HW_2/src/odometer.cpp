/*
 * odometer.cpp
 *
 *  Created on: Jan 11, 2017
 *      Author: aaron
 */

#include "odometer.h"

Odometer::Odometer(double m, float mpg){
	miles_driven = m;
	miles_per_gallon = mpg;
}

void Odometer::resetMiles(void){
	miles_driven = 0;
}
void Odometer::resetMPG(void){
	miles_per_gallon = 0;
}

void Odometer::resetOdometer(void){
	resetMiles();
	resetMPG();
	//miles_driven = 0;
	//miles_per_gallon = 0;
}
void Odometer::setMPG(float mpg){
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




