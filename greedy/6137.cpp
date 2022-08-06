#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string s;
    char ch;
    for (int i = 0 ; i < n ; ++i)
    {
        cin >> ch;
        s.push_back(ch);
    }

    string t = "";
    int i = 0;
    int j = s.size() - 1;
    while (i <= j)
    {
        
        if (s[i] < s[j])
        {
            t.push_back(s[i]);
            ++i;
        }
        else if (s[i] > s[j])
        {
            t.push_back(s[j]);
            --j;
        }
        else
        {
            bool flag = true;// true 앞 false 뒤
            int index = 1;
            for (; i + index < j - index ; ++index)
            {
                if (s[i + index] != s[j - index])
                    break ;
            }
            if (s[i + index] >= s[j - index])
                flag = false;
            if (flag)
            {
                t.push_back(s[i]);
                ++i;
            }
            else
            {
                t.push_back(s[j]);
                --j;
            }
        }
    }
    for (int i = 0 ; i < t.size() ; ++i)
    {
        cout << t[i];
        if ((i + 1) % 80 == 0)
            cout << '\n';
    }
}