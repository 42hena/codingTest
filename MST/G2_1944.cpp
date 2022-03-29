#include <bits/stdc++.h>

#define FOR(S, E) for(int S = 0 ; S < E ; ++S)
using namespace std;
int n, m;
char board[50][50];
int moveCount[50][50];

struct Pos{
    int y, x;
    bool operator<(const Pos &copy) const
    {
        if (y != copy.y)
            return y < copy.y;
        return x < copy.x;
    }
};

map<Pos, int> dict;
int sx, sy;
void input()
{
    cin >> n >> m;
    int count = 1;
    memset(moveCount, -1, sizeof(moveCount));
    FOR(i, n)
    {
        FOR(j, n)
        {
            cin >> board[i][j];
            if (board[i][j] == 'S')
            {
                sy = i;
                sx = j;
                dict.insert({{i,j}, 0});
            }
            else if (board[i][j] == 'K')
            {
                dict.insert({{i,j}, count});
                count++;
            }
        }
    }
}

int dy[] = {1, -1, 0, 0};
int dx[] = {0, 0, 1, -1};
int arr[251];
int findParent(int parent)
{
    if (arr[parent] == parent)
        return parent;
    return arr[parent] = findParent(arr[parent]);
}

void unionParent(int a, int b)
{
    a = findParent(a);
    b = findParent(b);
    if (a < b)
        arr[b] = a;
    else
        arr[a] =b;   
    
}
int same(int a, int b)
{
    a = findParent(a);
    b = findParent(b);
    if (a == b)
        return 1;
    else
        return 0;   
}
struct Edge
{
    int node1, node2;
    int cost;
    bool operator<(const Edge &copy) const
    {
        return cost < copy.cost;
    }
};

void solution()
{
    vector<Edge> v;
    
    FOR(i, n)
    {
        FOR(j, n)
        {
            if (board[i][j] == 'S' || board[i][j] == 'K')
            {
                queue<pair<int, int>> q;
                memset(moveCount, -1, sizeof(moveCount));
                auto start = dict.find({i, j});
                moveCount[i][j] = 0;
                q.push({i, j});
                while (!q.empty())
                {
                    int y = q.front().first;
                    int x = q.front().second;
                    
                    int move = moveCount[y][x];
                    q.pop();
                    if (!(i == y && j == x) && (board[y][x] == 'S' || board[y][x] == 'K'))
                    {
                        auto iter = dict.find({y, x});
                        v.push_back({iter->second, start->second, move});
                    }
                    FOR(i, 4)
                    {
                        int ny = y + dy[i];
                        int nx = x + dx[i];
                        if (board[ny][nx] == '1' || moveCount[ny][nx] != -1)   continue;
                        
                        moveCount[ny][nx] = moveCount[y][x] + 1;
                        q.push({ny, nx});
                    }
                }
            }
            
        }
    }

    //union find
    sort(v.begin(), v.end());
    FOR(i, m + 1)
        arr[i] = i;
    int sum = 0;
    int edgeCount = 0;
    for (int i = 0 ; i < v.size() ; ++i)
    {
        if (!same(v[i].node1, v[i].node2))
        {
            edgeCount++;
            sum += v[i].cost;
            unionParent(v[i].node1, v[i].node2);
        }
    }
    if (edgeCount == m)
        cout << sum;
    else
        cout << -1;
}

int main()
{
    input();
    solution();
}