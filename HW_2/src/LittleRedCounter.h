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
	public:
		void reset();
		void incr1(void);
		void incr10(void);
		void incr100(void);
		void incr1000(void);
		bool overflow(void);

};



#endif /* LITTLEREDCOUNTER_H_ */
