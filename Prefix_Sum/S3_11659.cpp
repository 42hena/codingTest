#include <bits/stdc++.h>
using namespace std;
int arr[100001];
void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}
int main()
{
    fastIO();
    int n, m;

    cin >> n >> m;
    for (int i = 1 ; i <= n ; ++i)
        cin >> arr[i];
    for (int i = 1 ; i <= n ; ++i)
        arr[i] += arr[i - 1];
    int a, b;
    for (int i = 0 ; i < m ; ++i){
        cin >> a >> b;
        cout << arr[b] - arr[a - 1] << '\n';
    }
}