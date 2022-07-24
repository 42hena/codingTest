#include <bits/stdc++.h>
using namespace std;

bool compare(string a, string b)
{
    return a + b > b + a;
}

int main()
{
    int n;
    cin >> n;
    vector<string> numbers(n);
    for (int i = 0 ; i < n ; ++i)
        cin >> numbers[i];
    
    sort(numbers.begin(), numbers.end(),compare);
    string ans;
    for (auto x : numbers)
    {
        ans += x;
    }
    if (ans.size() > 1)
    {
        while (ans.size() > 1)
        {
            if (ans.front() == '0')
                ans.erase(ans.begin());
            else
                break;
        }
    }
    cout << ans;
}