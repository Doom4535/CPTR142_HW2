/*
 * LittleRedCounter.h
 *
 *  Created on: Jan 20, 2017
 *      Author: aaron.covrig
 */

#ifndef LITTLEREDCOUNTER_H_
#define LITTLEREDCOUNTER_H_

/*
 * UML Diagram:
 *  Counter class:
 *  	Private:
 *  		count (total value counted)
 *  		max (the value that the device will overflow at
 *  		overflow (did the device overflow?, yes/no)
 *  	Public:
 *  		create a counter (constructor, default to a value of 0)
 *  		reset/clear the counter (clear count and overflow)
 *  		increment by 1 (also check if the addition will cause an overflow)
 *  		increment by 10 (also check if the addition will cause an overflow)
 *  		increment by 100 (also check if the addition will cause an overflow)
 *  		increment by 1000 (also check if the addition will cause an overflow)
 *  		check if overflow set
 */

class Counter{
	private:
		int count;
		int max;
		bool overflow;
	public:
		Counter(int m = 0);
		void reset();
		void incr1(void);
		void incr10(void);
		void incr100(void);
		void incr1000(void);
		bool didOverflow(void);

};

void counter_routine();



#endif /* LITTLEREDCOUNTER_H_ */
