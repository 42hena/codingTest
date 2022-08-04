#include <bits/stdc++.h>

using namespace std;

long long int total = 0;
int main(void)
{
    int n;
    cin >> n;
    vector<long long> plus;
    vector<long long> minus;
    for (int i = 0 ; i < n ; ++i)
    {
        int num;
        cin >> num;
        if (num == 1)
            total += 1;
        else if (num > 1)
            plus.push_back(num);
        else
            minus.push_back(num);
    }
    if (plus.size())
    {
        sort(plus.begin(), plus.end());
        for (int i = plus.size() - 1 ; i >= 0 ; i -= 2)
        {
            if (i - 1 >= 0)
                total += plus[i] * plus[i - 1];
            else
                total += plus[i];
        }
    }
    if (minus.size())
    {
        sort(minus.begin(), minus.end());
        for (int i = 0 ; i < minus.size() ; i += 2)
        {
            if (i + 1 < minus.size())
                total += minus[i] * minus[i + 1];
            else
                total += minus[i];
        }
    }
    cout << total;
}