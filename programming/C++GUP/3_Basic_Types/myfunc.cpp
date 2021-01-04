#include <cmath>
#include <iostream>

#include "myheader.h"

double timecal(unsigned long int mile){
	double time;
	time = mile / 186000;
	
	return time;	
}

void decrease(float cnt){
	for(int i = (int)cnt;i < 10; i++){
		for(int j = 1; j < 11; j++){
			cout << j << " ";
		}
		cout << "\n";
	}
}

int series(int prev){
	int next;
	next = (prev * 1468) % 467;
	
	return next;
}
