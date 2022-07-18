#include <iostream>
#include <set>
#include <queue>
#include <algorithm>
using namespace std;
int main(void)
{
    string s;
    string t;
    cin >> s;
    cin >> t;
    bool flag = false;
    while (t.size() >= s.size())
    {
        if (t == s)
        {
            flag = true;
            break;
        }
        char ch = t.back();
        if (ch == 'A')
            t.pop_back();
        else
        {
            t.pop_back();
            reverse(t.begin(), t.end());
        }
    }
    cout << flag;
}