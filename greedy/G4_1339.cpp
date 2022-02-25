#include <bits/stdc++.h>
using namespace std;
int n;
int value[26];
int main()
{
    vector<string> v;
    cin >> n;
    string tmp;
    for (int i = 0 ; i < n ; ++i)
    {
        cin >> tmp;
        v.push_back(tmp);
    }
    
    for (int i = 0 ; i < n ; ++i)
    {
        for (int j = 0 ; j < v[i].size() ; ++j)
        {
            value[v[i][j] - 'A'] += pow(10, v[i].size() - j - 1);
        }
    }
    int mul = 9;
    int sum = 0;
    for (int i = 0 ; i < 9 ; ++i)
    {
        int maxValue = 0;
        int maxIndex = 0;
        for (int j = 0 ; j < 26 ; ++j)
        {
            if (maxValue < value[j])
            {
                maxIndex = j;
                maxValue = value[j];
            }
        }
        sum += maxValue * mul;
        mul--;
        value[maxIndex] = 0;
    }
    cout << sum;
}