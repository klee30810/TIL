/*
Project : 2_C++_Outline
Creator : Kyungmin Lee
Updator : Kyungmin Lee
Reference : C++ Ground Up by Herbert Schildt
*/

#include <iostream>
#include "myheader.h"



int main(){
	int a, b, c;
	double dollar, pound, moon, earth;
	
	cout << "2. C++ Outline!\n";
	
	cout << "2-1 :	";
	cin >> dollar;
	pound = exchange(dollar);
	cout << pound << "$\n";
		
	cout << "2-2 :	";
	cin >> earth;
	moon = moongrav(earth);
	cout << moon << "[g]\n";
	
	cout << "2-3 :	";
	cin >> a;
	cin >> b;
	c = expcal(a, b);
	cout << c << "\n";
	
	return 0;
}

