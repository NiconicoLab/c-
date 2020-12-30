#include "sub.h"
#include <iostream>

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

