#include <bits/stdc++.h>
using namespace std;
int numbers[1000001];
int main()
{
    int n;
    cin >> n;
    for (int i = 0 ; i < n + 1 ; ++i)
    {
        numbers[i] = 1e9;
    }
    numbers[1] = 0;
    for (int i = 2 ; i < n + 1 ; ++i)
    {
        if (i % 3 == 0)
            numbers[i] = min(numbers[i], numbers[i / 3] + 1);
        if (i % 2 == 0)
            numbers[i] = min(numbers[i], numbers[i / 2] + 1);
        numbers[i] = min(numbers[i], numbers[i - 1] + 1);
    }
    // for (int i = 1 ; i < n + 1 ; ++i)
    // {
    //     cout << numbers[i] << ' ';
    // }
    // cout << '\n';
    cout << numbers[n];
}