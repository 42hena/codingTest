#include <bits/stdc++.h>
using namespace std;
int cache[31][2][10001]; //w type t
int main()
{
    int t, w;
    cin >> t >> w;
    vector<int> v(t + 1);
    for (int i = 1 ; i < t + 1 ; ++i)
        cin >> v[i];


    for (int i = 0 ; i < t + 1 ; ++i)
    {
        if (v[i] == 1)
            cache[0][0][i] = cache[0][0][i - 1] + 1;
        else if (v[i] == 2)
            cache[0][0][i] = cache[0][0][i - 1];
    }

    for (int i = 1 ; i < w + 1 ; ++i)
    {
        for (int j = 0 ; j < 2 ; ++j)
        {
            for (int k = 1 ; k < t + 1 ; ++k)
            {
                if (j == 0)
                {
                    if (v[k] == 1)
                        cache[i][j][k] = max(cache[i][j][k - 1], cache[i - 1][j + 1][k - 1]) + 1;
                    else
                        cache[i][j][k] = max(cache[i][j][k - 1], cache[i - 1][j + 1][k - 1]);
                }
                else
                {
                    if (v[k] == 2)
                        cache[i][j][k] = max(cache[i][j][k - 1], cache[i - 1][j - 1][k - 1]) + 1;
                    else
                        cache[i][j][k] = max(cache[i][j][k - 1], cache[i - 1][j - 1][k - 1]);
                }
            }
        }
    }
    cout << max(cache[w][0][t], cache[w][1][t]);
}