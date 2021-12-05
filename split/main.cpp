#if 0 // 下記のURL先のプログラムを参照し改変しています．
https://maku77.github.io/cpp/string/split.html
#endif

#include <iostream>
#include <vector>
#include <string>

std::vector<std::string> split(const std::string& src, const char* delim = ",")
{
	std::vector<std::string> vec;
	std::string::size_type len = src.length();
	printf("split str = %s : len = %ld\n", src.c_str(), len);
	
	for (std::string::size_type i = 0, n; i < len; i = n + 1)
	{
		n = src.find_first_of(delim, i);
		if (n == std::string::npos)
		{
			n = len;
		}
		vec.push_back(src.substr(i, n - i));
	}
	return vec;
}

int main(int argc, char **argv)
{
	// 固定長の文字列入力
	do {
		printf("=== fix string === \n");
		std::string s = "0x01,0xAA,0xFF,FE";
		std::vector<std::string> arr = split(s);
		for (unsigned long i = 0; i < arr.size(); i++)
		{
			long num = strtol(arr[i].c_str(), NULL, 16); // 16進数変換
			std::cout << arr[i] << " -> " << num << std::endl;
		}
	}while(0);

	// コマンドライン引数入力
	if(argc == 2)
	{
		printf("=== input command line === \n");
		std::string argvStr = argv[1];
		std::vector<std::string> argArr = split(argvStr);
		
		for (unsigned long i = 0; i < argArr.size(); ++i)
		{
			long num = strtol(argArr[i].c_str(), NULL, 16); // 16進数変換
			std::cout << argArr[i] << " -> " << num << std::endl;
		}
	}
	
#if 1 // おまけ(std::string型は.c_str()でchar*型に変換する必要がある)
	printf("=== std::string type test === \n");
	std::string s1 = "ABC";
	std::string s2 = "def";
	std::string s3 = s1 + s2;
	printf("%s %s %s\n", s1.c_str(), s2.c_str(), s3.c_str());
#endif

	return 0;
}
