#include <iostream>
using namespace std;
long long arr[500000];
long long tmp[500000];
int n;
long long GetMaxSwap(int l, int r)
{
    if (l == r)
    {
        // printf("%d\n", l);
        return 0;
    }
    int mid = (l + r) / 2;
    long long ret = GetMaxSwap(l, mid) + GetMaxSwap(mid + 1, r);
    // printf("l:%d m:%d r:%d\n", l, mid, r);
    int i = l;
    int j = mid + 1;
    int idx = i;
    while (i <= mid && j <= r)
    {
        if (arr[i] <= arr[j])
        {
            tmp[idx] = arr[i];
            i++;
        }
        else
        {
            // printf("value: %d j:%d idx:%d\n", arr[j], j, idx);
            tmp[idx] = arr[j];
            ret += j - idx;
            j++;
            // printf("ret:%d\n",ret);
        }
        idx++;   
    }
    while (i <= mid)
    {
        tmp[idx] = arr[i];
        idx++;
        i++;
    }
    while (j <= r)
    {
        tmp[idx] = arr[j];
        idx++;
        j++;
    }

    for (int fi = l ; fi <= r ; ++fi)
    {
        arr[fi] = tmp[fi];
    }
    // printf("l:%d ~ r:%d\n", l, r);
    // for (int i = l ; i <= r ; ++i)
    //     printf(" %d", arr[i]);
    // printf("\n");

    return ret;
}

int main()
{
    
    scanf("%d", &n);

    for (int i = 0 ; i < n ; ++i)
    {
        scanf("%d", &arr[i]);
    }

    printf("%lld\n", GetMaxSwap(0, n - 1));
}