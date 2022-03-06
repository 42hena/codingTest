#include <bits/stdc++.h>
using namespace std;
int l, c;
set<string> s;
vector<char> ch;
bool visited[15];
void recursive(int cnt, vector<char> &arr, int a, int b)
{
    if (a + b == l)
    {
        if (a >= 1 && b >= 2)
        {   
            string tmp = "";
            for (auto i : arr)
                tmp.push_back(i);
            s.insert(tmp);
        }
        return ;
    }
    // cout << cnt << '\n';
    for (int i = cnt ; i < c ; ++i)
    {
        if (!visited[i])
        {
            visited[i] = true;
            arr.push_back(ch[i]);
            if (ch[i] == 'a' || ch[i] == 'e' || ch[i] == 'i' || ch[i] == 'o' || ch[i] == 'u')
                recursive(i + 1, arr, a + 1, b);
            else
                recursive(i + 1, arr, a, b + 1);
            arr.pop_back();
            visited[i] = false;
        }
    }
}

int main()
{
    cin >> l >> c;
    char a;
    for (int i = 0 ; i < c ; ++i)
    {
        cin >> a;
        ch.push_back(a);
    }
    sort(ch.begin(), ch.end());
    vector<char> arr;
    recursive(0, arr, 0, 0);
    for (auto i : s)
        cout << i << '\n';
}