#include<iostream>
using namespace std;

//开闭原则 对扩展开放对修改关系
//增加功能是通过增加代码实现的

//写一个抽象类
class AbstractCaculator 
{
public:
	virtual int getResult() = 0;
	virtual void setOperatorNumber(int a,int b) = 0;

};

//加法计算其
class PlusCaculator :public AbstractCaculator 
{
public:
	void setOperatorNumber(int a, int b) 
	{
		this->mA = a;
		this->mB = b;
	}
	int getResult() 
	{
		return mA + mB;
	}
public:
	int mA;
	int mB;
};

//减法计算其
class MinuteCaculator :public AbstractCaculator
{
public:
	void setOperatorNumber(int a, int b)
	{
		this->mA = a;
		this->mB = b;
	}
	int getResult()
	{
		return mA - mB;
	}
public:
	int mA;
	int mB;
};

//惩法计算其
class MultiplyCaculator :public AbstractCaculator
{
public:
	void setOperatorNumber(int a, int b)
	{
		this->mA = a;
		this->mB = b;
	}
	int getResult()
	{
		return mA * mB;
	}
public:
	int mA;
	int mB;
};

void test01() 
{
	AbstractCaculator* caculator = new PlusCaculator;
	//caculator
	caculator->setOperatorNumber(10, 20);
	cout << caculator->getResult() << endl;
	delete caculator;
	caculator = new MultiplyCaculator;
	caculator->setOperatorNumber(10, 20);
	cout<<caculator->getResult() << endl;
}

int main(void) 
{
	test01();
	return 0;
}