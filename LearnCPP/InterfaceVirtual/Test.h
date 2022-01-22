#pragma once
#include "ITest.h"
class Test :
	public ITest
{
public:
	Test();
	~Test();
	virtual void test() override;
};

