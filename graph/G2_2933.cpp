#include <bits/stdc++.h>
using namespace std;
char cave[100][100];
bool visited[100][100];
int r, c;

struct Pos{
    int x, y;
    bool operator<(const struct Pos &copy) const
    {
        if (x != copy.x)
            return x > copy.x;
        return y < copy.y;    
        

    }
};

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void leftShoot(int height)
{
    int caveHeight = r - height;//바라보는 방향이 다름
    int posX, posY;

    for (int i = 0 ; i < c ; ++i)
    {
        if (cave[caveHeight][i] == 'x')
        {
            cave[caveHeight][i] = '.';
            break;
        }
    }
}

void rightShoot(int height)
{
    int caveHeight = r - height;//바라보는 방향이 다름
    int posX, posY;
    for (int i = c - 1 ; i >= 0 ; --i)
    {
        if (cave[caveHeight][i] == 'x')
        {
            cave[caveHeight][i] = '.';
            break;
        }
    }
}

bool BFS(int col, int row, vector<Pos> &v)
{
    bool flag = false;
    queue<Pos> q;
    
    q.push({col, row});
    v.push_back({col, row});
    visited[col][row] = true;
    while (!q.empty())
    {
        Pos now = q.front();
        if (now.x == r - 1)
        {
            flag = true;
        }
        q.pop();
        for (int d = 0 ; d < 4 ; ++d)
        {
            int nx = now.x + dx[d];
            int ny = now.y + dy[d];
            if (cave[nx][ny] == '.')    continue;
            if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
            if (!visited[nx][ny] && cave[nx][ny] == 'x')
            {
                q.push({nx, ny});
                v.push_back({nx, ny});
                visited[nx][ny] = true;
            }
        }
    }
    
    if (flag)//벽에 닿아있음
        return false;
    return true;
}

void downCluster(vector<Pos> &v)
{
    bool cluster[100][100];
    memset(cluster, false, sizeof(cluster));
    bool check = true;
    while (check)
    {
        for (int i = 0 ; i < v.size() ; ++i)
        {
            int x = v[i].x;
            int y = v[i].y;
            v[i].x = x + 1;
            cave[x + 1][y] = 'x';
            cave[x][y] = '.';
            cluster[x + 1][y] = true;
            
            if (x + 2 == r || (cave[x + 2][y] == 'x' && !cluster[x + 2][y]))
            {
                check = false;
            }
        }
    }
    for (int i = 0 ; i < v.size() ; ++i)
    {
        visited[v[i].x][v[i].y] = true;
    }
}
int main()
{
    cin >> r >> c;   
    for (int i = 0 ; i < r ; ++i)
        for (int j = 0 ; j < c ; ++j)
            cin >> cave[i][j];

    int stickNum;
    cin >> stickNum;
    vector<int> sticks(stickNum);
    for (int i = 0 ; i < stickNum ; ++i)
        cin >> sticks[i];

    int index = 0;
    vector<Pos> v;
    while (index < stickNum)
    {
        if (index % 2 == 0) //left
            leftShoot(sticks[index]);
        else            //right
            rightShoot(sticks[index]);
        memset(visited, false, sizeof(visited));
        
        for (int i = 0 ; i < r ; ++i)
        {
            for (int j = 0 ; j < c ; ++j)
            {
                if (cave[i][j] == 'x' && !visited[i][j])
                {
                    v.clear();  
                    bool ret = BFS(i, j, v);
                    if (ret)//닿지 않음
                    {
                        sort(v.begin(), v.end());
                        downCluster(v);
                    }
                }
            }
        }
        
        ++index;
    }
    for (int a = 0 ; a < r ; ++a)
        {
            for (int b = 0 ; b < c ; ++b)
            {
                cout << cave[a][b];
            }
            cout << '\n';
        }
}