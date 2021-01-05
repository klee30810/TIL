/*
Project : 4_Flow_Control
Creator : Kyungmin Lee
Updator : Kyungmin Lee
Reference : C++ Ground Up by Herbert Schildt
*/

#include <iostream>

#include "myheader.h"


int main(int argc, char** argv) {
	int input;
	double length, area;
	
	char list[10];
	char* result;
	
	std::cout << "4. Flow Control\n";
	
	std::cout << "4-1 :	";
	std::cout << "num of angles :	";
	std::cin >> input;
	std::cout << "length of edge :	";
	std::cin >> length;
	area = CalculateArea(input, length);
	std::cout << area << "[m^2]\n";
	
	std::cout << "4-2 : ";
	std::cout << "input for delay : ";
	std::cin >> input;
	Delay(input);
	
	std::cout << "4-3 : ";
	std::cout << "input for 10 characters : ";
	std::cin >> list;
	Segment(list);
	
	std::cout << "4-4 : \n";
	DisplayMenu();
	
	std::cout << "4-5: ";
	SearchPrimeNum();

	std::cout << "4-6 input 10 characters: "; 
	std::cin >> list;
	Dots(list);
	
	std::cout << "4-7 : \n";
	PrintOdds();
	
	std::cout << "4-8 : input 10 characters: ";
	std::cin >> list;
	result = ToUpper(list);
	
	std::cout << "4-9 : input a number";
	std::cin >> input;
	Limit(input);
		
	return 0;
}
