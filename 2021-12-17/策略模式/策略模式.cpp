#include<iostream>
using namespace std;


//抽象武器
class Weapon 
{
public:
	virtual  void useWeapon() = 0;
};


class Knife :public Weapon 
{
public:
	virtual  void useWeapon() 
	{
		cout << "使用匕首" << endl;
	}
};

class AK47 :public Weapon
{
public:
	virtual  void useWeapon()
	{
		cout << "使用AK" << endl;
	}
};

class Character 
{
public:
	void setWeapon(Weapon* weapon) 
	{
		this->we = weapon;
	}
	void ThrowWeapon() 
	{
		this->we->useWeapon();
	}
public:
	Weapon* we;
};

void test01()
{
	Character* ch = new Character;
	Weapon* kni = new Knife;
	Weapon* ak = new AK47;
	ch->setWeapon(kni);
	ch->ThrowWeapon();
}

int main() 
{
	test01();
	return 0;
}