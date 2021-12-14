#include<iostream>
using namespace std;

class AbstractFruit 
{
public:
	virtual void showName() = 0;
};

class Apple :public AbstractFruit 
{
public:
	virtual void showName() 
	{
		cout << "apple" << endl;
	}

};

class Banana :public AbstractFruit
{
public:
	virtual void showName()
	{
		cout << "banana" << endl;
	}
};

class Yali :public AbstractFruit
{
public:
	virtual void showName()
	{
		cout << "yali" << endl;
	}
};

class AbstractFactory 
{
public:
	virtual AbstractFruit* CreateFruit() = 0;
};

class AppleFactory :public AbstractFactory 
{
public:
	virtual AbstractFruit* CreateFruit() 
	{
		return new Apple;
	}
};

class BananaFactory :public AbstractFactory
{
public:
	virtual AbstractFruit* CreateFruit()
	{
		return new Banana;
	}
};

class YaliFactory :public AbstractFactory
{
public:
	virtual AbstractFruit* CreateFruit()
	{
		return new Yali;
	}
};

void test01() 
{
	AbstractFactory* factory = 0;
	AbstractFruit* fruit = 0;
	factory = new AppleFactory;
	fruit = factory->CreateFruit();
	fruit->showName();
	delete fruit;
	delete factory;
	factory = new BananaFactory;
	fruit = factory->CreateFruit();
	fruit->showName();
}

int main() 
{
	test01();
	return 0;
}