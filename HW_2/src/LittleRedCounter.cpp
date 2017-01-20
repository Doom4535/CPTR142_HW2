/*
 * LittleRedCounter.cpp
 *
 *  Created on: Jan 20, 2017
 *      Author: aaron.covrig
 */

#include <iostream>
#include "LittleRedCounter.h"

Counter::Counter(int m){
	max = m;
	count = 0;
	bool overflow = false;
}
void Counter::reset(){
	count = 0;
	didOverflow();
	std::cout << "Count: " << count << std::endl;
}
void Counter::incr1(void){
	count += 1;
	didOverflow();
	std::cout << "Count: " << count << std::endl;
}
void Counter::incr10(void){
	count += 10;
	didOverflow();
	std::cout << "Count: " << count << std::endl;
}
void Counter::incr100(void){
	count += 100;
	didOverflow();
	std::cout << "Count: " << count << std::endl;
}
void Counter::incr1000(void){
	count += 1000;
	didOverflow();
	std::cout << "Count: " << count << std::endl;
}
bool Counter::didOverflow(void){
	if(count > max){
		overflow = true;
		std::cout << "Warning, overflow detected" << std::endl;
	}
	else{
		overflow = false;
	}
	return(overflow);
}

void counter_routine(){
	int max_count;
	bool loop = true;
	char ch;
	std::cout << "Enter the maximum count value: ";
	std::cin >> max_count;
	std:: cout << std::endl;
	Counter c1(max_count);
	while(loop){
		std::cout << "Enter a to increment by 1, s to increment by 10, d to increment by 100, and f to increment by 1000" << std::endl;
		std::cout << "To reset the counter press r, to check the overflow status, press o, and to end the program press e" << std::endl;
		std::cin >> ch;
		if(ch == 'a'){
			c1.incr1();
		}
		else if(ch == 's'){
			c1.incr10();
		}
		else if(ch == 'd'){
			c1.incr100();
		}
		else if(ch == 'f'){
			c1.incr1000();
		}
		else if(ch == 'o'){
			std::cout << c1.didOverflow() << std::endl;
		}
		else if(ch == 'r'){
			c1.reset();
		}
		else if(ch == 'e'){
			loop = false;
		}
	}
}



