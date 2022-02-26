#include <iostream>
using namespace std;
int main()
{
    int a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;
    int ans = 0;
    if (a <= 0)
    {
        if (b < 0)
        {
            ans = abs(b - a) * c;
        }
        else
            ans = abs(a) * c + d + b * e;    
    }
    else
    {
        ans = (b-a) * e;
    }
    cout << ans;       
}