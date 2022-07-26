#include <bits/stdc++.h>
using namespace std;

struct Data {
	int sendTown;
	int receiveTown;
	int boxNum;
    bool operator<(const Data &c)
    {
        return receiveTown < c.receiveTown;
    }
};

int capacity[10001] = { 0 };
int n = 0, c = 0, m = 0;
int result = 0;


int main() {
	
	cin >> n >> c;
	cin >> m;
    vector<Data> v(m);
	for (int i = 0; i < m; i++)
		cin >> v[i].sendTown >> v[i].receiveTown >> v[i].boxNum;

	sort(v.begin(), v.end());

	for (int i = 0; i < m; i++) { 
		
		int maxNum = 0;
		for (int j = v[i].sendTown; j < v[i].receiveTown; j++)
			maxNum = max(capacity[j], maxNum);

		int val = min(v[i].boxNum, c - maxNum);
		result += val;
		for (int j = v[i].sendTown; j < v[i].receiveTown; j++)
        {
			capacity[j] += val;
		}
	}

	
	cout << result << endl;

}