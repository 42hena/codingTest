#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin >> n;
    int f; cin >> f;
    n = n - n % 100;
    while (true)
    {
        if (n % f == 0)
            break;
        n++;
    }
    if(n % 100 < 10)
        printf("0%d", n % 100);
    else
        printf("%d", n % 100);
}