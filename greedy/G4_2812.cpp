#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    string number;
    cin >> number;
    // stack<char> s;
    vector<char> s;
    int i = 0;
    while (i < n)
    {
        if (s.empty() || s.back() >= number[i] || k == 0)
            s.push_back(number[i]);
        else
        {
            while (!s.empty() && s.back() < number[i] && k > 0)
            {
                s.pop_back();
                k--;
            }
            s.push_back(number[i]);
        }
        ++i;
    }
    while (k--)
        s.pop_back();
    reverse(s.begin(), s.end());
    
    while (!s.empty())
    {
        cout << s.back();
        s.pop_back();
    }
}