#include <functional>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main(void)
{
    int n, k;

    cin >> n >> k;
    vector<int> sensors(n);
    for (int i = 0 ; i < n ; ++i)
        cin >> sensors[i];
    sort(sensors.begin(), sensors.end());
    priority_queue<int, vector<int>, greater<int> > pq;

    int total = 0;
    for (int i = 0 ; i < n - 1 ; ++i)
        pq.push(sensors[i + 1] - sensors[i]);
    int size = n - k;
    while (!pq.empty() && size-- > 0)
    {
        total +=pq.top();
        pq.pop();
    }
    cout << total;
}