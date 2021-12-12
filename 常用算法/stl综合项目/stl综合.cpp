#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<algorithm>
#include<numeric>
#include<functional>
#include<deque>
#include<time.h>
using namespace std;

class Player 
{
public:
	string mName;
	int mScore[3];
};

void Create_Player(map<int, Player>& mPlist, vector<int>& v1) 
{
	string seedName = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	for (int i = 0; i < 24; i++) 
	{
		Player p;
		p.mName = "选手";
		p.mName += seedName[i];
		for (int j = 0; j < 3; j++) 
		{
			p.mScore[j] = 0;
		}
	int uID = 100 + i;
	//保存选手的个人信息
	mPlist.insert(make_pair(uID, p));
	v1.push_back(uID);
	}
}

//选手抽签
void Set_Random(vector<int>& v) 
{
	random_shuffle(v.begin(),v.end());

}
//比赛
void Set_Score(int index, vector<int>& vIn, map<int, Player>& mPlist, vector<int>& vOut) 
{
	srand((unsigned int)time(NULL));
	multimap<int, int,greater<int>> mGroup;
	int groupIndex = 0;
	for (vector<int>::iterator it = vIn.begin(); it != vIn.end(); it++) 
	{
	//打分
		deque<int> dScore;
		for (int i = 0; i < 10; i++) 
		{
			int score = rand() % 40 + 60;
			dScore.push_back(score);
		}
		//排序
		sort(dScore.begin(), dScore.end());
		//去除最低最高分
		dScore.pop_back();
		dScore.pop_front();
		//求平均分
		int totalScore=accumulate(dScore.begin(), dScore.end(), 0);
		int avgScore = totalScore / dScore.size();
		mPlist[*it].mScore[index - 1] = avgScore; 
		mGroup.insert(make_pair(avgScore, *it));
		groupIndex++;
		if (groupIndex % 6 == 0) 
		{
			int numIndex = 0;
			for (multimap<int, int>::iterator it = mGroup.begin(); it != mGroup.end(); it++) 
			{
				if (numIndex >= 3) 
				{
					break;
				}
				vOut.push_back((*it).second);
				numIndex++;
			}
			mGroup.clear();
		}
	}
}

void Show_Good_Player(int index, vector<int>& v, map<int, Player>& mPlist) 
{
	cout << "第" << index << "论晋级名单" << endl;
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) 
	{
		cout << "姓名" << mPlist[*it].mName << "分数" << mPlist[*it].mScore[index - 1] << endl;
	}
}

int main(void) 
{
	//定义map容器，根据编号保存选手信息
	map<int, Player> mPlist;
	//第一轮比赛的参赛列表
	vector<int> v1;
	//第二轮比赛的参赛列表
	vector<int> v2;
	//第三轮比赛的参赛列表
	vector<int> v3;
	//最终前三名
	vector<int> v4;
	//创建选手
	Create_Player(mPlist,v1);
	//第一轮比赛
	Set_Random(v1);
	Set_Score(1,v1, mPlist, v2);
	Show_Good_Player(1,v2,mPlist);
	//第二轮比赛
	Set_Random(v2);
	Set_Score(2, v2, mPlist, v3);
	Show_Good_Player(2, v3, mPlist);
	//第三轮比赛
	Set_Random(v3);
	Set_Score(3, v3, mPlist, v4);
	Show_Good_Player(3, v4, mPlist);
	return 0;
}