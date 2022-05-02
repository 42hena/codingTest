#include <iostream>

using namespace std;
#include <vector>
#include <queue>
int visited[10001];
int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	vector<int> v(n + 1);
	for (int i = 1 ; i < n + 1 ; ++i)
		cin >> v[i];
	int a, b;
	cin >> a >> b;
	queue<pair<int, int> > q;
	q.push(make_pair(a, 0));
	while (!q.empty())
	{
		int now = q.front().first;
		int cnt = q.front().second;
		if (now == b)
		{
			cout << cnt;
			return 0;
		}
		q.pop();
		int tmp = v[now];
		while (now + tmp <= n)
		{
			if (!visited[now + tmp])
				q.push(make_pair(now + tmp, cnt + 1));
			visited[now + tmp] = true;
			tmp += v[now];
		}
		tmp = v[now];
		while (now - tmp >= 1)
		{
			if (!visited[now - tmp])
				q.push(make_pair(now - tmp, cnt + 1));
			visited[now - tmp] = true;
			tmp += v[now];
		}
	}
	cout << -1;
}