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
		cout << "���뿧��" << endl;
	}
	virtual void chong()
	{
		cout << "����ţ��" << endl;
	}
	virtual void jiaoban() 
	{
		cout << "���ӽ���" << endl;
	}
};

class Tea :public AbstractDrink
{
public:
	virtual void fang()
	{
		cout << "�����Ҷ" << endl;
	}
	virtual void chong()
	{
		cout << "���뿪ˮ" << endl;
	}
	virtual void jiaoban()
	{
		cout << "���ý���" << endl;
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