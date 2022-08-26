#include <iostream>

using namespace std;

int main()
{
    long long a, b;
    cin >> a >> b;
    
    
    long long total = a + b;
    long long tmp = 1;
    long long i = 1; 
    while (true)
    {
        if (i * (i + 1) / 2 <= total)
            tmp = i;
        else
            break;
        ++i;
    }
    if (tmp * (tmp + 1)/ 2 != total)
    {
        cout << -1;
        return 0;
    }
    int cnt = 0;
    while (a)
    {
        if (a > tmp)
        {
            a -= tmp;
            tmp--;
        }
        else {
            tmp = a;
            a -= tmp;
            tmp--;
        }
        cnt++;
    }
    cout << cnt;
}