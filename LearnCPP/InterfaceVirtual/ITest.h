#pragma once
class ITest
{
public:
	ITest();
	~ITest();
	virtual void add();

	virtual void init();

	virtual void test() = 0;
};

