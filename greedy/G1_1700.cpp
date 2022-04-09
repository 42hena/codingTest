#include <bits/stdc++.h>
using namespace std;

int multitap[100];
int main()
{
    int ans = 0;
    int n, k;
    cin >> n >> k;
    vector<int> schedule(k);
    for (int i = 0 ; i < k ; ++i)
        cin >> schedule[i];
    
    for (int i = 0 ; i < k ; ++i) // 스케줄
    {
        bool exist = false;
        for (int j = 0 ; j < n ; ++j) //멀티텝
        {
            if (schedule[i] == multitap[j]) // 같다면 갈아줄 필요 x
            {
                exist = true;
                break;
            }
        }
        if (exist)
            continue;
        bool in = false;
        for (int j = 0 ; j < n ; ++j) //멀티텝
        {
            if (!multitap[j])
            {
                multitap[j] = schedule[i];
                in = true;
                break;
            }
        }
        if (in)
            continue;
        int maxValue = 0;
        int maxIndex = 0;
        
        for (int j = 0 ; j < n ; ++j) //멀티텝
        {
            bool check = false;
            for (int a = i + 1 ; a < k ; ++a)
            {
                if (multitap[j] == schedule[a])
                {
                    check = true;
                    if (maxValue < a - i)
                    {
                        maxValue = a - i;
                        maxIndex = j;
                    }
                    break;
                }
            }
            if (!check)
            {
                maxValue = 100;
                maxIndex = j;
            }
        }
        multitap[maxIndex] = schedule[i];
        ans++;
    }
    cout << ans;
}