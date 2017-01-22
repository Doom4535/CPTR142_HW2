/*
 * LittleRedCounter.h
 *
 *  Created on: Jan 20, 2017
 *      Author: aaron.covrig
 */

#ifndef LITTLEREDCOUNTER_H_
#define LITTLEREDCOUNTER_H_

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
