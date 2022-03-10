#include <bits/stdc++.h>
using namespace std;
int ans = 1023;
int t;
int Case;
int num;
int copyNum;
int compareNum;
int cnt;
int val;
int main()
{
    cin >> t;

    while (t--)
    {
        compareNum = 0;
        cin >> num;
        cnt = 0;
        
        while (compareNum != ans){
            copyNum = num * (cnt + 1);
            val = copyNum;
            // cout << copyNum << '\n';
            while (copyNum)
            {
                compareNum |= (1 <<(copyNum % 10));
                copyNum /= 10;
            }
            // for (int i = 0 ; i < 10 ; ++i)
            // {
            //     if (compareNum & (1 << i))
            //         cout << "1";
            //     else
            //         cout << "0";
            // }
            // cout << "\n";
            ++cnt;
            
        }
        

        ++Case;
        cout << "#" << Case << " " << val << '\n';
        
    }
}