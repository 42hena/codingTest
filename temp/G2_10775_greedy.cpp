#include <bits/stdc++.h>
using namespace std;

int gate[100001];

int g, p;
int findParentAndChange(int p)
{
    if (p ==  gate[p]) {
        gate[p] = p - 1;
        return p;
    }
    return gate[p] = findParentAndChange(gate[p]);
}
int findParent(int p)
{
    if (p ==  gate[p]) {
        return p;
    }
    return gate[p] = findParent(gate[p]);
}
bool visited[100001];
int main()
{
    cin >> g >> p;
    vector<int> planes(p);
    for (int i = 0 ; i < p ; ++i)   cin >> planes[i];    // 입력
    for (int i = 0 ; i <= g ; ++i)  gate[i] = i;
    int cnt = 0;
    time_t start = time(NULL), end;
    visited[0] = true;
    for (int i = 0 ; i < p ; ++i)
    {
        int plane = planes[i];
        bool flag = false;
        for (int j = gate[plane] ; j >= 0 ; j--)
        {
            if (!visited[j])
            {   
                visited[j] = true;
                flag = true;
                gate[plane] = j - 1;
                break;
            }
        }
        for (int j = 1 ; j <= g ; ++j)
            cout << gate[j] << ' ';
        cout << '\n';
        if (!flag)
            break;
        cnt++;
    }
    
    cout << cnt << '\n';
    end = time(NULL);
    printf("%f", (double)(end - start));
}