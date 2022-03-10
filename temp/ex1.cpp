#include <bits/stdc++.h>
using namespace std;
int n = 3;
int m = 4;
int minValue = 100000000;
int cost[][4] = {1, 3, 5, 8, 4, 2, 1, 7, 4, 3, 2, 3};
void recursive(int i, int j, int total)
{
    total += cost[i][j];
    if (i == 2 && j == 3)
    {
        if (minValue > total)
            minValue = total;
        cout << i << ' ' << j << ' ' << total << '\n';
    }
    if (i + 1 < n)
        recursive(i + 1, j, total);
    if (j + 1 < m)
        recursive(i, j + 1, total);
}

int main()
{
    

    for (int i = 0 ; i < 3 ; ++i)
    {
        for (int j = 0 ; j < 4 ; ++j)
            cout << cost[i][j] << ' ';
        cout << '\n';
    }
    recursive(0, 0, 0);
    cout << "answer: " << minValue;
}