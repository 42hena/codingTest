#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Data
{
	int p, d;
	bool operator<(const Data& copy) const
	{
		return d > copy.d;
	}
};
int main()
{
	int n;
	cin >> n;
	if (n == 0)
	{
		cout << 0;
		exit(0);
	}
	vector<Data> v(n);
	for (int i = 0; i < n; ++i)
		cin >> v[i].p >> v[i].d;

	sort(v.begin(), v.end());
	/*for (auto x : v)
	{
		cout << x.p << ' ' << x.d << '\n';
	}*/
	int start = v[0].d;

	int total = 0;
	for (; start > 0; start--)
	{
		//cout << "date:" << start << '\n';

		int maxIndex = -1;
		int maxValue = 0;
		for (int i = 0; i < v.size(); ++i)
		{
			int now = v[i].d;
			//cout << "now " << now << '\n';
			if (start <= now)
			{
				int value = v[i].p;
				if (value > maxValue)
				{
					maxValue = value;
					maxIndex = i;
				}
			}
			else
				break;
		}
		if (v.size() && maxIndex != -1)
		{
			total += v[maxIndex].p;
			v.erase(v.begin() + maxIndex);
		}
	}
	cout << total;
}