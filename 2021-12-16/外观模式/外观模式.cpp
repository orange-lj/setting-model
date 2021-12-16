#include<iostream>
using namespace std;

//���ӻ�
class Tv 
{
public:
	void on() 
	{
		cout << "�򿪵���" << endl;
	}
	void off() 
	{
	
		cout << "�رյ���" << endl;
	}
};

//̨��
class Light
{
public:
	void on()
	{
		cout << "��̨��" << endl;
	}
	void off()
	{

		cout << "�ر�̨��" << endl;
	}
};

//��Ϸ��
class Ps4
{
public:
	void on()
	{
		cout << "��Ps4" << endl;
	}
	void off()
	{

		cout << "�ر�Ps4" << endl;
	}
};


//����
class Radio
{
public:
	void on()
	{
		cout << "������" << endl;
	}
	void off()
	{

		cout << "�ر�����" << endl;
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
