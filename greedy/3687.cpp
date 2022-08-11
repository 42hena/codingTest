#include <bits/stdc++.h>
using namespace std;
vector<string> dp(101);
vector<string> addValue(8);

string bigSolve(int n)
{
    string ret = "";
    if (n == 2)
        ret= "1";
    else if (n == 3)
        ret= "7";
    else
    {
        if (n % 2 != 0) //짝수일때
        {
            ret.push_back('7');
            n -= 3;
        }
        for (int i = 0 ; i < n / 2 ; ++i)
            ret.push_back('1');
    }
    return ret;
}

int main()
{

    dp[0] = "";
    dp[2] = "1";
    dp[3] = "7";
    dp[4] = "4";
    dp[5] = "2";
    dp[6] = "6";
    dp[7] = "8";

    addValue[0] = "";
    addValue[2] = "1";
    addValue[3] = "7";
    addValue[4] = "4";
    addValue[5] = "2";
    addValue[6] = "0";
    addValue[7] = "8";

    // 작은놈
    for (int i = 8; i < 101; ++i)
    {
        
        for (int j = 2; j < 8; ++j)
        {
            string left = dp[i - j];
            string right = addValue[j];
            if (i - j == 1)
                break;
            if (j == 2)
                dp[i] = left + right;
            else
            {
                if (dp[i].size() > left.size() + right.size())
                    dp[i] = left + right;
                else if (dp[i].size() == left.size() + right.size())
                {
                    if (dp[i] > left + right)
                        dp[i] = left + right;
                }
            }
        }
    }
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        cout << dp[n] << ' ' << bigSolve(n) << '\n';
    }
}