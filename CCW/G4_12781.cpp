#include <bits/stdc++.h>
using namespace std;
int main()
{
    int x1, y1, x2, y2, x3, y3, x4, y4;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

    long long ccw1 = x1 * y2 + x2 * y3 + x3 * y1 - (x2 * y1 + x3 * y2 + x1 * y3);
    long long ccw2 = x1 * y2 + x2 * y4 + x4 * y1 - (x2 * y1 + x4 * y2 + x1 * y4);
    if (ccw1 * ccw2 < 0)
        cout << 1;
    else
        cout << 0;
    //x1 x2 x3 x4
    //y1 y2 y3 y4
}