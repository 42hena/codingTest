//https://www.acmicpc.net/problem/10828
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
stack<int> s;
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
            s.push(value);
        }
        else if (command == "pop")
        {
            if (s.size())
            {
                cout << s.top() << endl;
                s.pop();
            }
            else    cout << -1 << endl;
        }
        else if (command == "size")
            cout << s.size() << endl;
        else if (command == "empty")
            cout << s.empty() << endl;
        else if (command == "top")
        {
            if (s.size())
                cout << s.top() << endl;
            else
                cout << -1 << endl;
        }
    }
}