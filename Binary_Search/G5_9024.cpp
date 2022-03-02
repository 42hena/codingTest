#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    int n, k;

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    while (t--){
        cin >> n >> k;
        vector<int> array(n);
        set<int> s;
        for (int i = 0 ; i < n ; ++i)
            cin >> array[i];
        sort(array.begin(), array.end());
        int i = 0;
        int j = n - 1;
        while (i < j)
        {
            int value = array[i] + array[j];
            if (value > k)
                j--;
            else
                i++;
            s.insert(abs(value - k));
        }
        int findValue =  *s.begin();
        int cnt = 0;
        for (int i = 0 ; i < n ; ++i)
        {
            // cout << "test";
            int l = i + 1;
            int r = n - 1;
            int ans = -1;
            while (l <= r)
            {
                int m = (l + r) / 2;
                
                int cmpValue = array[m] + array[i];
                // cout <<"value" <<cmpValue << '\n';
                if (cmpValue == k - findValue || cmpValue == k + findValue)
                {
                    ans = m;
                    break;
                }
                else if (cmpValue > k)
                    r = m - 1;
                else if (cmpValue < k)
                    l = m + 1;
            }   
            if (ans != -1)
                cnt++;
        }
        cout << cnt << '\n';
    }
}