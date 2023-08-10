#include <iostream>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
int s;

int arr[400004];


void update(int index, int v)
{
    index += s;
    if (v > 0)
        arr[index] = 1;
    else if (v == 0)
        arr[index] = 0;
    else
        arr[index] = -1;

    while (index > 0)
    {
        index /= 2;
        arr[index] = arr[index * 2] * arr[index * 2 + 1];
    }
}

int GetValue(int l, int r, int nodeL, int nodeR, int node)
{
    if (r < nodeL || nodeR < l)
        return 1;
    if (l <= nodeL && nodeR <= r)
        return arr[node];
    
    int mid = (nodeL + nodeR) / 2;

    return GetValue(l, r, nodeL, mid, node * 2) * GetValue(l, r, mid + 1, nodeR, node * 2 + 1);
}


int main()
{
    fastio
    int n, m;
    while (cin >> n >> m)
    {
        s = 1;
        while (s < n)
            s <<= 1;

        for (int i = 0 ; i < n ; ++i)
        {
            int tmp;
            cin >> tmp;
            if (tmp > 0)
                arr[s + i] = 1;
            else if (tmp == 0)
                arr[s + i] = 0;
            else
                arr[s + i] = -1;
        }

        for (int i = s - 1 ; i > 0 ; --i)
            arr[i] = arr[i * 2] * arr[i * 2 + 1];

        for (int i = 0 ; i < m ; ++i)
        {
            char type;
            int a, b;
            cin >> type >> a >> b;
            if (type == 'C')
            {
                update(a - 1, b);
            }
            else
            {
                int ret = GetValue(a - 1, b - 1, 0, s - 1, 1);
                if (ret > 0)
                    cout << '+';
                else if (ret == 0)
                    cout << '0';
                else
                    cout << '-';
            }
        }
        cout << '\n';
    }
}