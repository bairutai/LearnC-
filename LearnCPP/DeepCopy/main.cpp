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
	// 浅拷贝 在copyA函数中进行了一次拷贝,默认是浅拷贝,
	// 拷贝之后m_strTest指向的还是局部变量a中的m_strTest，
	// 这个时候已经被释放了，所有会有崩溃的问题
	//A a = copyA();
	//std::cout << *(a.getText()) << std::endl;

	// 深拷贝,自定义了拷贝构造函数，并为m_strTest分配了新的内存
	// 并把内容进行了追加，这个是正确的做法
	B b = copyB();
	std::cout << *(b.getText()) << std::endl;
	return 0;
}