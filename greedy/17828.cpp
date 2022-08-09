#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    if (n > m)
    {
        cout << "!";
        return 0;
    }
    vector<char> v;
    for (int i = 0 ; i < n ; ++i)
    {
        int value = m - (n - 1 - i);
        if (value >= 26)
        {
            v.push_back('Z');
            m -= 26;
        }
        else if (value > 1)
        {
            v.push_back('A' + value - 1);
            m -= value;
        }
        else if (value == 1)
        {
            v.push_back('A');
            m -= 1;
        }
    }
    if (m)
        cout << "!";
    else
        for (int i = n - 1 ; i >=0  ; --i)
            cout << v[i];
}