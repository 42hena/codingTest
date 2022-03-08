#include <bits/stdc++.h>
using namespace std;
set<int> s;
vector<int> v;
vector<int> arr;
int len;
bool visited[6];
int minValue;
int n, m;
int maxSize;
void recursive(int arrayLength, int wantLength)
{
    if (wantLength == 0)
        return ;
    if (arrayLength == wantLength)
    {
        // cout<< "count" << count <<'\n';
        int sum = 0;
        for (int i = 0 ; i < arrayLength ; ++i)
            sum = sum * 10 + arr[i];
        if (minValue > wantLength + abs(n - sum))
            minValue = wantLength + abs(n - sum);
        return ;
    }
    for (int i = 0 ; i < len ; ++i)
    {
        arr.push_back(v[i]);
        recursive(arrayLength + 1, wantLength);
        arr.pop_back();
    }
}

int main()
{
    
    cin >> n >> m;
    for (int i = 0 ; i < 10 ; ++i)
        s.insert(i);
    int num;
    for (int i = 0 ; i < m ; ++i)
    {
        cin >> num;
        auto iter = s.find(num);
        if (iter != s.end())
            s.erase(iter);
    }
    for (auto i : s)
        v.push_back(i);
    int copyN = n;
    minValue = abs(100 - n);
    while (copyN){
        copyN /= 10;
        maxSize++;
    }
    if (n == 0)
        maxSize = 1;
    len = v.size();
    recursive(0, maxSize + 1);
    recursive(0, maxSize);
    recursive(0, maxSize - 1);
    cout << minValue;   
}