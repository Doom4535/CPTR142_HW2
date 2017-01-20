//============================================================================
// Name        : HW_2.cpp
// Author      : Aaron Covrig
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include "odometer.h"
#include "pizza.h"
#include "LittleRedCounter.h"

int prob_1(void); // #6
int prob_2(void); // #7
int prob_3(void); // #7.3

using namespace std;

int main() {
	std::cout << "!!!Hello World!!!" << std::endl; // prints !!!Hello World!!!
	prob_1();
	prob_2();
	prob_3();
	return 0;
}

int prob_1(void){
	// Two test trip objects
	Odometer trip1, trip2;

	vector<Odometer> trips;
	trips.push_back(trip1);
	trips.push_back(trip2);

	trips[0].resetOdometer();
	trips[0].setMPG(20);
	//trips[0].addOdometer(100);

	std::cout << "Trip 1: Going to store" << std::endl;
	trips[0].addOdometer(20);
	std::cout << "Total fuel used so far: " << trips[0].getFuel_consumed() << " gallons" << std::endl;
	std::cout << "Trip 2: Going to Jim's" << std::endl;
	trips[0].addOdometer(12);
	std::cout << "Total fuel used so far: " << trips[0].getFuel_consumed() << " gallons" << std::endl;
	std::cout << "Trip 3: Pick up Becca:" << std::endl;
	trips[0].addOdometer(8);
	std::cout << "Total fuel used so far: " << trips[0].getFuel_consumed() << " gallons" << std::endl;
	std::cout << "Trip 4: Going to shop: " << std::endl;
	trips[0].addOdometer(15);
	std::cout << "Total fuel used so far: " << trips[0].getFuel_consumed() << " gallons" << std::endl;

	trips[1].resetOdometer();
	std::cout << "Car repaired, Odometer reset" << std::endl;
	std::cout << "Preparing for cross country trip: " << std::endl;
	trips[1].setMPG(18);
	trips[1].addOdometer(1500);
	std::cout << "Total fuel used so far: " << trips[1].getFuel_consumed() << " gallons" << std::endl;
	std::cout << "Entering mountainous region, MPG lower" << std::endl;
	trips[1].changeMPG(14);
	trips[1].addOdometer(500);
	std::cout << "Total fuel used so far: " << trips[1].getFuel_consumed() << " gallons" << std::endl;
	std::cout << "Leaving mountainous region, MPG higher" << std::endl;
	trips[1].changeMPG(18);
	trips[1].addOdometer(2200);
	std::cout << "Trip done, total fuel used: " << trips[1].getFuel_consumed() << " gallons" << std::endl;

	return(0);
}

int prob_2(void){
	std::cout << "Starting Problem 2 (Ch. 6, #7)" << std::endl;
	Pizza p1; // Making a premade pizza for quick order
	std::cout << "Price for quick order pizza, type: " << p1.getType() << ", size: " << p1.getSize() << ", number of Toppings: " << p1.get_num_Toppings() << std::endl;
	std::cout << "Price: " << p1.getPrice();
	Pizza p2("thick crust", "large", 6);
	std::cout << std::endl;
	std::cout << "Next pizza order was a... " << p2.getType() << ", size: " << p2.getSize() << ", number of toppings: " << p2.get_num_Toppings() << std::endl;
	return(0);
}

int prob_3(void){
	counter_routine();
	return(0);
}
