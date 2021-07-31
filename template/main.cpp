#include <iostream>
#include <string>
 
using namespace std;
 
//  テンプレート関数
template <typename T> T my_add(T x, T y) {
	return x + y;
}

template <class T> void my_print(T x) {
	cout << x << endl;
}

// テンプレートクラス
template <typename T> class myCalc {
private:
	T m_n1;
	T m_n2;
public:
	inline void set(const T n1, const T n2) { m_n1 = n1; m_n2 = n2; };
	inline T add() const{ return (m_n1 + m_n2); }
};

int main(int argc, char *argv[])
{
	try
	{
		// コンパイル時に各々の型に応じた関数が作成される
		cout << my_add<int>(6, 8) << endl;
		cout << my_add<string>("ASD", "FGH") << endl;
		cout << my_add(9, 1) << endl; // 両方ともintの場合は型指定省略可
#if 0 // この中のコードはコンパイルエラーとなる
		// cout << add("asd", "fgh") << endl; //  stringの場合は型指定が必要で省略不可
		// cout << add(479,1.2) << endl; //  型が不一致した場合は使用不可
#endif

		my_print("test");

		myCalc<int> i1; // int型でテンプレートが作成される
		myCalc<string> i2; // string型でテンプレートが作成される
		i1.set(1, 2);
		i2.set("ASD", "FGH");
		cout << i1.add() << endl << i2.add() << endl;

	}
	catch(...)
	{
		cerr << "exception" << endl;
	}
	return 0;
}
