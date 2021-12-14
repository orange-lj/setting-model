#include<iostream>
#include<string>
#include<vector>
using namespace std;

//最少知识原则
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
		mQulity = "高品质";
	}
	void sale() 
	{
		cout << "楼盘A" << mQulity << "被售卖" << endl;
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
		mQulity = "低品质";
	}
	void sale()
	{
		cout << "楼盘B" << mQulity << "被售卖" << endl;
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
	if (ba->mQulity == "低品质") 
	{
		ba->sale();
	}
	BuildingB* bb = new BuildingB;
	if (bb->mQulity == "低品质")
	{
		bb->sale();
	}
}

//中介类
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
	//对外提供接口
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

//客户端
void test02() 
{
	Mediator* mediator = new Mediator;
	AbstractBuilding* building = mediator->findMyBuilding("高品质");
	if (building!=NULL) 
	{
		building->sale();
	}
	else 
	{
		cout << "没有条件的" << endl;
	}
}

int main(void) 
{
	test02();
	return 0;
}