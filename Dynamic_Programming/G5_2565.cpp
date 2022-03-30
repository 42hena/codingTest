//https://www.acmicpc.net/problem/2565
#include <bits/stdc++.h>
using namespace std;
int dp[100];
int main()
{
    int n;
    cin >> n;
    vector<pair<int, int> > v(n);
    for (int i = 0 ; i < n ; ++i)
        cin >> v[i].first >> v[i].second;
    sort(v.begin(), v.end());
    int answer = 0;
    for (int i = 0 ; i < n ; ++i)
    {
        dp[i] = 1;
        for (int j = 0 ; j < i ; ++j)
        {
            if (v[j].second < v[i].second)
            {
                dp[i] = max(dp[i], dp[j] + 1) ;
            }
        }
        answer = max(dp[i], answer);
    }   
    
    cout << n - answer;
}
/*
first나 second로 정렬을 실행하면 LIS의 꼴이 나온다
LIS의 Max값을 제외한 나머지를 제거한 것이 답이다.
*/