#include<iostream>
#include<vector>
#include<time.h>
#include<algorithm>
using namespace std;

struct MyPrint
{
	void operator()(int val)
	{
		cout << val << " ";
	}
};
//copy swap
void test01() 
{
	vector<int> v1; 
	srand((unsigned int) time(NULL));
	for (int i = 0; i < 10; i++) 
	{
		v1.push_back(rand() % 10);
	}
	vector<int> v2;
	v2.resize(v1.size());
	copy(v1.begin(),v1.end(),v2.begin());
	for_each(v2.begin(), v2.end(), MyPrint());
	//swap
	vector<int> v3;
	for (int i = 0; i < 10; i++) 
	{
		v3.push_back(rand() % 10);
	}
	cout << "----------------------" << endl;
	swap(v3, v2);
	for_each(v2.begin(), v2.end(), MyPrint());

}

//replace replace_if
void test02() 
{
	vector<int> v1;
	for (int i = 0; i < 10; i++) 
	{
		v1.push_back(i);
	}
	for_each(v1.begin(), v1.end(), MyPrint());
	replace(v1.begin(), v1.end(), 5, 100);
	for_each(v1.begin(), v1.end(), MyPrint());
}

int main() 
{
	//test01();
	test02();
	return 0;
}
