#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//����������Ѿ�д����
struct MyPrint 
{
	void operator()(int v1,int v2) 
	{
		cout << v1 + v2 << endl;
	}
};

//����Ŀ��ӿ� ��Ҫ�����ʲô����
class Target 
{
public:
	virtual void operator()(int v = 0) = 0;
};

//д������
class Adapter :public Target 
{
public:
	Adapter(int param) 
	{
		this->param = param;
	}
	virtual void operator()(int v) 
	{
		print(v, param);
	}
public:
	MyPrint print;
	int param;
};

Adapter MyBind2nd(int v) 
{
	return Adapter(v);
}

int main(void) 
{
	vector<int> v;
	for (int i = 0; i < 10; i++) 
	{
		v.push_back(i);
	}
	for_each(v.begin(), v.end(), MyBind2nd(10));
	return 0;
}