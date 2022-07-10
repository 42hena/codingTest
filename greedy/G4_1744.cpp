#include <bits/stdc++.h>
using namespace std;

// [n : 수열의 크기]
// [plus :  2 이상의 값들]
// [minus : 0 이하의 값들]
int n;
int main(void)
{
    cin >> n;
    vector<int> plus;
    vector<int> minus;
    int number;
    int total = 0;
    for (int i = 0 ; i < n ; ++i)
    {
        cin >> number;
        if (number > 0)
        {
            if (number == 1)
                total++;
            else
                plus.push_back(number);
        }
        else
            minus.push_back(number);
    }
    sort(minus.begin(), minus.end());
    sort(plus.begin(), plus.end(), greater<>());

    int minusCount = minus.size();
    for (int i = 0 ; i < minusCount ; i = i + 2)
    {
        if (i + 1 < minusCount)
            total += minus[i] * minus[i + 1];
        else
            total += minus[i];
    }
    int plusCount = plus.size();
    for (int i = 0 ; i < plusCount ; i = i + 2)
    {
        if (i + 1 < plusCount)
        {
            total += plus[i] * plus[i + 1];
        }
        else
            total += plus[i];
    }
    cout << total;
}