#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> balloons(n);
    for (int i = 0 ; i < n ; ++i)
        cin >> balloons[i];
    int cnt = 0;
    for (int i = 0 ; i < n ; ++i)
    {
        int start = balloons[i];
        if (!start)
            continue;
        cnt++;
        for (int j = i ; j < n ; ++j)
        {
            if (start < 1)
                break ;
            if (start == balloons[j])
            {
                start -= 1;
                balloons[j] = 0;
            }
        }
    }
    cout << cnt << '\n';
}