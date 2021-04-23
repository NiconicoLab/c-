#include <iostream>

namespace my_namespace
{
    void print(void);
    void print_wrapper(void)
	{
        print(); // namespace空間内は修飾なしで呼び出し可能
    }
}

void my_namespace::print(void)
{
	std::cout << "my func" << std::endl;
	return;
}

namespace my_namespace2
{
    void print(void)
	{
		std::cout << "other namespace" << std::endl;
	}
    void print_wrapper(void)
	{
        my_namespace::print(); // 別のnamespace空間内の関数を呼び出す
    }
}


namespace my = my_namespace; // namespace名を別名でつける

// using namespace std; // 全部使えることになるため，特定の関数へ絞る場合は下記を使用する
using std::cout;
using std::endl;

int main(int argc, char **argv)
{
	my_namespace::print_wrapper();
	my_namespace2::print();
	my_namespace2::print_wrapper();
	my::print();

	cout << "test" << endl;

	return 0;
}
