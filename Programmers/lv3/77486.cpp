#include <bits/stdc++.h>

using namespace std;

int parent[10001];
int cost[10001];
vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    map<string, int> member;
	member.insert({"root", 1});
	int size = enroll.size();
	int cnt = 2;
	for (int i = 0 ; i < size ; ++i)
	{
		if (referral[i] == "-")
		{
			member.insert({enroll[i], cnt});
			parent[cnt] = 1;
		}
		else
		{
			member.insert({enroll[i], cnt});
			auto iter = member.find(referral[i]);
			int index = iter->second;
			parent[cnt] = index;
		}
		cnt++;
	}
	int sellerSize = seller.size();
	for (int i = 0 ; i < sellerSize ; ++i)
	{
		auto iter = member.find(seller[i]);
		int sellerIndex = iter->second;
		int value = amount[i] * 100;
		while (parent[sellerIndex] != 0)
		{
            int tmp = value;
            value = value * 0.1;
			cost[sellerIndex] += tmp - value;
			sellerIndex = parent[sellerIndex];
		}
	}
    
	vector<int> answer;
	for (int i = 2 ; i <= size + 1 ; ++i)
	{
		answer.push_back(cost[i]);
	}
    return answer;
}