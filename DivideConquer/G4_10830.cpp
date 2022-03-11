#include <bits/stdc++.h>
using namespace std;
int arr[5][5];
int answer[5][5];
int tmp[5][5];
int main()
{
    long long  n, b;
    cin >> n >> b;
    // fill(&answer[0][0], &answer[4][5], 1);
    for (int i = 0 ; i < n ; ++i)
        for (int j = 0 ; j < n ; ++j)
        {
            cin >> arr[i][j];
            if (i == j)
                answer[i][j] = 1;
        }

    long long cnt = 1;
    long long total = 0;
    while (b != total)
    {
        if (b & cnt)
        {
            // cout << "cnt:"<<cnt<< '\n';
            memset(tmp, 0, sizeof(tmp));
            for (int i = 0 ; i < n ; ++i)
            {
                for (int j = 0 ; j < n ;  ++j)
                {
                    long long sum = 0;
                    for (int k = 0 ; k < n ; ++k)
                    {
                        sum  =  (sum + answer[i][k] * arr[k][j]) %1000;
                    }
                    tmp[i][j] = sum % 1000;
                }
            }
            for (int i = 0 ; i < n ; ++i)
            {
                for (int j = 0 ; j < n ;  ++j)
                {
                    answer[i][j] = tmp[i][j];
                }
            }
            total += cnt;
        }
        cnt *= 2;
        memset(tmp, 0, sizeof(tmp));
        for (int i = 0 ; i < n ; ++i)
        {
            for (int j = 0 ; j < n ;  ++j)
            {
                long long sum = 0;
                for (int k = 0 ; k < n ; ++k)
                {
                    sum = (sum + arr[i][k] * arr[k][j]) % 1000;
                }
                tmp[i][j] = sum % 1000;
            }
        }
        for (int i = 0 ; i < n ; ++i)
        {
            for (int j = 0 ; j < n ;  ++j)
            {
                arr[i][j] = tmp[i][j];
            }
        }
    }
    for (int a = 0 ; a < n ; ++a)
    {
        for (int b = 0 ; b < n ;  ++b)
        {
            cout << answer[a][b] << ' ';
        }
        cout << "\n";
    }
}