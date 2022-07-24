#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, b, c;
    cin >> n >> b >> c;
    vector<long long> ramen(n + 2);
    for (int i = 0 ; i < n ; ++i)
        cin >> ramen[i];
    
    long long total = 0;
    if (b<=c)
    {
        for (int i = 0 ; i < n ; ++i)
            total += ramen[i] * b;
        cout << total;
        exit(0);
    }
    for (int i = 0 ; i < n ; ++i)
    {
        if (ramen[i + 1] > ramen[i + 2])
        {
            long long value1 = min(ramen[i], ramen[i + 1] - ramen[i + 2]);
            ramen[i] -= value1;
            ramen[i + 1] -= value1;
            total += (b + c) * value1;

            long long value2 = min(ramen[i], min(ramen[i + 1], ramen[i + 2]));
            total += value2 * (b + 2*c);
            ramen[i] -= value2;
            ramen[i + 1] -= value2;
            ramen[i + 2] -= value2;
        }
        else
        {
            long long value1 = min(ramen[i], min(ramen[i + 1], ramen[i + 2]));
            ramen[i] -= value1;
            ramen[i + 1] -= value1;
            ramen[i + 2] -= value1;
            total += (b + 2*c) * value1;

            long long value2 = min(ramen[i], ramen[i + 1]);
            total += value2 * (b + c);
            ramen[i] -= value2;
            ramen[i + 1] -= value2;
        }
        total += ramen[i] * b;
    }
    cout << total;
}