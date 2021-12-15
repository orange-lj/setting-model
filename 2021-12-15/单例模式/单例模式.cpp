#include<iostream>
using namespace std;


//懒汉式单例
class Singleton_lazy 
{
private:
	Singleton_lazy() {}
public:
	static Singleton_lazy* getInstance() 
	{
		if (lazy == NULL) 
		{
			lazy = new Singleton_lazy;
		}
		return lazy;
	}
private:
	static Singleton_lazy* lazy;
};

Singleton_lazy* Singleton_lazy::lazy = NULL;

//饿汉式单例
class Singleton_hungry 
{
private:
	Singleton_hungry() {}
public:
	static Singleton_hungry* getInstance() 
	{
		return hungry;
	}
private:
	static Singleton_hungry* hungry;
};
Singleton_hungry* Singleton_hungry::hungry = new Singleton_hungry;


void test01() 
{
	Singleton_lazy* p1 = Singleton_lazy::getInstance();
	Singleton_lazy* p2 = Singleton_lazy::getInstance();
	if (p1 == p2) 
	{
		cout << "俩个指针指向同一个内存" << endl;
	}
	else 
	{
		cout << "不是" << endl;
	}
	Singleton_hungry* p3 = Singleton_hungry::getInstance();
	Singleton_hungry* p4 = Singleton_hungry::getInstance();
	if (p3 == p4) 
	{
		cout << "俩个指针指向同一个内存" << endl;
	}
	else
	{
		cout << "不是" << endl;
	}
}

int main() 
{
	test01();
	return 0;
}