//============================================================================
// Name        : HW_2.cpp
// Author      : Aaron Covrig
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "odometer.h"
#include "pizza.h"

int prob_1(void); // #6
int prob_2(void); // #7

int main() {
	std::cout << "!!!Hello World!!!" << std::endl; // prints !!!Hello World!!!
	prob_1();
	prob_2();
	return 0;
}

int prob_1(void){
	Odometer car1(0, 20, 0);
	std::cout << "Trip 1: Going to store" << std::endl;
	car1.addOdometer(20);
	std::cout << "Total fuel used so far: " << car1.getFuel_consumed() << " gallons" << std::endl;
	std::cout << "Trip 2: Going to Jim's" << std::endl;
	car1.addOdometer(12);
	std::cout << "Total fuel used so far: " << car1.getFuel_consumed() << " gallons" << std::endl;
	std::cout << "Trip 3: Pick up Becca:" << std::endl;
	car1.addOdometer(8);
	std::cout << "Total fuel used so far: " << car1.getFuel_consumed() << " gallons" << std::endl;
	std::cout << "Trip 4: Going to shop: " << std::endl;
	car1.addOdometer(15);
	std::cout << "Total fuel used so far: " << car1.getFuel_consumed() << " gallons" << std::endl;
	car1.resetOdometer();
	std::cout << "Car repaired, Odometer reset" << std::endl;
	std::cout << "Preparing for cross country trip: " << std::endl;
	car1.setMPG(18);
	car1.addOdometer(1500);
	std::cout << "Total fuel used so far: " << car1.getFuel_consumed() << " gallons" << std::endl;
	std::cout << "Entering mountainous region, MPG lower" << std::endl;
	car1.changeMPG(14);
	car1.addOdometer(500);
	std::cout << "Total fuel used so far: " << car1.getFuel_consumed() << " gallons" << std::endl;
	std::cout << "Leaving mountainous region, MPG higher" << std::endl;
	car1.changeMPG(18);
	car1.addOdometer(2200);
	std::cout << "Trip done, total fuel used: " << car1.getFuel_consumed() << " gallons" << std::endl;

	return(0);
}

int prob_2(void){
	std::cout << "Starting Problem 2 (Ch. 6, #7)" << std::endl;
	Pizza p1; // Making a premade pizza for quick order
	std::cout << "Price for quick order pizza, type: " << p1.getType() << ", size: " << p1.getSize() << ", number of Toppings: " << p1.get_num_Toppings() << std::endl;
	std::cout << "Price: " << p1.getPrice();
	return(0);
}
