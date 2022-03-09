#include <bits/stdc++.h>
using namespace std;
struct Data
{
    int type;
    int attackDamage;
    int health;
};
int main()
{
    int n, h;//방 개수, 초기 공격력
    cin >> n >> h;
    vector<Data> v(n);
    for (int i = 0 ; i < n ; ++i)
    {
        cin >> v[i].type >> v[i].attackDamage >> v[i].health;
    }
    long long l = 0;
    long long r = 	9223372036854775807;
    long long ans;
    while (l <= r)
    {
        long long copyH = h;
        long long m = (l + r) / 2;
        // cout << m << '\n';
        long long copyM = m;
        for (int i = 0 ; i < n ; ++i)
        {
            if (v[i].type == 1)
            {
                copyM -= floor((v[i].health - 1) / copyH) * v[i].attackDamage;
            }
            else{
                if (copyM + v[i].health > m)
                    copyM = m;
                else
                    copyM += v[i].health;
                copyH += v[i].attackDamage;
            }
            if (copyM <= 0)
                break;
        }
        if (copyM > 0)
        {
            ans = m;
            r = m - 1;
        }
        else
        {
            l = m + 1;
        }
    }
    cout << ans << '\n';
}