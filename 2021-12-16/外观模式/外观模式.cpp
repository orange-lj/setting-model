#include<iostream>
using namespace std;

//电视机
class Tv 
{
public:
	void on() 
	{
		cout << "打开电视" << endl;
	}
	void off() 
	{
	
		cout << "关闭电视" << endl;
	}
};

//台灯
class Light
{
public:
	void on()
	{
		cout << "打开台灯" << endl;
	}
	void off()
	{

		cout << "关闭台灯" << endl;
	}
};

//游戏机
class Ps4
{
public:
	void on()
	{
		cout << "打开Ps4" << endl;
	}
	void off()
	{

		cout << "关闭Ps4" << endl;
	}
};


//音响
class Radio
{
public:
	void on()
	{
		cout << "打开音响" << endl;
	}
	void off()
	{

		cout << "关闭音响" << endl;
	}
};

class KTVmode 
{
public:
	KTVmode()
	{
		ptv = new Tv;
		plight = new Light;
		pradio = new Radio;
		pps = new Ps4;
	}
	~KTVmode()
	{
		delete ptv;
		delete plight;
		delete pradio;
		delete pps;
	}
public:
	void open() 
	{
		ptv->off();
		plight->off();
		pradio->on();
		pps->on();
	}
public:
	Tv* ptv;
	Light* plight;
	Radio* pradio;
	Ps4* pps;
};

void test01() 
{
	KTVmode* ktv = new KTVmode;
	ktv->open();
}

int main() 
{
	test01();
	return 0;
}
