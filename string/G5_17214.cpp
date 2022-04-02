#include <bits/stdc++.h>
using namespace std;
int main()
{
    string a;
    cin >> a;
    int sum = 0;
    bool flag = false;
    if (a == "0")
    {
        cout << "W";
        return 0;
    }
    for (int i = 0 ; i < a.size() ; ++i)
    {
        if (a[i] >= '0' && a[i] <= '9')
            sum =  sum * 10 + a[i] - '0';
        else if (a[i] =='x')
        {
            int value = sum / 2;
            sum = 0;
            if (value == 1 || value == -1)
                cout << "xx";
            else
                cout << value << "xx";
            flag = true;
        }
        else if (a[i] == '+')
        {
            cout << '+';
        }
        else if (a[i] == '-')
        {
            cout << '-';
        }
    }
    if (sum == 0)
    {
        
        flag = true;
    }
    else if (abs(sum) == 1)
    {
        cout  << "x";
        flag = true;
    }
    else
    {
        cout  << sum << "x";
        flag = true;
    }
    if (flag)
        cout << "+W";
    else
        cout << "W";
}