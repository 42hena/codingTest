#include <iostream>
#include <algorithm>
using namespace std;
int s = 1;
int arr[400004];

void update(int index, int value)
{
    index += s;
    arr[index] = value;

    while (index > 0)
    {
        index /= 2;
        arr[index] = min(arr[index * 2], arr[index * 2 + 1]);
    }
}

int GetMinValue(int l, int r, int nodeL, int nodeR, int node)
{
    if (r < nodeL || nodeR < l)
        return 1e9;
    if (l <= nodeL && nodeR <= r)
        return arr[node];

    int mid = (nodeL + nodeR) / 2;

    return min(GetMinValue(l, r, nodeL, mid, node * 2), GetMinValue(l, r, mid + 1, nodeR, node * 2 + 1));
}

int main()
{
    int n;
    scanf("%d", &n);

    while (s < n)
        s <<= 1;
    for (int i = 1 ; i < s * 2 ; ++i)
        arr[i] = 1e9;
    for (int  i = 0 ; i < n ; ++i)
        scanf("%d", &arr[s + i]);
    for (int i = s - 1 ; i > 0 ; --i)
        arr[i] = min(arr[i * 2], arr[i * 2 + 1]);

    int m;
    scanf("%d", &m);
    for (int  i = 0 ; i < m ; ++i)
    {
        int type;
        scanf("%d", &type);
        if (type == 1)
        {
            int index, v;
            scanf("%d %d", &index, &v);
            update(index - 1, v);
        }
        else
        {
            int start, end;
            scanf("%d %d", &start, &end);
            printf("%d\n", GetMinValue(start - 1, end - 1, 0, s - 1, 1));
        }
    }
}