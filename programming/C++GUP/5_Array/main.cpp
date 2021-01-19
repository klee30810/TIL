/*
Project : 5_Array
Creator : Kyungmin Lee
Updator : Kyungmin Lee
Reference : C++ Ground Up by Herbert Schildt
*/

#include <iostream>

#include "myheader.h"

int main(int argc, char **argv)
{
	int input, output, list4[30] = {0};
	char list[20], list2[100], list3[12][100];

	std::cout << "5. Array\n";

	std::cout << "\n5-1 enter 10 numbers:	";
	std::cin >> list;
	CheckSame(list);

	std::cout << "\n5-2 enter an array: ";
	std::cin >> list2;
	output = StringLen(list2);
	std::cout << output << "\n";

	std::cout << "\n5-3 \n";
	Matrix3D();

	std::cout << "\n5-4 : \n";
	PrintWord(list3);

	std::cout << "\n5-5 :\n";
	GetMode(list4);

	std::cout << "\n5-6 : \n";
	getString();

	std::cout << "\n5-7: \n";
	printReverse();

	std::cout << "\n5-9: \n";

	return 0;
}
