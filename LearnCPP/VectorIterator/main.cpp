#include <iostream>
#include <vector>
int main()
{
	std::vector<int> vectorA;
	vectorA.push_back(0);
	vectorA.push_back(1);
	vectorA.push_back(2);
	vectorA.push_back(3);

	// vector����������׷��Ԫ�ص�ʱ������·����ڴ�
	// ����it��vectorA׷��һ��Ԫ��֮��ʧЧ�ˣ����Ի����
	std::vector<int>::iterator it = vectorA.begin();
	vectorA.push_back(4);
	for (it; it != vectorA.end(); ++it)
	{
		std::cout << *(it) << std::endl;
	}
	return 0;
}