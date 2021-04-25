#include <iostream>

// 呼び出す関数を探すため，virtual関数は非virtualの関数と比較して実行時間がかかる
// virtualではない関数では基底クラスのメンバー関数が呼ばれ，
// virtualな関数では派生クラスのメンバー関数が呼ばれる

// 基底クラス
class ClassA {
public:
	virtual ~ClassA() { }
	virtual void func1();
	void func2();
};

// 継承クラス
class ClassB : public ClassA {
public:
	virtual void func1();
	void func2();
};

void ClassA::func1(void)
{
	std::cout << "ClassA func1" << std::endl;
}

void ClassA::func2(void)
{
	std::cout << "ClassA func2" << std::endl;
}

void ClassB::func1(void)
{
	std::cout << "ClassB func1" << std::endl;
}

void ClassB::func2(void)
{
	std::cout << "ClassB func2" << std::endl;
}

int main(int argc, char* argv[])
{
	class ClassB b; // 継承クラス
	b.func1();
	b.func2();

	class ClassA* p = &b; // 派生クラスインスタンスへのポインタ値を基底クラスへのポインタ変数で保持
	p->func1();
	p->func2(); // 仮想関数(virtualを付けていない)ため，基底クラスの関数が呼ばれる

	return 0;
}
