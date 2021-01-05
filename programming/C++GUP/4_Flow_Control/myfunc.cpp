#include <iostream>
#include "myheader.h"

double CalculateArea(int num, double length){
	double area;
	
	if (num==0)	{
		area = PI * length * length;
	}
		
	else if (num==3) {
		area = 0.5 * length * length;
	}
			
	else {
		area = length * length;
	} 
		
	return area;
}

void Delay(int input){
	int i;
	
	for(i=input;i>0;i--)
		std::cout << i << "\n";
		
	std::cout << "sound" << "\a";
}

void Segment(char list[10]){
	int i, p=0, num=0, cha=0, option;
	
	for(i=0;i<10;i++){
		
		if (((64<list[i]) && (list[i]<91)) || ((96<list[i]) && (list[i]<123))) {
			option = 1;	
		}
		else if ((47<list[i]) && (list[i]<58)){
			option = 2;	
		}
		else 
			option = 3;
		
		switch(option){
			case 1:
				++cha;
				continue;
			
			case 2:
				++num;
				continue;
				
			case 3:
				++p;
				continue;
		}
	}
	
	std::cout << "char: " << cha << "\n";
	std::cout << "num: " << num << "\n";
	std::cout << "point: " << p << "\n";
}

void DisplayMenu(){
	int choice;
	
	do{
		std::cout << "1. Enter address\n2. Delete address\n3. Search the list\n4.Print the list\n5. Quit\n";
		std::cout << "Enter the number of your choice (1-5): ";
		std::cin >> choice;	
	}while((choice>5) || (choice<1));
		
}

void SearchPrimeNum(){
	int i, j, result;
	
	for (i=1000;i<2000;i++){
		for (j=2;j<2000;j++){
			if (i%j == 0) {
				break;
			}
			result = i;
		}
		std::cout << result << "\n";
	}
}

void Dots(char list[10]){
	int i, j;
	
	for(i=0;i<10;i++){
		for(j=0; j<(int)list[i];j++){
			std::cout << ".";
		}
		std::cout << "\n";
	}
}

void PrintOdds(){
	int i;
	
	for(i=0; i<101; i++){
		if(i%2 != 0) std::cout << i << "\n";
	}
}

char* ToUpper(char list[10]){
	int i;
	char result[10];
	
	for(i=0; i<10; i++){
		if ((list[i]>96) && (list[i]<123))
			result[i] = list[i]-32;
		else result[i] = list[i];
	}
	
	std::cout << result << "\n";
	return result;
}

void Limit(int input){
	if (input == 0) std::cout << "input is zero\n";
	else 
		if (input > 0) std::cout << "input is positive\n";
		else std::cout << "input is negetive\n";
}


