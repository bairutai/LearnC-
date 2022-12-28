#include <iostream>
using namespace std;
void throwExpt()
{
	throw 1;
}

void noBlockThrow()
{
	throwExpt();
}

void blockThrow() noexcept
{
	throwExpt();
}

int main()
{
	try
	{
		throwExpt();
	}
	catch (...)
	{
		cout << "Found throw" << endl;
	}
	try
	{
		noBlockThrow();
	}
	catch (...)
	{
		cout << "throw is not block" << endl;
	}
	try
	{
		blockThrow();
	}
	catch (...)
	{
		cout << "throw is block" << endl;
	} 
	return 0;
}