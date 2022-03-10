#include <bits/stdc++.h>
using namespace std;

long long memo[91];
long long fibonacci(int n)
{
    if (memo[n] != -1)
        return memo[n];
    if (n == 1)
        return 1;
    if (n == 0)
        return 0;
    memo[n] = fibonacci(n - 1) + fibonacci(n - 2);
    return memo[n];
}

int main()
{
    int n;

    cin >> n;
    fill(memo, memo + 91, -1);
    cout << fibonacci(n);
}