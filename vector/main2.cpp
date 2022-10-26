#include <iostream>
#include <vector>
#include <algorithm>

struct data_t {
	int num;
	std::string str;
};

int main(int argc, char* argv[])
{
	std::vector<data_t> v1;

	struct data_t data1;
	data1.num = 79;
	data1.str = "taro";
	v1.push_back(data1);

	data1.num = 57;
	data1.str = "jiro";
	v1.push_back(data1);

	data1.num = 99;
	data1.str = "shinji";
	v1.push_back(data1);

	std::vector<data_t>::iterator itr;

#if 0
	for (int i = 0; i < v1.size(); i++)
	{
		printf("%d %s\n", v1[i].num, v1[i].str.c_str());
	}
#else
	for (itr = v1.begin(); itr != v1.end(); ++itr)
	{
		printf("%d %s\n", itr->num, itr->str.c_str());
	}
#endif

	// ラムダ式でソートする．コンパイル時はc++11を指定(g++ -std=c++11)
	std::sort(v1.begin(), v1.end(), [](const data_t &a, const data_t &b){return a.num < b.num;});

	printf("=== sort ===\n");

#if 0
	for (int i = 0; i < v1.size(); i++)
	{
		printf("%d %s\n", v1[i].num, v1[i].str.c_str());
	}
#else
	for (itr = v1.begin(); itr != v1.end(); ++itr)
	{
		printf("%d %s\n", itr->num, itr->str.c_str());
	}
#endif

	return 0;
}

