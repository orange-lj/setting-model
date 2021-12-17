#include<iostream>
#include<windows.h>
#include<queue>
using namespace std;

//Э�鴦����
class HandleClientProtocal 
{
public:
	void addMoney() 
	{
		cout << "���ӽ��" << endl;
	}
	void addDiamond()
	{
		cout << "������ʯ" << endl;
	}
	void addEquipment()
	{
		cout << "����װ��" << endl;
	}
	void addLevel()
	{
		cout << "���ӵȼ�" << endl;
	}
};

class AbstractCommand 
{
public:
	virtual void handle() = 0;//����ͻ�������Ľӿ�
};

class AddMoneyCommand :public AbstractCommand 
{
public:
	AddMoneyCommand(HandleClientProtocal* protocal)
	{
		this->pprotocal = protocal;
	}
	virtual void handle() 
	{
		this->pprotocal->addMoney();
	}
public:
	HandleClientProtocal* pprotocal;
};

class AddDiamondCommand :public AbstractCommand
{
public:
	AddDiamondCommand(HandleClientProtocal* protocal)
	{
		this->pprotocal = protocal;
	}
	virtual void handle()
	{
		this->pprotocal->addDiamond();
	}
public:
	HandleClientProtocal* pprotocal;
};

class AddEquitmentCommand :public AbstractCommand
{
public:
	AddEquitmentCommand(HandleClientProtocal* protocal)
	{
		this->pprotocal = protocal;
	}
	virtual void handle()
	{
		this->pprotocal->addEquipment();
	}
public:
	HandleClientProtocal* pprotocal;
};



class Server 
{
public:
	void addRequest(AbstractCommand* command)
	{
		mCommand.push(command);
	}
	void startHandle() 
	{
		while (!mCommand.empty()) 
		{
			Sleep(2000);
			AbstractCommand* command = mCommand.front();
			command->handle();
			mCommand.pop();
		}
	}
public:
	queue<AbstractCommand*> mCommand;
};


void test01() 
{
	HandleClientProtocal* protocal = new 	HandleClientProtocal;
	AbstractCommand* addmoney = new AddMoneyCommand(protocal);
	AbstractCommand* adddiamont = new AddDiamondCommand(protocal);
	AbstractCommand* addequitment = new AddEquitmentCommand(protocal);
	Server* se = new Server;
	se->addRequest(addmoney);
	se->addRequest(adddiamont);
	se->addRequest(addequitment);
	se->startHandle();
}
int main() 
{
	test01();
	return 0;
}