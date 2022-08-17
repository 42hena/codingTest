#include <iostream>
#include <vector>
using namespace std;


int main(void)
{
    int l = -1;
    int r = -1;
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0 ; i < n ; ++i)
        cin >> v[i];
    for (int i = 0 ; i < n ; ++i)
    {
        int total = 0;
        l = i;
        for (int j = i ; j < n ; ++j)
        {

            bool flag = true;
            for (int b = 0 ; b < 32 ; ++b)
            {
                int bit = (1 << b);
                if (!(k & bit) && (v[j] & bit))
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                total |= v[j];
                if (total == k)
                {
                    r = j;
                    cout << l + 1 << ' ' << r + 1;
                    return 0;
                }
            }
            else
            {
                i = j;
                break;
            }
        }
    }
    cout << -1;
}