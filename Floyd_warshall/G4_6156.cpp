#include <bits/stdc++.h>
using namespace std;
int n, m;
int pathrank[101][101];
int pathreverserank[101][101];
#define FOR(I, E) for (int I = 0 ; I < E ; ++I)
#define FORO(I, E) for (int I = 1 ; I < E ; ++I)
const int INF = 1e9;
void init()
{
    FOR(i, n + 1)
        FOR(j, n + 1)
        {
            if (i == j)
            {
                pathrank[i][j] = 0;
                pathreverserank[i][j] = 0;
            }
            else
            {
                pathrank[i][j] = INF;
                pathreverserank[i][j] = INF;
            }
        }
}
int main()
{
    cin >> n >> m;
    init();
    int v1, v2, w;
    FOR(i, m)   
    {
        cin >> v1 >> v2;
        pathrank[v1][v2] = 1;
        pathreverserank[v2][v1] = 1;
    }
    
    FORO(k, n + 1)
        FORO(i, n + 1)
            FORO(j, n + 1)
            {
                pathrank[i][j] = min(pathrank[i][j], pathrank[i][k] + pathrank[k][j]);
                pathreverserank[i][j] = min(pathreverserank[i][j], pathreverserank[i][k] + pathreverserank[k][j]);
            }
    int count = 0;
    FORO(i, n + 1)
    {
        bool flag = true;
        FORO(j, n + 1)
        {
            if (pathrank[i][j] == INF &&  pathreverserank[i][j] == INF)
                flag = false;
        }
        if (flag)
            count++;
    }
    cout << count;
}