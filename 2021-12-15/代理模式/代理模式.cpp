#include<iostream>
#include<string>
using namespace std;

class AbstractCommonInterface
{
public:
	virtual void run() = 0;
};

class MySystem:public AbstractCommonInterface
{
public:
	virtual void run() 
	{
		cout << "系统启动" << endl;
	}
};

class MySystemProxy :public AbstractCommonInterface 
{
public:
	MySystemProxy(string username,string userpass) 
	{
		this->name = username;
		this->pass = userpass;
		system = new MySystem;
	}
	bool checkUsernamePassword() 
	{
		if (name == "admin" && pass == "admin") 
		{
			return true;
		}
		return false;
	}
	virtual void run()
	{
		if (checkUsernamePassword()) 
		{
			this->system->run();
		}
		else 
		{
			cout << "用户名密码错误" << endl;
		}
	}
	~MySystemProxy() 
	{
		if (system != NULL) 
		{
			delete system;
		}
	}
public:
	MySystem* system;
	string name;
	string pass;
};

void test01() 
{
	MySystemProxy* proxy = new MySystemProxy("admin", "admin");
	proxy->run();
}

int main() 
{
	test01();
	return 0;
}