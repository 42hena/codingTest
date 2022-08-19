#include <iostream>
#include <queue>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int my;
	cin >> my;
	priority_queue<int> pq;
	for (int i = 0; i < n - 1; ++i)
	{
		int num;
		cin >> num;
		pq.push(num);
	}
	int cnt = 0;
	while (!pq.empty())
	{
		int value = pq.top();
		pq.pop();
		if (my <= value)
		{
			my++;
			cnt++;
			pq.push(value - 1);
		}
		else
			break;
	}
	cout << cnt;
}