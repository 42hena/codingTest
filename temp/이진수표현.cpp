#include <bits/stdc++.h>
using namespace std;
int t;
int Case;
int n, m;
int main()
{
    cin >> t;

    while (t--)
    {
        int compareNum = 0;
        cin >> n >> m;
        int i = 0;
        // while (i < 32){
        //     compareNum = (1 << i) & m;
        //     ++i;
        // }
        
        ++Case;
        bool flag = true;
        for (int i = 0 ; i < n ; ++i){
            // cout << (m & (1 << (i))) << '\n';
            if ( (m & (1 << (i))) == 0){
                flag = false;
                break;
            }
        }
        if (flag)
            cout << "#" << Case << " " << "ON" << '\n';
        else
            cout << "#" << Case << " " << "OFF" << '\n';       
    }
}