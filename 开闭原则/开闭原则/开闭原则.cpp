#include<iostream>
using namespace std;

//����ԭ�� ����չ���Ŷ��޸Ĺ�ϵ
//���ӹ�����ͨ�����Ӵ���ʵ�ֵ�

//дһ��������
class AbstractCaculator 
{
public:
	virtual int getResult() = 0;
	virtual void setOperatorNumber(int a,int b) = 0;

};

//�ӷ�������
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

//����������
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

//�ͷ�������
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