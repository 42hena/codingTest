#include <bits/stdc++.h>
using namespace std;
long long int cache[100][21];
int main()
{
    
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0 ; i < n ; ++i)
    {
        cin >> v[i];
    }
    cache[0][v[0]] = 1;
    for (int i = 1 ; i < n - 1 ; ++i)
    {
        for (int j = 0 ; j < 21 ; ++j)
        {
            int nextPlus = j + v[i];
            int nextMinus = j - v[i];
            if (nextPlus <= 20)
                cache[i][nextPlus] += cache[i - 1][j];
            if (nextMinus >= 0)
                cache[i][nextMinus] += cache[i - 1][j];
        }
    }
    cout << cache[n - 2][v[n - 1]];
}