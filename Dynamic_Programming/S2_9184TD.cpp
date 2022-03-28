#include <iostream>
#include <cstring>
using namespace std;
int arr[51][51][51];
int recursive(int a, int b, int c)
{
    
    if (a <= 0 or b <= 0 or c <= 0)
        return arr[0][0][0] = 1;
    int &ret = arr[a][b][c];
    if (ret != -1)
        return ret;
    if (a > 20 or b > 20 or c > 20)
        return arr[a][b][c] = recursive(20, 20, 20);

    if (a < b and b < c)
        return ret = recursive(a, b, c-1) + recursive(a, b-1, c-1) - recursive(a, b-1, c);
    else
        return ret = recursive(a-1, b, c) + recursive(a-1, b-1, c) + recursive(a-1, b, c-1) - recursive(a-1, b-1, c-1);
}

int main()
{
    while (1)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == - 1 && a == b && a == c)
            break;
        memset(arr, -1, sizeof(arr));
        cout << "w(" << a << ", " << b << ", " << c << ") = " << recursive(a, b, c) << '\n';
    }
}
