#include <bits/stdc++.h>
using namespace std;
int arr[1025][1025];
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
    {
        for (int j = 1 ; j <= n ; ++j)
        {
            cin >> arr[i][j];
        }
    }
        
    for (int i = 1 ; i <= n ; ++i){
        for (int j = 1 ; j <= n ; ++j)
        {
            arr[i][j] += arr[i][j - 1];
        }
    }

    for (int j = 1 ; j <= n ; ++j){
        for (int i = 1 ; i <= n ; ++i)
        {
            arr[i][j] += arr[i - 1][j];
        }
    }

    int a, b, c, d;
    for (int i = 0 ; i < m ; ++i)
    {
        cin >> a >> b >> c >> d;
        cout << arr[c][d] - arr[a - 1][d] - arr[c][b - 1] + arr[a - 1][b - 1] << '\n';
    }
}