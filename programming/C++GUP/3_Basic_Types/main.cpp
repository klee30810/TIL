/*
Project : 3_Basic_Types
Creator : Kyungmin Lee
Updator : Kyungmin Lee
Reference : C++ Ground Up by Herbert Schildt
*/

#include <iostream>
#include "myheader.h"

extern int prev;

int main(){
	int cnt, control, next;
	double time;
	unsigned long int mile;
	
	cout << "3. Basic Types\n";
	
	cout << "3-5 :	";
	cin >> mile;
	time = timecal(mile);
	cout << time << "[s]\n";
		
	cout << "3-7 :	";
	cin >> control;
	cnt = 10 - control;
	decrease(cnt);
	
	cout << "3-8 : 	";
	cin >> prev;
	for (int i = 0; i < 9; i++){
		next = series(prev);
		prev = next;
		cout << "next: " << next << "\n";
	}
	
	
	return 0;
}

