#include <iostream>
#include <vector>


int main(int argc, char* argv[])
{
	std::vector<int> v{12, 23, 34, 45};

	std::vector<int>::iterator itr = v.begin();
	std::cout << *itr << std::endl;
	
	++itr; // 次の要素へポインタをインクリメント
	std::cout << *itr << std::endl; // 2番目の要素を表示

	*itr = 89; // 2番目の要素値を変更
	std::cout << *itr << std::endl; // 2番目の要素を表示
	
	return 0;
}
