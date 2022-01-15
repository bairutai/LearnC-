#include <string>
#include <iostream>
class A
{
public:
	A()
	{
		m_strTest = new std::string("testA");
	}

	std::string* getText() const
	{
		return m_strTest;
	}

	~A()
	{
		delete m_strTest;
		m_strTest = nullptr;
	}

private:
	std::string* m_strTest = nullptr;
};

class B
{
public:
	B()
	{
		m_strTest = new std::string("testB");
	}
	B(const B& b)
	{
		m_strTest = new std::string;

		m_strTest->append(b.getText()->data());
	}

	~B()
	{
		delete m_strTest;
		m_strTest = nullptr;
	}

	std::string* getText() const
	{
		return m_strTest;
	}

private:
	std::string* m_strTest = nullptr;

};

A copyA()
{
	A a;
	return a;
}

B copyB()
{
	B b;
	return b;
}

int main()
{
	// ǳ���� ��copyA�����н�����һ�ο���,Ĭ����ǳ����,
	// ����֮��m_strTestָ��Ļ��Ǿֲ�����a�е�m_strTest��
	// ���ʱ���Ѿ����ͷ��ˣ����л��б���������
	//A a = copyA();
	//std::cout << *(a.getText()) << std::endl;

	// ���,�Զ����˿������캯������Ϊm_strTest�������µ��ڴ�
	// �������ݽ�����׷�ӣ��������ȷ������
	B b = copyB();
	std::cout << *(b.getText()) << std::endl;
	return 0;
}