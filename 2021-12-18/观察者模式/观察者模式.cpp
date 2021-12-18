#include<iostream>
#include<list>
using namespace std;

class AbstractHero
{
public:
	virtual void update() = 0;
};

class HeroA :public AbstractHero
{
public:
	HeroA()
	{
		cout << "英雄A正在打boss" << endl;
	}
	virtual void update()
	{
		cout << "英雄A停止打boss" << endl;
	}
};

class HeroB :public AbstractHero
{
public:
	HeroB()
	{
		cout << "英雄B正在打boss" << endl;
	}
	virtual void update()
	{
		cout << "英雄B停止打boss" << endl;
	}
};

class HeroC :public AbstractHero
{
public:
	HeroC()
	{
		cout << "英雄C正在打boss" << endl;
	}
	virtual void update()
	{
		cout << "英雄C停止打boss" << endl;
	}
};

class HeroD :public AbstractHero
{
public:
	HeroD()
	{
		cout << "英雄D正在打boss" << endl;
	}
	virtual void update()
	{
		cout << "英雄D停止打boss" << endl;
	}
};
class HeroE :public AbstractHero
{
public:
	HeroE()
	{
		cout << "英雄E正在打boss" << endl;
	}
	virtual void update()
	{
		cout << "英雄E停止打boss" << endl;
	}
};

class AbstratBoss
{
public:
	//增加英雄
	virtual void addHero(AbstractHero* hero) = 0;
	//删除英雄
	virtual void deleteHero(AbstractHero* hero) = 0;
	//通知英雄
	virtual void notify() = 0;
};

class BossA :public AbstratBoss
{
public:
	virtual void addHero(AbstractHero* hero)
	{
		pHeraList.push_back(hero);
	}
	virtual void deleteHero(AbstractHero* hero)
	{
		pHeraList.remove(hero);
	}
	virtual void notify()
	{
		for (list<AbstractHero*>::iterator it = pHeraList.begin(); it != pHeraList.end(); it++)
		{
			(*it)->update();
		}
	}
public:
	list<AbstractHero*> pHeraList;
};

void test01()
{
	//创建观察者
	HeroA* heroa = new HeroA;
	HeroB* herob = new HeroB;
	HeroC* heroc = new HeroC;
	HeroD* herod = new HeroD;
	HeroE* heroe = new HeroE;
	//创建观察者目标
	BossA* bossa = new BossA;
	bossa->addHero(heroa);
	bossa->addHero(herob);
	bossa->addHero(heroc);
	bossa->addHero(herod);
	bossa->addHero(heroe);
	cout << "heroc成忙" << endl;
	bossa->deleteHero(heroc);
	cout << "boss死了，通知其他英雄停止攻击" << endl;
	bossa->notify();
}

int main() 
{
	test01();
	return 0;
}