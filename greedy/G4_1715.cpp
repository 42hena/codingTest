#include <bits/stdc++.h>
using namespace std;
struct Data
{
    int num;
    bool operator<(const struct Data &copy) const
    {
        return num > copy.num;
    }
};
int n;
int main()
{
    cin >> n;
    priority_queue< int, vector<int>, greater<int> > pq;
    int num;
    for (int i = 0 ; i < n ; ++i)
    {
        cin >> num;
        pq.push(num);
    }
    int sum = 0;
    while (pq.size() != 1)
    {
        int tmp1 = pq.top();
        pq.pop();
        int tmp2 = pq.top();
        pq.pop();
        // cout << tmp1 << ' ' << tmp2 << '\n';
        int tmp = tmp1 + tmp2;
        sum += tmp;
        pq.push(tmp);
    }
    cout << sum;
}