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
int main()
{
    cin >> g >> p;
    vector<int> planes(p);
    for (int i = 0 ; i < p ; ++i)   cin >> planes[i];    // 입력
    for (int i = 0 ; i <= g ; ++i)  gate[i] = i;
    int cnt = 0;
    for (int i = 0 ; i < p ; ++i)
    {
        int plane = planes[i];
        int ret = findParentAndChange(plane);
        if (ret == 0)
            break;
        findParent(plane);
        cnt++;
    }
    cout << cnt;
}