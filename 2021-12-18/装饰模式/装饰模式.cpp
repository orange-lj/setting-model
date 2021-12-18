#include<iostream>
using namespace std;


class AbstractHero
{
public:
	virtual void showStatus() = 0;
public:
	int mHp;
	int mMp;
	int mAt;
	int mDf;
};

//æﬂÃÂ”¢–€
class HeroA :public AbstractHero
{
public:
	HeroA()
	{
		mHp = 0;
		mMp = 0;
		mAt = 0;
		mDf = 0;
	}
public:
	virtual void showStatus() 
	{
		cout << "—™¡ø" << mHp << endl;
		cout << "ƒß∑®" << mMp << endl;
		cout << "π•ª˜" << mAt << endl;
		cout << "∑¿”˘" << mDf << endl;
	}
};

//”¢–€¥©…œƒ≥∏ˆ◊∞ ŒŒÔ
class AbstractEquitment :public AbstractHero 
{
public:
	AbstractEquitment(AbstractHero* hero)
	{
		this->phero = hero;
	}
	virtual void showStatus() 
	{
	
	}
public:
	AbstractHero* phero;
};

class KuangTu :public AbstractEquitment 
{
public:
	KuangTu(AbstractHero* hero) :AbstractEquitment(hero) 
	{
	
	}
	void addKuangtu() 
	{
		cout << "¥©…œøÒÕΩ" << endl;
		this->mHp = this->phero->mHp;
		this->mMp = this->phero->mMp;
		this->mAt = this->phero->mAt;
		this->mDf = this->phero->mDf+30;
	}
	virtual void showStatus()
	{
		addKuangtu();
		cout << "—™¡ø" << mHp << endl;
		cout << "ƒß∑®" << mMp << endl;
		cout << "π•ª˜" << mAt << endl;
		cout << "∑¿”˘" << mDf << endl;
	}
};

class Wuqi :public AbstractEquitment 
{
public:
	Wuqi(AbstractHero* hero):AbstractEquitment(hero)
	{
		
	}
	void addWuqi() 
	{
		cout << "¥©…œŒ‰∆˜" << endl;
		this->mAt = this->phero->mAt + 30;
		this->mHp = this->phero->mHp;
		this->mMp = this->phero->mMp;
		this->mDf = this->phero->mDf;
	}
	virtual void showStatus()
	{
		addWuqi();
		cout << "—™¡ø" << mHp << endl;
		cout << "ƒß∑®" << mMp << endl;
		cout << "π•ª˜" << mAt << endl;
		cout << "∑¿”˘" << mDf << endl;
	}
};

void test01() 
{
	AbstractHero* hero = new HeroA;
	hero->showStatus();
	cout << "-----------------" << endl;
	hero = new KuangTu(hero);
	hero->showStatus();
}

int main() 
{
	test01();
	return 0;
}