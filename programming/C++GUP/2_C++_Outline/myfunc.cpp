#include <cmath>
#include "myheader.h"

double exchange(double dollar){
	double pound;	
	pound = 2 * dollar;
	
	return pound;
}

double moongrav(double earthgrav){
	double moongrav;	
	moongrav = 0.17 * earthgrav;
	
	return moongrav;
}

int expcal(int a, int b){
	int result;
	result = pow(a, b);
	
	return result;
}
