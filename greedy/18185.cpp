#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> ramen(n + 2);
    for (int i = 0 ; i < n ; ++i)
        cin >> ramen[i];
    
    int total = 0;
    for (int i = 0 ; i < n ; ++i)
    {
        if (ramen[i + 1] > ramen[i + 2])
        {
            int value1 = min(ramen[i], ramen[i + 1] - ramen[i + 2]);
            ramen[i] -= value1;
            ramen[i + 1] -= value1;
            total += 5 * value1;

            int value2 = min(ramen[i], min(ramen[i + 1], ramen[i + 2]));
            total += value2 * 7;
            ramen[i] -= value2;
            ramen[i + 1] -= value2;
            ramen[i + 2] -= value2;
        }
        else
        {
            int value1 = min(ramen[i], min(ramen[i + 1], ramen[i + 2]));
            ramen[i] -= value1;
            ramen[i + 1] -= value1;
            ramen[i + 2] -= value1;
            total += 7 * value1;

            int value2 = min(ramen[i], ramen[i + 1]);
            total += value2 * 5;
            ramen[i] -= value2;
            ramen[i + 1] -= value2;
        }
        total += ramen[i] * 3;
    }
    cout << total;
}