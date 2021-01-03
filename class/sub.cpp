#include "sub.h"
#include <iostream>

Class1::Class1() : number1(10), number2(23)
{
	std::cout << "Class::Class1()" << "\n"
		  << "number1=" << number1 << "\n"
		  << "number2=" << number2 << std::endl;
}

Class1::~Class1()
{
	number1 = 0;
	number2 = 0;
	std::cout << "Class::~Class1()" << "\n"
		  << "number1=" << number1 << "\n"
		  << "number2=" << number2 << std::endl;
}

void Class1::init_table(void)
{
	for(int i = 0; i < NUM; i++)
	{
		for(int j = 0; j < NUM; j++)
		{
			table[i][j] = this->add(i ,j);
		}
	}
}

void Class1::print_table(void)
{
	for(int i = 0; i < NUM; i++)
	{
		for(int j = 0; j < NUM; j++)
		{
			std::cout << "table[" << i << "][" << j << "]=" << table[i][j] << std::endl;
		}
	}
}

int Class1::add(int a, int b)
{
	return (a+b);
}

