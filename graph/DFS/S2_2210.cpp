#include <iostream>
#include <set>
#include <string>
#include <vector>
using namespace std;

char board[5][5];
int dy[] = {1, -1, 0, 0};
int dx[] = {0, 0, 1, -1};
set<string> s;

void DFS(int y, int x, int count, vector<char> &v)
{
	if (count  == 5)
	{
		string tmp = "";
		for (int i = 0 ; i < v.size() ; ++i)
		{
			tmp += v[i];
		}
		s.insert(tmp);
		return ;
	}

	for (int i = 0  ; i < 4 ; ++i)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || ny >= 5 || nx < 0 || nx >= 5)
			continue;
        v.push_back(board[ny][nx]);
        DFS(ny, nx, count + 1, v);
        v.pop_back();
	}
}

int main()
{
	for (int i = 0 ; i < 5 ; ++i)
	{
		for (int j = 0 ; j < 5 ; ++j)
		{
			cin >> board[i][j];
		}
	}

	vector<char> v;
	for (int i = 0 ; i < 5 ; ++i)
	{
		for (int j = 0 ; j < 5 ; ++j)
		{
			v.push_back(board[i][j]);
			DFS(i, j, 0, v);
			v.pop_back();
		}
	}
	cout << s.size();
}