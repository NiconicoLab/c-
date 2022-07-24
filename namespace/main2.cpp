#include <iostream>

namespace my_namespace
{
	class my_class
	{
	public:
		void print(void);		
	};
}

void my_namespace::my_class::print(void)
{
	std::cout << "my func" << std::endl;
	return;
}

int main(int argc, char **argv)
{
	my_namespace::my_class c;
	c.print();

	// new演算子を使うことでインスタンス化を自身のタイミングで決めることができる
	class my_namespace::my_class *pc;
	pc = new my_namespace::my_class;
	pc->print();
	delete pc;
	
	return 0;
}
