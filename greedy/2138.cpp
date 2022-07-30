#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string option1, option2;
    string ans;
    cin >> option1 >> ans;
    
    int cnt1 = 0, cnt2 = 1;
    option2 = option1;
    option2[0] == '1' ? option2[0] = '0' : option2[0] = '1';
    option2[1] == '1' ? option2[1] = '0' : option2[1] = '1';

    for (int i = 1 ; i < n ; ++i)
    {
        if (option1[i - 1] == ans[i - 1])
            continue;
        if (i != n - 1)
        {
            option1[i - 1] == '1' ? option1[i - 1] = '0' : option1[i - 1] = '1';
            option1[i] == '1' ? option1[i] = '0' : option1[i] = '1';
            option1[i + 1] == '1' ? option1[i + 1] = '0' : option1[i + 1] = '1';
        }
        else
        {
            option1[i - 1] == '1' ? option1[i - 1] = '0' : option1[i - 1] = '1';
            option1[i] == '1' ? option1[i] = '0' : option1[i] = '1';
        }
        cnt1++;
    }
    if (option1 == ans)
    {
        cout << cnt1 << '\n';
        return 0;
    }
    for (int i = 1 ; i < n ; ++i)
    {
        if (option2[i - 1] == ans[i - 1])
            continue;
        if (i != n - 1)
        {
            option2[i - 1] == '1' ? option2[i - 1] = '0' : option2[i - 1] = '1';
            option2[i] == '1' ? option2[i] = '0' : option2[i] = '1';
            option2[i + 1] == '1' ? option2[i + 1] = '0' : option2[i + 1] = '1';
        }
        else
        {
            option2[i - 1] == '1' ? option2[i - 1] = '0' : option2[i - 1] = '1';
            option2[i] == '1' ? option2[i] = '0' : option2[i] = '1';
        }
        cnt2++;
    }
    if (option2 == ans)
    {
        
        cout << cnt2 << '\n';
        return 0;
    }
    else
        cout << -1 << '\n';
}
