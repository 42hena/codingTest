#include <bits/stdc++.h>
using namespace std;
int main()
{
    int coinKindNum, money;

    cin >> coinKindNum >> money;
    vector<int> coin(coinKindNum);
    for (int i = 0 ; i < coinKindNum ; ++i)
        cin >> coin[i];
    int ans = 0;
    for (int i =  coinKindNum - 1 ; i >= 0 ; --i)
        if (money / coin[i])
        {
            ans += money / coin[i];
            money -= coin[i] * (money / coin[i]);
        }
    cout << ans;
}