#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    vector<int> v(n);
    for (int i = 0 ; i < n ; ++i)
        scanf("%d", &v[i]);
    sort(v.begin(), v.end());
    priority_queue<int> pq;
    for (int i = 0 ; i < n - 1 ; ++i)
        pq.push(v[i + 1] - v[i]);
    int ans = k;
    k -= 1;
    while (!pq.empty() && k--)
        pq.pop();
    while (!pq.empty())
    {
        ans += pq.top();
        pq.pop();
    }
    printf("%d", ans);
}