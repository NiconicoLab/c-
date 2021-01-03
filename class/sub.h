#ifndef SUB_H
#define SUB_H

#include <iostream>

#define NUM 5

class Class1
{
protected:
	class MembershipFunc
	{
	public:
		double tn;
		double t0;
		double tp;
	};

public:
	Class1();
	~Class1();

	void init_table(void);
	void print_table(void);
	
private:
	int add(int a, int b);
	int table[NUM][NUM];
	int number1;
	int number2;
};

#endif

