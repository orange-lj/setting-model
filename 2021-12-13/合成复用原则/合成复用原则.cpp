#include<iostream>
using namespace std;


class AbstractCar 
{
public:
	virtual void run() = 0;
};

class DaZhong:public AbstractCar 
{
public:
	virtual void run() 
	{
		cout << "大众车启动" << endl;
	}

};


class TuoLaJi :public AbstractCar 
{
public:
	virtual void run()
	{
		cout << "拖拉机启动" << endl;
	}
};

//可以使用组合
class Person 
{
public:
	void setCar(AbstractCar* car)
	{
		this->car = car;
	}
	void Doufeng() 
	{
		this->car->run();
	}
	~Person() 
	{
		if (this->car != NULL) 
		{
			delete this->car;
		}
	}
public:
	AbstractCar* car;
};

void test01() 
{
	Person* p=new Person;
	p->setCar(new DaZhong);
	p->Doufeng();
	delete p;
}

int main(void) 
{
	test01();
	return 0;
}