#include <iostream>
#include <string>
#include <stack>
using namespace std;

#define MODs (1e9 + 7)
#define MAX_LEN 41
int minTree[200004];
int maxTree[200004];

int s = 1;
int GetMinValue(int l, int r, int nodeL, int nodeR, int node)
{
    if (r < nodeL || nodeR < l)
        return 1e6 + 1;
    if (l <= nodeL && nodeR <= r)
        return minTree[node];

    int mid = (nodeL + nodeR) / 2;

    return min(GetMinValue(l, r, nodeL, mid, node * 2), GetMinValue(l, r, mid + 1, nodeR, node * 2 + 1));
}

int GetMaxValue(int l, int r, int nodeL, int nodeR, int node)
{
    if (r < nodeL || nodeR < l)
        return 0;
    if (l <= nodeL && nodeR <= r)
        return maxTree[node];

    int mid = (nodeL + nodeR) / 2;

    return max(GetMaxValue(l, r, nodeL, mid, node * 2), GetMaxValue(l, r, mid + 1, nodeR, node * 2 + 1));
}

int main()
{
    int n, m;

    scanf("%d %d", &n, &m);

    while (s < n)
        s <<= 1;
    
    for (int i = 0 ; i < n ; ++i)
    {
        scanf("%d", &minTree[s + i]);
        maxTree[s + i] = minTree[s + i];
    }
    for (int i = n ; i < s ; ++i)
    {
        minTree[s + i] = 1e6 + 1;
    }

    
    // init
    for (int i = s - 1 ; i  > 0 ; --i)
    {
        minTree[i] = min(minTree[i * 2], minTree[i * 2 + 1]);
        maxTree[i] = max(maxTree[i * 2], maxTree[i * 2 + 1]);
    }


    // Query
    for (int i = 0 ; i < m ; ++i)
    {
        int start, end;
        scanf("%d %d", &start, &end);
        printf("%d\n", GetMaxValue(start - 1, end - 1, 0, s - 1, 1) - GetMinValue(start - 1, end - 1, 0, s - 1, 1));
    }
}
