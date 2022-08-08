#include <bits/stdc++.h>
using namespace std;
bool origin[20][20];
bool state[20][20];
int minValue = 401;

void print(int n)
{
    for (int i = 0 ; i < n ; ++i)
    {
        for (int j = 0 ; j < n ; ++j)
        {
            cout << state[i][j] << ' ';
        }
        cout << '\n';
    }
}

void calculateCount(int n)
{
    int total = 0;
    for (int i = 0 ; i < n ; ++i)
    {
        int tCount = 0;
        for (int j = 0 ; j < n ; ++j)
        {
            if (state[i][j])
                tCount++;
        }
        total += min(tCount, n - tCount);
    }

    if (minValue > total)
        minValue = total;
}

int main()
{
    int n;
    cin >> n;
    char ch;
    for (int i = 0 ; i < n ; ++i)
        for (int j = 0 ; j < n ; ++j)
        {
            cin >> ch;
            if (ch == 'T')
                origin[i][j] = 1;
        }
    
    for (int i = 0 ; i < (1 << n) ; ++i)
    {
        memcpy(state, origin, sizeof(state));
        for (int j = 0 ; j < n ; ++j)
        {
            if (i & (1 << j))
                for (int row = 0 ; row < n ; ++row)
                {
                    state[row][j] = !state[row][j];
                }
        }
        // cout << "start\n";
        // print(n);
        // cout << "end\n\n";
        calculateCount(n);
    }
    cout << minValue;
}