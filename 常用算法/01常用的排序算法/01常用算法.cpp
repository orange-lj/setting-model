#include<iostream>
#include<vector>
#include<list>//不支持随机访问
#include<time.h>
#include<algorithm>
using namespace std;

struct MyPrint01
{
	void operator()(int val)
	{
		cout << val << " ";
	}
};

struct MyCompare 
{
	bool operator()(int v1, int v2) 
	{
		return v1 > v2;
	}
};

//merge算法
void test01() 
{
	vector<int> v1;
	vector<int> v2;
	list<int> l3;
	srand((unsigned int) time(NULL));
	for (int i = 0; i < 10; i++) 
	{
		v1.push_back(rand() % 10);
	}
	for (int i = 0; i < 10; i++)
	{
		//v2.push_back(rand() % 10);
		l3.push_back(rand() % 10);
	}
	sort(v1.begin(), v1.end(),MyCompare());
	l3.sort(MyCompare());
	//for_each(l3.begin(), l3.end(), MyPrint01());
	//sort(v2.begin(), v2.end(), MyCompare());
	vector<int> v3;
	//v3.resize(v1.size() + v2.size());//开辟空间
	v3.resize(v1.size() + l3.size());//开辟空间
	//默认从小到大
	//merge(v1.begin(), v1.end(), v2.begin(), v2.end(),v3.begin(), MyCompare());
	merge(v1.begin(), v1.end(), l3.begin(), l3.end(),v3.begin(), MyCompare());
	for_each(v3.begin(), v3.end(), MyPrint01());
}

//random_shuffle
void test02() 
{
	vector<int> v;
	for (int i = 0; i < 9; i++) 
	{
		v.push_back(i);
	}
	random_shuffle(v.begin(), v.end());
	for_each(v.begin(), v.end(), MyPrint01());
}

//reverse
void test03() 
{
	vector<int> v;
	for (int i = 0; i < 9; i++) 
	{
		v.push_back(i);
	}
	reverse(v.begin(), v.end());
	for_each(v.begin(), v.end(), MyPrint01());
}

int main() 
{
	//test03();
//	test02();
	test01();
	return 0;
}

