#include <bits/stdc++.h>
using namespace std;

struct Oven
{
    int ADDH, ADDT, MINT, ADDO, MINO;
    int now;
    // bool operator<(const Oven &copy) const
    
};
bool visited[61];
Oven oven[61];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    queue<Oven> q;
    q.push({0, 0, 0, 0, 0, 0});
    visited[0] = true;
    oven[0] = {0, 0, 0, 0, 0, 0};
    while (!q.empty())
    {
        Oven now = q.front(); q.pop();
        // cout << now.ADDH<< ' ' << now.ADDT << ' ' << now.MINT << ' ' << now.ADDO << ' ' << now.MINO  << ' ' << "value: " << now.now<< '\n';
        if (now.now - 1 >= 0 && !visited[now.now - 1])
        {
            q.push({now.ADDH, now.ADDT, now.MINT, now.ADDO, now.MINO + 1, now.now - 1});
            visited[now.now - 1] = true;
            oven[now.now - 1] = {now.ADDH, now.ADDT, now.MINT, now.ADDO, now.MINO + 1, now.now - 1};
        }
        if (now.now + 1 <= 60 && !visited[now.now + 1])
        {
            q.push({now.ADDH, now.ADDT, now.MINT, now.ADDO + 1, now.MINO, now.now + 1});
            visited[now.now + 1] = true;
            oven[now.now + 1] = {now.ADDH, now.ADDT, now.MINT, now.ADDO + 1, now.MINO, now.now + 1};
        }
        if (now.now - 10 >= 0 && !visited[now.now - 10])
        {
            q.push({now.ADDH, now.ADDT, now.MINT + 1, now.ADDO, now.MINO, now.now - 10});
            visited[now.now - 10] = true;
            oven[now.now - 10] = {now.ADDH, now.ADDT, now.MINT + 1, now.ADDO, now.MINO, now.now - 10};
        }
        if (now.now + 10 <= 60 && !visited[now.now + 10])
        {
            q.push({now.ADDH, now.ADDT + 1, now.MINT, now.ADDO, now.MINO, now.now + 10});
            visited[now.now + 10] = true;
            oven[now.now + 10] = {now.ADDH, now.ADDT + 1, now.MINT, now.ADDO, now.MINO, now.now + 10};
        }
        if (now.now + 60 <= 60 && !visited[now.now + 60])
        {
            q.push({now.ADDH + 1, now.ADDT, now.MINT, now.ADDO, now.MINO, now.now + 60});
            visited[now.now + 60] = true;
            oven[now.now + 60] = {now.ADDH + 1, now.ADDT, now.MINT, now.ADDO, now.MINO, now.now + 60};
        }
    }
    // for (int i = 0 ; i < 61 ; ++i)
    //     cout << oven[i].ADDH << ' ' << oven[i].ADDT << ' ' << oven[i].MINT << ' ' << oven[i].ADDO << ' ' << oven[i].MINO << ' ' << oven[i].now<< '\n';
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a = n / 60;
        int b = n % 60;
        
        cout << oven[b].ADDH + a << ' ' << oven[b].ADDT << ' ' << oven[b].MINT << ' ' << oven[b].ADDO << ' ' << oven[b].MINO << '\n';
    }
}