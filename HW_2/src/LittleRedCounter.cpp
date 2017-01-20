/*
 * LittleRedCounter.cpp
 *
 *  Created on: Jan 20, 2017
 *      Author: aaron.covrig
 */

#include "LittleRedCounter.h"

Counter::Counter(int m){
	max = m;
	count = 0;
	bool overflow = false;
}
void Counter::reset(){
	count = 0;
}
void Counter::incr1(void){
	count += 1;
}
void Counter::incr10(void){
	count += 10;
}
void Counter::incr100(void){
	count += 100;
}
void Counter::incr1000(void){
	count += 1000;
}
bool Counter::didOverflow(void){
	return(overflow);
}



