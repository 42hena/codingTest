#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int n;
    
    cin >> n;
    vector<int> v(n);

    int total = 0;
    for (int i = 0 ; i < n ; ++i)
    {
        cin >> v[i];
        total += v[i];
    }
    bool flag = true;
    if (total % 3 != 0)
        flag = false;
    int count = 0;
    for (int i = 0 ; i < v.size() ; ++i)
        count += v[i] / 2;
    if (count < total / 3)
        flag = false;
    if (flag)
        cout << "YES";
    else
        cout << "NO";
}