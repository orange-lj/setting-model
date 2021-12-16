#include<iostream>
using namespace std;

class AbstractDrink 
{
public:
	virtual void fang() = 0;
	virtual void chong() = 0;
	virtual void jiaoban() = 0;
public:
	void make() 
	{
		fang();
		chong();
		jiaoban();
	}
};

class Coffee:public AbstractDrink
{
public:
	virtual void fang() 
	{
		cout << "放入咖啡" << endl;
	}
	virtual void chong()
	{
		cout << "放入牛奶" << endl;
	}
	virtual void jiaoban() 
	{
		cout << "筷子搅拌" << endl;
	}
};

class Tea :public AbstractDrink
{
public:
	virtual void fang()
	{
		cout << "放入茶叶" << endl;
	}
	virtual void chong()
	{
		cout << "放入开水" << endl;
	}
	virtual void jiaoban()
	{
		cout << "不用搅拌" << endl;
	}
};

void test01() 
{
	Tea* t = new Tea;
	t->make();
}

int main() 
{
	test01();
	system("pause");
	return 0;
}