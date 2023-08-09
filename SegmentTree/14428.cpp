#include <iostream>
using namespace std;

struct Data
{
    int value;
    int index;
};

Data arr[400004];
int s = 1;


void update(int index, int value)
{
    index += s;
    arr[index].value = value;

    while (index > 0)
    {
        index /= 2;
        
        if (arr[index * 2].value > arr[index * 2 + 1].value)
            arr[index] = arr[index * 2 + 1];
        else
            arr[index] = arr[index * 2];
    }
}

Data GetMinValue(int l, int r, int nodeL, int nodeR, int node)
{
    if (r < nodeL || nodeR < l)
    {
        Data tmp;
        tmp.value = 1e9 + 1;
        tmp.index = 1e9 + 1;
        return tmp;
    }
    if (l <= nodeL && nodeR <= r)
        return arr[node];
    
    int mid = (nodeL + nodeR) / 2;

    Data left = GetMinValue(l, r, nodeL, mid, node * 2);
    Data right = GetMinValue(l, r, mid + 1, nodeR, node * 2 + 1);

    if (left.value > right.value)
    {
        return right;
    }
    else
    {
        return left;
    }
}
void print()
{
    for (int i = 1 ; i < 2 * s ; ++i)
    {
        printf("[v:%d index:%d] ", arr[i].value, arr[i].index);
    }
    printf("\n");
}

int main()
{
    int n;
    scanf("%d", &n);
    
    while (s < n)
        s <<= 1;

    for (int i = 0 ; i < s * 2 ; ++i)
    {
        arr[i + s].value = 1e9;
        arr[i + s].index = i + 1;
    }

    for (int i = 0 ; i < n ; ++i)
    {
        scanf("%d", &arr[i + s].value);
    }

    for (int i = s - 1 ; i > 0 ; --i)
    {
        if (arr[i * 2].value > arr[i * 2 + 1].value)
        {
            arr[i].value = arr[i * 2 + 1].value;
            arr[i].index = arr[i * 2 + 1].index;
        }
        else
        {
            arr[i].value = arr[i * 2].value;
            arr[i].index = arr[i * 2].index;
        }
    }

    int m;
    scanf("%d", &m);
    for (int i = 0 ; i < m ; ++i)
    {
        int type;

        scanf("%d", &type);
        if (type == 1)
        {
            int index, value;
            scanf("%d %d", &index, &value);
            update(index - 1, value);
        }
        else
        {
            int start, end;
            scanf("%d %d", &start, &end);
            Data v = GetMinValue(start - 1, end - 1, 0, s - 1, 1);
            printf("%d\n", v.index);
        }
    }

}