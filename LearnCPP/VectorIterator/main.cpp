#include <iostream>
#include <vector>
int main()
{
	std::vector<int> vectorA;
	vectorA.push_back(0);
	vectorA.push_back(1);
	vectorA.push_back(2);
	vectorA.push_back(3);

	// vector的特性是在追加元素的时候会重新分配内存
	// 下列it在vectorA追加一个元素之后失效了，所以会崩溃
	std::vector<int>::iterator it = vectorA.begin();
	vectorA.push_back(4);
	for (it; it != vectorA.end(); ++it)
	{
		std::cout << *(it) << std::endl;
	}
	return 0;
}