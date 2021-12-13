#include<iostream>
#include<string>
#include<vector>
using namespace std;

//����֪ʶԭ��
class AbstractBuilding 
{
public:
	virtual void sale() = 0;
	virtual string getQuality() = 0;
};

class BuildingA :public AbstractBuilding 
{
public:
	BuildingA() 
	{
		mQulity = "��Ʒ��";
	}
	void sale() 
	{
		cout << "¥��A" << mQulity << "������" << endl;
	}
	virtual string getQuality() 
	{
		return mQulity;
	}
public:
	string mQulity;
};

class BuildingB :public AbstractBuilding
{
public:
	BuildingB()
	{
		mQulity = "��Ʒ��";
	}
	void sale()
	{
		cout << "¥��B" << mQulity << "������" << endl;
	}
	virtual string getQuality()
	{
		return mQulity;
	}
public:
	string mQulity;
};

void test01() 
{
	BuildingA* ba = new BuildingA;
	if (ba->mQulity == "��Ʒ��") 
	{
		ba->sale();
	}
	BuildingB* bb = new BuildingB;
	if (bb->mQulity == "��Ʒ��")
	{
		bb->sale();
	}
}

//�н���
class Mediator 
{
public:
	Mediator() 
	{
	
		AbstractBuilding* building = new BuildingA;
		vBuilding.push_back(building);
		building = new BuildingB;
		vBuilding.push_back(building);
	}
	//�����ṩ�ӿ�
	AbstractBuilding* findMyBuilding(string quality) 
	{
		for (vector<AbstractBuilding*>::iterator it = vBuilding.begin(); it != vBuilding.end(); it++)
		{
			if ((*it)->getQuality()==quality)
			{
				return *it;
			}
		}	
	}
	~Mediator() 
	{
		for (vector<AbstractBuilding*>::iterator it = vBuilding.begin(); it != vBuilding.end(); it++) 
		{
			if (*it != NULL) 
			{
				delete* it;
			}
		}
	}
public:
	vector<AbstractBuilding*> vBuilding;
};

//�ͻ���
void test02() 
{
	Mediator* mediator = new Mediator;
	AbstractBuilding* building = mediator->findMyBuilding("��Ʒ��");
	if (building!=NULL) 
	{
		building->sale();
	}
	else 
	{
		cout << "û��������" << endl;
	}
}

int main(void) 
{
	test02();
	return 0;
}