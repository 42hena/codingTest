#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int arr[100][100];
bool visited[100][100];
int m, n, k;
struct pos{
    int x;
    int y;
};
vector<int> v;
void BFS(int i, int j)
{
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    queue<pos> q;
    q.push({i, j});
    visited[i][j] = true;
    int cnt = 0;
    while (!q.empty())
    {
        int x = q.front().x;
        int y = q.front().y;
        q.pop();
        for (int k = 0 ; k < 4 ; k++){
            int nx = x + dx[k];
            int ny = y + dy[k];
            
            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            if (!visited[nx][ny] && !arr[nx][ny]){
                q.push({nx, ny});
                visited[nx][ny] = true;
                cnt++;
            }
        }
    }
    v.push_back(cnt + 1);
}

bool compare(int a, int b)
{
    return a < b;
}

int main()
{
    

    cin >> m >> n >> k;
    for (int i = 0 ; i < k ; i++){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for (int a = x1 ; a < x2 ; a++){
            for (int b = y1 ; b < y2 ; b++){
                arr[a][b] = 1;
            }
        }
    }

    // for (int i = 0 ; i < n ; i++){
    //     for (int j = 0 ; j < m ; j++){
    //         cout << arr[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    // cout << '\n';

    int cnt = 0;
    for (int i = 0 ; i < n ; i++){
        for (int j = 0 ; j < m ; j++){
            if (!visited[i][j] and !arr[i][j]){
                BFS(i, j);
                cnt++;
            }
        }
    }

    // for (int i = 0 ; i < n ; i++){
    //     for (int j = 0 ; j < m ; j++){
    //         cout << visited[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

    sort(v.begin(), v.end(), compare);
    cout << cnt<< '\n';
    for (int i = 0 ; i < v.size() ; i++)
        cout << v[i] << ' ';
}