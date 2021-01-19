
#include "myheader.h"

void CheckSame(char list[20])
{
	int i, j;

	for (i = 0; i < (int)strlen(list); i++)
	{
		for (j = 1; j < (int)strlen(list) - 1; j++)
			if (list[i] == list[j])
				std::cout << "same!\n";
		break;
	}
}

int StringLen(char list2[100])
{
	int i, result;

	for (i = 0; i < (int)strlen(list2); i++)
	{
		if (list2[i] != 0)
			result++;
	}
	result = result - 1;
	return result;
}

void Matrix3D()
{
	int i = 0, j, k, num = 0, arr[30], mat[3][3][3];

	for (i = 0; i < (sizeof(arr) / sizeof(*arr)); i++)
	{
		arr[i] = i + 1;
	}

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			for (k = 0; k < 3; k++)
			{
				mat[i][j][k] = arr[num + k];
				std::cout << mat[i][j][k] << " ";
			}
			num += 3;
			std::cout << "\n";
		}
	}
}

void PrintWord(char list3[12][100])
{
	int i, choice;

	for (i = 0; i < 10; i++)
	{
		std::cout << "Enter the word: ";
		std::cin >> list3[i];
	}

	std::cout << "Enter the number: ";
	std::cin >> choice;

	for (i = 0; i < 90; i++)
		std::cout << list3[choice - 1][i];
}

void GetMode(int list[30])
{
	int i, j, freq[30] = {0}, mode = 0;

	for (i = 0; i < 20; i++)
	{
		std::cout << "Enter 1 digit number: ";
		std::cin >> list[i];
	}

	for (i = 0; i < 20; i++)
	{
		for (j = 0; j < 20; j++)
		{
			if (list[i] == list[j])
				freq[i]++;
		}
	}

	// mode = list[0];
	for (i = 0; i < 20; i++)
	{
		for (j = i; j < 20; j++)
		{
			if (freq[i] > freq[j])
				mode = list[i];
		}
	}

	std::cout << "mode: " << mode;
}

void getString()
{
	int length = 0;
	char list[100] = {0};

	std::cout << "Input string: ";
	std::cin >> list;

	for (int i = 0; i < (sizeof(list) / sizeof(list[0])); i++)
	{
		if (list[i] != 0)
			length++;
	}

	for (int i = length; i < (sizeof(list) / sizeof(list[0])); i++)
	{
		list[i] = '1';
	}

	for (int i = 0; i < (sizeof(list) / sizeof(list[0])); i++)
	{
		printf("%c", list[i]);
	}

	std::cout << std::endl;
}

void printReverse()
{
	int length = 0;
	char list[100] = {0};

	std::cout << "Input string: ";
	std::cin >> list;

	for (int i = 0; i < (sizeof(list) / sizeof(list[0])); i++)
	{
		if (list[i] != '\0')
			length++;
	}

	for (int i = 0; i < (length / 2); i++)
	{
		std::cout << list[i] << std::fflush;
		std::cout << list[length - i - 1] << std::fflush;
	}
}
