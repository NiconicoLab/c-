#include <iostream>
#include <string>
#include <map>

std::map<std::string, int> table = {
	{ "AAA", 12 },
	{ "BBB", 23 },
	{ "CCC", 34 },
};

double func1(int a, int b) { return (a + b); }
double func2(int a, int b) { return (a - b); }

std::map<std::string , double(*)(int, int)> funcTable = {
	{ "+", func1 },
	{ "-", func2 },
};

int main(int argc, char* argv[])
{
	std::string str = "AAA";
	// キー要素が存在している場合
	if(table.find(str) != table.end()) {
		std::cout << table[str] << std::endl;
	}
	else {
		std::cout << "not found value" << std::endl;
	}

	std::string str2 = "+";
	// キー要素が存在している場合
	if (funcTable.find(str2) != funcTable.end()) {
		std::cout << funcTable[str2](1, 2) << std::endl;
	}
	else {
		std::cout << "not found function" << std::endl;
	}
	
	return 0;
}
