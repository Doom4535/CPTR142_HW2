/*
 * odometer.h
 *
 *  Created on: Jan 11, 2017
 *      Author: aaron
 */

#ifndef ODOMETER_H_
#define ODOMETER_H_

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
