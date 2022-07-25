#include <functional>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    long long n;
    cin >> n;
    vector<long long> win(n);
    long long total = 0;
    bool flag = true;
    for (int i = 0 ; i < n ; ++i)
    {
        cin >> win[i];
    }
    sort(win.begin(), win.end());
    for (int i = 0 ; i < n ; ++i)
    {
        total += win[i];
        if (total < i * (i + 1) / 2)
            flag = false;
    }
    if (total != (n - 1) * n / 2)
        flag = false;
    cout << (flag ? 1 : -1) << '\n'; 
}