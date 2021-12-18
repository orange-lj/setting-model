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

//����Ӣ��
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
		cout << "Ѫ��" << mHp << endl;
		cout << "ħ��" << mMp << endl;
		cout << "����" << mAt << endl;
		cout << "����" << mDf << endl;
	}
};

//Ӣ�۴���ĳ��װ����
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
		cout << "���Ͽ�ͽ" << endl;
		this->mHp = this->phero->mHp;
		this->mMp = this->phero->mMp;
		this->mAt = this->phero->mAt;
		this->mDf = this->phero->mDf+30;
	}
	virtual void showStatus()
	{
		addKuangtu();
		cout << "Ѫ��" << mHp << endl;
		cout << "ħ��" << mMp << endl;
		cout << "����" << mAt << endl;
		cout << "����" << mDf << endl;
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
		cout << "��������" << endl;
		this->mAt = this->phero->mAt + 30;
		this->mHp = this->phero->mHp;
		this->mMp = this->phero->mMp;
		this->mDf = this->phero->mDf;
	}
	virtual void showStatus()
	{
		addWuqi();
		cout << "Ѫ��" << mHp << endl;
		cout << "ħ��" << mMp << endl;
		cout << "����" << mAt << endl;
		cout << "����" << mDf << endl;
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