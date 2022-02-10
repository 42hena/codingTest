#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define INF 2147483647

int n, cnt = 1;
int Map[125][125];
int dist[125][125];
struct Data{
	int x, y, w;

	bool operator<(const struct Data &copy) const
	{
		return w > copy.w;
	}
};

void Input()
{
	for (int i = 0 ; i < n ; ++i)
		for (int j = 0 ; j < n ; ++j){
			cin >> Map[i][j];
			dist[i][j] = INF;
		}
}
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
void dijkstra()
{
	dist[0][0] = Map[0][0];
	priority_queue<Data> pq;

	pq.push({0, 0, dist[0][0]});

	while (!pq.empty())
	{
		int x = pq.top().x;
		int y = pq.top().y;
		int nowCost = pq.top().w;
		pq.pop();

		if (dist[x][y] < nowCost)
			continue;
		for (int i = 0 ; i < 4 ; ++i)
		{
			int nextX = x + dx[i];
			int nextY = y + dy[i];
			int nextCost = nowCost + Map[nextX][nextY];
			if (nextX < 0 || nextX >= n || nextY < 0 || nextY >= n)
				continue;
			if (nextCost < dist[nextX][nextY])
			{
				dist[nextX][nextY] = nextCost;
				pq.push({nextX, nextY, nextCost});
			}
		}

	}
	cout << "Problem " << cnt <<": " << dist[n - 1][n - 1] << '\n';
}

int main()
{
	while (true)
	{
		cin >> n;
		if (n == 0)
			break;
		Input();
		dijkstra();
		cnt++;
	}

}