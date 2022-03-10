#include <bits/stdc++.h>
using namespace std;
int num[16];
int recursive(int n)
{
    // cout << &n << '\n';
    if (n == 2)
        return 0;
    for (int i = 0 ; i < n - 1 ; ++i)
        num[i] = (num[i] + num[i + 1]) % 10;
    int a = recursive(n - 1);
    cout << a<< '\n';
}

int main()
{
    string a, b;
    cin >> a >> b;
    
    int j = 0;
    for (int i = 0 ; i < 8 ;++i){
        num[j] = a[i] - '0';
        ++j;
        num[j] = b[i] - '0';
        ++j;
    }
    
    recursive(16);
    if (num[0] == 0)
        cout << '0' << num[1];
    else
        cout << num[0] * 10 + num[1];
}