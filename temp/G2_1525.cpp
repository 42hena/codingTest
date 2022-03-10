#include <bits/stdc++.h>
using namespace std;
set<string> s;
struct Data{
    string tmp;
    int pos;
    int cnt;
};
int main()
{
    string tmp = "";
    string ans = "123456780";
    char num;
    
    int x;
    for (int i = 0 ; i < 9 ; ++i)
    {
        cin >> num;
        tmp.push_back(num);
        if (num == '0')
            x = i;
    }
    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};
    queue<Data> q;
    q.push({tmp, x, 0});
    int answer = -1;
    while (!q.empty())
    {
        string temp = q.front().tmp;
        int x = q.front().pos;
        int cnt = q.front().cnt;
        if (temp == ans)
        {
            answer = cnt;
            break;
        }
        q.pop();
        // cout << temp <<' ' << cnt<< '\n';
        for (int i = 0 ; i < 4 ; ++i)
        {
            int nx = (x / 3) + dx[i];
            int ny = (x % 3) + dy[i];
            if (nx < 0 || nx >= 3 || ny < 0 || ny >= 3)
                continue;
            int pos = nx * 3 + ny;
            char c = temp[x];
            temp[x] = temp[pos];
            temp[pos] = c;
            if (s.find(temp) == s.end())
            {
                s.insert(temp);
                q.push({temp, pos, cnt + 1});
            }
            c = temp[x];
            temp[x] = temp[pos];
            temp[pos] = c;
        }
    }
    if (answer == -1)
        cout << -1;
    else
        cout << answer;
}