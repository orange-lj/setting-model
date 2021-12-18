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
		cout << "Ӣ��A���ڴ�boss" << endl;
	}
	virtual void update()
	{
		cout << "Ӣ��Aֹͣ��boss" << endl;
	}
};

class HeroB :public AbstractHero
{
public:
	HeroB()
	{
		cout << "Ӣ��B���ڴ�boss" << endl;
	}
	virtual void update()
	{
		cout << "Ӣ��Bֹͣ��boss" << endl;
	}
};

class HeroC :public AbstractHero
{
public:
	HeroC()
	{
		cout << "Ӣ��C���ڴ�boss" << endl;
	}
	virtual void update()
	{
		cout << "Ӣ��Cֹͣ��boss" << endl;
	}
};

class HeroD :public AbstractHero
{
public:
	HeroD()
	{
		cout << "Ӣ��D���ڴ�boss" << endl;
	}
	virtual void update()
	{
		cout << "Ӣ��Dֹͣ��boss" << endl;
	}
};
class HeroE :public AbstractHero
{
public:
	HeroE()
	{
		cout << "Ӣ��E���ڴ�boss" << endl;
	}
	virtual void update()
	{
		cout << "Ӣ��Eֹͣ��boss" << endl;
	}
};

class AbstratBoss
{
public:
	//����Ӣ��
	virtual void addHero(AbstractHero* hero) = 0;
	//ɾ��Ӣ��
	virtual void deleteHero(AbstractHero* hero) = 0;
	//֪ͨӢ��
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
	//�����۲���
	HeroA* heroa = new HeroA;
	HeroB* herob = new HeroB;
	HeroC* heroc = new HeroC;
	HeroD* herod = new HeroD;
	HeroE* heroe = new HeroE;
	//�����۲���Ŀ��
	BossA* bossa = new BossA;
	bossa->addHero(heroa);
	bossa->addHero(herob);
	bossa->addHero(heroc);
	bossa->addHero(herod);
	bossa->addHero(heroe);
	cout << "heroc��æ" << endl;
	bossa->deleteHero(heroc);
	cout << "boss���ˣ�֪ͨ����Ӣ��ֹͣ����" << endl;
	bossa->notify();
}

int main() 
{
	test01();
	return 0;
}