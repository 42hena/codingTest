#include <bits/stdc++.h>

using namespace std;

bool check(int &a, int &b, vector<int> &g, vector<int> &s, vector<int> &w, vector<int> &t, long long mid)
{
    long long totalGold = 0;
    long long totalSilver = 0;
    long long totalGoldAndSilver = 0;
    for (int i = 0 ; i < g.size() ; ++i)
    {
        long long time = t[i];
        long long roundTime = time * 2;
        
        long long moveCount = mid / roundTime;
        if (mid % roundTime >= time)
            moveCount++;
        long long totalBucket = w[i] * moveCount;
        totalGold += min((long long)g[i], totalBucket);
        totalSilver += min((long long)s[i], totalBucket);
        totalGoldAndSilver += min((long long)g[i] + s[i], totalBucket);
    }
    if (totalGold >= a && totalSilver >= b && totalGoldAndSilver >= a + b)
        return true;
    return false;
}

long long solution(int a, int b, vector<int> g, vector<int> s, vector<int> w, vector<int> t) {
    long long answer = -1;
    long long left = 1;
    long long right = 4*10e14 + 10e5;
    
    while (left <= right)
    {
        long long mid = (left + right) / 2;
        if (check(a, b, g, s, w, t, mid))
        {
            answer = mid;
            right = mid - 1;
        }
        else
            left = mid + 1;
    }
    return answer;
}