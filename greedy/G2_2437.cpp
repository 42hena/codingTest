#include <bits/stdc++.h>
using namespace std;

// [n : 추의 개수]
// [weights : 추의 배열]
// [maxWeight : 추게 잴 수 있는 최대 무게]
int main()
{
    int n;
    cin >> n;
    vector<int> weights(n);
    for (int i = 0 ; i < n ; ++i)
        cin >> weights[i];
    sort(weights.begin(), weights.end());
    int maxWeight = 1;
    for (auto value : weights)
    {
        if (maxWeight < value)
            break;
        maxWeight += value;
    }
    cout << maxWeight;
}
