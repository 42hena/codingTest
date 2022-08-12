#include <bits/stdc++.h>
using namespace std;
int numbers[1000001];
int recursive(int n)
{
    if (n <= 1)
        return numbers[n] = 0;
    if (numbers[n] != -1)
        return numbers[n];
    int minValue = recursive(n - 1) + 1;
    if (n % 3 == 0)
        minValue = min(minValue, recursive(n / 3) + 1);
    if (n % 2 == 0)
        minValue = min(minValue, recursive(n / 2) + 1);
    return numbers[n] = minValue;
}
int main()
{
    int n;
    memset(numbers, -1, sizeof(numbers));
    cin >> n;
    
    cout << recursive(n) << '\n';
}