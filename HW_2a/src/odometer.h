/*
 * odometer.h
 *
 *  Created on: Jan 11, 2017
 *      Author: aaron
 */

#ifndef ODOMETER_H_
#define ODOMETER_H_

/*
 * UML Diagram:
 *  Odometer class:
 *  	Private:
 *  		total miles driven
 *  		miles per gallon
 *  		total gallons of fuel used
 *  		reset the odometer miles driven
 *  		reset the MPG value
 *  		reset the amount of fuel used
 *  	Public:
 *  		Odometer constructor (initialize)
 *  		reset the Odometer (and the miles driven and fuel consumed)
 *  		set the MPG
 *  		get the MPG
 *  		add miles to the odometer
 *  		get the fuel consumed
 *  		add fuel used to total count
 *  		set fuel consumed
 *  		change the MPG for the future trip
 */

class Odometer{
	private:
		double miles_driven;
		float miles_per_gallon;
		double gallons_used;
		void resetMiles(void);
		void resetMPG(void);
		void resetTank(void);
	public:
		Odometer(double m = 0, float mpg = 0, double gal = 0);
		void resetOdometer(void);
		void setMPG(float mpg);
		float getMPG(void);
		void addOdometer(double miles);
		double getFuel_consumed(void);
		void addTank(double galConsumed);
		void setTank(double galConsumed);
		void changeMPG(float mpg);

};



#endif /* ODOMETER_H_ */
