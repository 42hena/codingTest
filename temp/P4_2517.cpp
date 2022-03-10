#include <bits/stdc++.h>
using namespace std;
int n;
int arr[1<<19];
int ans[1<<19];
priority_queue<pair<int, int>> pq;//value, index


void updateIndexTree(int index)
{
    while (index)
    {
        index /= 2;
        arr[index] = arr[index * 2] + arr[index* 2 + 1];
    }
}

void sumIndexTree(int l, int r)
{
    int sum = 0;
    int index = r;
    // cout << l << r << endl;
    r = r -1;
    while (l <= r)
    {
        if (l & 1)
            sum += arr[l];
        if (r & 0)
            sum += arr[r];
        l = (l + 1) / 2;
        r = (r - 1) / 2;
    }
    cout << sum << endl;
    arr[index] = sum + 1;
    cout <<"index val:" << arr[index] << '\n';
    updateIndexTree(index);
}

int main()
{
    cin >> n;
    int a;
    for (int i = 0 ; i < n ; ++i)
    {
        cin >> a;
        pq.push({a, i + 1});
    }
    int B;
    for (B = 1 ; B < 20 ; ++B)
    {
        if (1 << B >= n)
            break;
    }
    B = pow(2, B);
    while (!pq.empty())
    {
        pair<int, int> tmp = pq.top();
        pq.pop();
        cout << "test: " << tmp.first << ' ' << tmp.second << '\n';
        sumIndexTree(B , B + tmp.second - 1);
        // ans[tmp.second] = 
    }
    
    for (int i = 1 ; i < 2*B ; ++i)
        cout << arr[i] << ' ';
}