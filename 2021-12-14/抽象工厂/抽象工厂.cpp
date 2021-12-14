#include<iostream>
using namespace std;

class AbstractApple 
{
public:
	virtual void showName() = 0;
};

class ChinaApple :public AbstractApple
{
public:
	virtual void showName() 
	{
		cout << "中国苹果" << endl;
	}
};

class USAApple :public AbstractApple
{
public:
	virtual void showName()
	{
		cout << "美国苹果" << endl;
	}
};

class JapanApple :public AbstractApple
{
public:
	virtual void showName()
	{
		cout << "日本苹果" << endl;
	}
};


class AbstractBanana
{
public:
	virtual void showName() = 0;
};

class ChinaBanana :public AbstractBanana
{
public:
	virtual void showName()
	{
		cout << "中国香蕉" << endl;
	}
};

class USABanana :public AbstractBanana
{
public:
	virtual void showName()
	{
		cout << "美国香蕉" << endl;
	}
};

class JapanBanana :public AbstractBanana
{
public:
	virtual void showName()
	{
		cout << "日本香蕉" << endl;
	}
};

class AbstratFactory 
{
public:
	virtual AbstractApple* CreateApple() = 0;
	virtual AbstractBanana* CreateBanana() = 0;
};

class ChinaFactory :public AbstratFactory 
{
public:
	virtual AbstractApple* CreateApple() 
	{
		return new ChinaApple;
	}
	virtual AbstractBanana* CreateBanana() 
	{
		return new ChinaBanana;
	}
};

class USAFactory :public AbstratFactory
{
public:
	virtual AbstractApple* CreateApple()
	{
		return new USAApple;
	}
	virtual AbstractBanana* CreateBanana()
	{
		return new USABanana;
	}
};

class JapanFactory :public AbstratFactory
{
public:
	virtual AbstractApple* CreateApple()
	{
		return new JapanApple;
	}
	virtual AbstractBanana* CreateBanana()
	{
		return new JapanBanana;
	}
};

void test01() 
{
	AbstratFactory* factory = NULL;
	AbstractApple* apple = NULL;
	AbstractBanana* banana = NULL;
	factory = new ChinaFactory;
	apple = factory->CreateApple();
	banana = factory->CreateBanana();
	apple->showName();
	banana->showName();
	delete banana;
	delete apple;
	delete factory;
}

int main() 
{
	test01();
	return 0;
}