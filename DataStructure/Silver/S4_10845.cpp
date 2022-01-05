//https://www.acmicpc.net/problem/10845
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
queue<int> q;
int main(void)
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int n;
    
    cin >> n;
    string command;
    int value;
    for (int i = 0 ; i < n ; ++i)
    {
        cin >> command;
        if (command == "push")
        {
            cin >> value;
            q.push(value);
        }
        else if (command == "pop")
        {
            if (q.size())
            {
                cout << q.front() << endl;
                q.pop();
            }
            else    cout << -1 << endl;
        }
        else if (command == "size")
            cout << q.size() << endl;
        else if (command == "empty")
            cout << q.empty() << endl;
        else if (command == "front")
        {
            if (q.size())
                cout << q.front() << endl;
            else
                cout << -1 << endl;
        }
        else if (command == "back")
        {
            if (q.size())
                cout << q.back() << endl;
            else
                cout << -1 << endl;
        }
    }
}