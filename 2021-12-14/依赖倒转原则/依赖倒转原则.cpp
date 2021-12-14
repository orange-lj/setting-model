#include<iostream>
using namespace std;

class BankWorker 
{
public:
	void saveService() 
	{
		cout << "存款业务" << endl;
	}
	void payService() 
	{
		cout << "支付业务" << endl;
	}
	void tranceService()
	{
		cout << "转账业务" << endl;
	}
};




//业务模块
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

//专门办理存款
class SaveBankWorker :public AbstractWorker 
{
public:
	virtual void doBusiness() 
	{
		cout << "办理存款业务" << endl;
	}
};

//专门办理支付
class PayBankWorker :public AbstractWorker 
{
public:
	virtual void doBusiness()
	{
		cout << "办理支付业务" << endl;
	}

};
//专门办理转账
class TraceBankWorker :public AbstractWorker
{
public:
	virtual void doBusiness()
	{
		cout << "办理转正业务" << endl;
	}
};

//中层业务
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