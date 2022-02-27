#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> plus;
    vector<int> minus;
    int num;
    int ans = 0;
    for (int i = 0 ; i < n ; ++i)
    {
        cin >> num;
        if (num == 1)   
            ans += 1;
        else if (num > 1)
            plus.push_back(num);
        else
            minus.push_back(num);
    }
    sort(plus.begin(), plus.end());
    sort(minus.begin(), minus.end());
    int plusSize = plus.size();
    int minusSize = minus.size();

    for (int i = plusSize - 1 ; i > 0 ; i = i - 2)
        ans += plus[i] * plus[i - 1];
    if ((plusSize & 1))
        ans += plus[0];
    for (int i = 0 ; i < minusSize - 1 ; i = i + 2)
        ans += minus[i] * minus[i + 1];
    if ((minusSize & 1))
        ans += minus[minusSize - 1];
    cout << ans;
}