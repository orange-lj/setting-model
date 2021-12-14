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
		cout << "我是苹果" << endl;
	}
};

class Banana :public AbstractFruit 
{
public:
	virtual void showName() 
	{
		cout << "我是香蕉" << endl;
	}
};

class Yali :public AbstractFruit
{
public:
	virtual void showName()
	{
		cout << "我是鸭梨" << endl;
	}
};

//水果工厂
class FruitFactory 
{
public:
	  AbstractFruit* CreateFruit(string flag) 
	{
		if (flag == "apple") 
		{
			return new Apple;
		}
		else if (flag == "banana") 
		{
			return new Banana;
		}
		else if (flag == "yali")
		{
			return new Yali;
		}
		else 
		{
			return NULL;
		}
	}
};



void test01() 
{
	FruitFactory* factory = new FruitFactory;
	AbstractFruit* fruit = factory->CreateFruit("apple");
	fruit->showName();
	delete fruit;
	fruit = factory->CreateFruit("banana");
	fruit->showName();
}
 
int main() 
{
	test01();
	return 0;
}