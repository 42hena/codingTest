#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;  cin >> n;
    vector<int> v(n);
    vector<int> memory;
    for (int i = 0 ; i < n ; ++i)
        cin >> v[i];
    int s;  cin >> s;
    int count = 0;
    while (s > 0 && !v.empty())
    {
        // cout << "i: " << i << ' ';
        int maxIndex = 0;
        int i, j;
        for (i = 0, j = 0 ; j < v.size() ; j++)
        {
            if (j - i <= s)
            {
                if (v[maxIndex] < v[j])
                    maxIndex = j;
            }
            else
                break;
        }
        memory.push_back(v[maxIndex]);
        v.erase(v.begin() + maxIndex);
        s -= (maxIndex) - i;
        count++;
        // cout << s << '\n';
    }
    for (int i = 0 ; i < v.size() ; ++i)
        memory.push_back(v[i]);
    for (int i = 0 ; i < memory.size() ; ++i)
        cout << memory[i] << ' ';
}