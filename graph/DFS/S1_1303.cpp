#include <iostream>
#include <queue>
using namespace std;
bool visited[100][100];
char board[100][100];
int dy[] = {1, -1, 0, 0};
int dx[] = {0, 0, 1, -1};
int n, m;
int dfs(int y, int x, char ch)
{
	int sum = 0;
	visited[y][x] = true;
	for (int i = 0 ; i < 4 ; ++i)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || ny >= m || nx < 0 || nx >= n)
			continue;
		if (visited[ny][nx]) continue;
		if (board[ny][nx] != ch) continue;
		sum += dfs(ny, nx, ch);
	}
	return (sum + 1);
}

int main()
{
	cin >> n >> m;
	for (int i = 0 ; i < m ; ++i)
	{
		for (int j = 0 ; j < n ; ++j)
		{
			cin >> board[i][j];
		}
	}

	int w = 0, b = 0;
	for (int i = 0 ; i < m ; ++i)
	{
		for (int j = 0 ; j < n ; ++j)
		{
			if (!visited[i][j])
			{
				int value = dfs(i, j, board[i][j]);
				if (board[i][j] == 'W')
					w += (value * value);
				else
					b += (value * value);
			}
		}
	}
	cout << w << ' ' << b;
}