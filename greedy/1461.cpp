#include <functional>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	int n, m;
	cin >> n >> m;
	vector<int> plus;
	vector<int> minus;
	
	int num;
	for (int i = 0 ; i < n ; ++i)
	{
		cin >> num;
		if (num > 0)
			plus.push_back(num);
		else // 0은 문제에서 고려하지 않음
			minus.push_back(num);
	}
	// 내림차순
	sort(plus.begin(), plus.end(), greater<int>());
	// 오름차순
	sort(minus.begin(), minus.end());

	// for (auto value : plus)
	// 	cout << value << ' ';
	// cout << '\n';
	// for (auto value : minus)
	// 	cout << value << ' ';
	// cout << '\n';

	// size 저장해놓기
	int plusSize = plus.size();
	int minusSize = minus.size();
	int maxValue = 0;
	if (!plus.size())
		maxValue = abs(minus[0]);
	else if (!minus.size())
		maxValue = plus[0];
	else
	 	maxValue = plus[0] > abs(minus[0]) ? plus[0] : abs(minus[0]);
	// 정답 저장용 
	int total = 0;
	for (int i = 0 ; i < plusSize ; i = i + m)
		total += plus[i] * 2;
	for (int i = 0 ; i < minusSize ; i = i + m)
		total += abs(minus[i]) * 2;
	total -= maxValue;
	cout << total;
}