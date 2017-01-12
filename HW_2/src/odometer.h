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
		void resetMiles(void);
		void resetMPG(void);
	public:
		Odometer(double m = 0, float mpg = 0);
		void resetOdometer(void);
		void setMPG(float mpg);
		float getMPG(void);
		void addOdometer(double miles);
		double getFuel_consumed(void);

};



#endif /* ODOMETER_H_ */
