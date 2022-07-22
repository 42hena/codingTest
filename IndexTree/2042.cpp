#include <bits/stdc++.h>
using namespace std;

#define MAXK 21
int B;

long long IDT[1 << MAXK];

void initIndexTree()
{
    for (int i = B - 1 ; i > 0 ; --i)
    {
        IDT[i] = IDT[i<<1] + IDT[(i<<1) | 1];
    }
}

void update(int p, long long v)
{
    p += (B-1);
    IDT[p] = v;
    while(p >>= 1)
    {
        IDT[p] = IDT[p<<1] + IDT[(p<<1)|1];
    }
}

long long lgsum(int l, int r)
{
    long long total = 0;
    l += (B - 1); r += (B - 1);
    while (l <= r)
    {
        if ((l & 1) == 1) total += IDT[l];
        if ((r & 1) == 0) total += IDT[r];

        l = (l + 1) >> 1;
        r = (r - 1) >> 1;
    }
    return total;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, k;

    cin >> n >> m >> k;

    for(B = 1 ; B < n ; B <<= 1)
        ;

    for (int i = B ; i < B + n ; ++i)
        cin >> IDT[i];
    initIndexTree();

    int a, b;
    long long c;
    for (int i = 0 ; i < m + k ; ++i)
    {
        cin >> a >> b >> c;
        if (a == 1)
            update(b, c);
        else
            cout << lgsum(b, c) << '\n';
    }
    
}