#include <iostream>
using namespace std;

int cost[26][26];


int main()
{
	int m, n;
	cin >> m >> n;
	for (int i = 0; i < 26; ++i)
		for (int j = 0; j < 26; ++j)
		{
			if (i == j)
				continue;
			cost[i][j] = 1e4;
		}
	for (int i = 0; i < m; ++i)
	{
		char ch1, ch2;
		cin >> ch1 >> ch2;
		cost[ch1 - 'a'][ch2 - 'a'] = 1;
		//cost[ch2 - 'a'][ch1 - 'a'] = 1;
	}
	for (int via = 0; via < 26; ++via)
		for (int start = 0; start < 26; ++start)
		{
			for (int end = 0; end < 26; ++end)
				cost[start][end] = min(cost[start][end], cost[start][via] + cost[via][end]);
		}

	/*for (int i = 0; i < 26; ++i) {
		for (int j = 0; j < 26; ++j)
		{
			printf(" %5d", cost[i][j]);
		}
		printf("\n");
	}*/


	for (int i = 0; i < n; ++i)
	{
		string first, second;
		cin >> first >> second;
		/*cout << "before:" << first << ' ' << second << '\n';*/
		if (first.size() != second.size())
		{
			cout << "no\n";
			continue;
		}
		for (int j = 0; j < first.size(); ++j)
		{
			if (first[j] == second[j])
				continue;
			int ch = first[j] - 'a';
			int index = -1;
			for (int k = 0; k < 26; ++k)
			{
				if (cost[ch][k] != 1e4)
				{
					char t = 'a' + k;
					if (t == second[j])
						index = k;
				}
			}

			if (index != -1)
			{
				first[j] += index - ch;
			}
		}
		//cout << first << ' ' << second << '\n';
		if (first == second)
			cout << "yes\n";
		else
			cout << "no\n";
	}
}