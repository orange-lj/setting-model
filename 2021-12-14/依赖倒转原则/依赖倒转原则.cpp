#include<iostream>
using namespace std;

class BankWorker 
{
public:
	void saveService() 
	{
		cout << "���ҵ��" << endl;
	}
	void payService() 
	{
		cout << "֧��ҵ��" << endl;
	}
	void tranceService()
	{
		cout << "ת��ҵ��" << endl;
	}
};




//ҵ��ģ��
void test01() 
{
	BankWorker* worker = new BankWorker;
	doSaveBussiness(worker);
	doPayBussiness(worker);
	doTranceBussiness(worker);
}

//
class AbstractWorker 
{
public:
	virtual void doBusiness() = 0;
};

//ר�Ű�����
class SaveBankWorker :public AbstractWorker 
{
public:
	virtual void doBusiness() 
	{
		cout << "������ҵ��" << endl;
	}
};

//ר�Ű���֧��
class PayBankWorker :public AbstractWorker 
{
public:
	virtual void doBusiness()
	{
		cout << "����֧��ҵ��" << endl;
	}

};
//ר�Ű���ת��
class TraceBankWorker :public AbstractWorker
{
public:
	virtual void doBusiness()
	{
		cout << "����ת��ҵ��" << endl;
	}
};

//�в�ҵ��
void doNewBusiness(AbstractWorker* worker)
{
	worker->doBusiness();
}

void test02() 
{
	AbstractWorker* transfer = new TraceBankWorker;
	doNewBusiness(transfer);
}

int main() 
{
	return 0;
}