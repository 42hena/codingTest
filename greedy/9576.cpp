#include <bits/stdc++.h>
using namespace std;
int visited[1001];

struct Data
{
	int a, b;

	bool operator<(const Data &copy) const
	{
		// if (a == copy.a)
			return b < copy.b;
		// return a < copy.a;
	}
};

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		// init
		memset(visited, false,  sizeof(visited));
		int n, m;
		cin >> n >> m;
		vector<Data> v(m);
		for (int i = 0 ; i < m ; ++i)
			cin >> v[i].a >> v[i].b;
		int ans = 0;
		sort(v.begin(), v.end());
		for (auto value : v)
		{
			// cout << value.a << ' ' << value.b << '\n';
			for (int day = value.a ; day <= value.b ; ++day)
			{
				if (!visited[day])
				{
					ans++;
					visited[day] = true;
					break;
				}
			}
		}
		cout << ans << '\n';
			
	}
}