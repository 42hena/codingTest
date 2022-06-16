#include <bits/stdc++.h>
using namespace std;

int win[101][101];
int lose[101][101];
#define MAX 1e9;
int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    int length = results.size();
    
    for (int i = 1 ; i <= n ; ++i)
    {
        for (int j = 1 ; j <= n ; ++j)
        {
            win[i][j] = 1e9;
            lose[i][j] = 1e9;
            if (i == j)
            {
                win[i][j] = 0;
                lose[i][j] = 0;
            }
        }
    }
    
    for (int i = 0 ; i < length ; ++i)
    {
        int v1 = results[i][0];
        int v2 = results[i][1];
        win[v1][v2] = 1;
        lose[v2][v1] = 1;
    }
    
    for (int k = 1 ; k <= n ; ++k)
    {
        for (int i = 1 ; i <= n ; ++i)
        {
            for (int j = 1 ; j <= n ; ++j)
            {
                win[i][j] = min(win[i][k] + win[k][j], win[i][j]);
                lose[i][j] = min(lose[i][k] + lose[k][j], lose[i][j]);
            }
        }   
    }
    
    for (int i = 1 ; i <= n ; ++i)
    {
        int cnt = 0;
        for (int j = 1 ; j <= n ; ++j)
        {
            if (win[i][j] != int(1e9) || lose[i][j] != int(1e9))
                cnt++;
        }
        if (cnt == n)
            answer++;
        cout << endl;
    }
    
    return answer;
}