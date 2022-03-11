#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    long long total = 1;
    cin >> n >> k;

    for (int i = k ; i > 0 ; i--)
        total = (total * i) % 1000000007;
    for (int i = n - k ; i > 0 ; i--)
        total = (total * i) % 1000000007;
    long long cnt = 1;
    long long b = 0;
    long long a = total;
    total = 1;
    while (1000000005 != b)
    {
        if (1000000005 & cnt)
        {
            total = (total * a) % 1000000007;
            b += cnt;
        }
        a = (a * a) % 1000000007;
        cnt *= 2;
    }
    for (int i = 1 ; i <= n ; ++i)
    {
        total = (i *  total) % 1000000007;
    }
    cout << total;

}