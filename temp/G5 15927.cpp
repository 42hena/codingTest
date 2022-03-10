#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    cin >> str;
    
    int size = str.size();
    bool alpha[26];
    bool flag = true;
    memset(alpha, false, 26);

    for (int i = 0 ; i < size ; ++i){
        alpha[str[i] - 'A'] = true;
        if (str[i] != str[size - 1 - i]){
            flag = false;
            break;
        }
    }
    if (!flag)
        cout << size;
    else{
        int cnt = 0;
        for (int i = 0 ; i < 26 ; ++i){
            if (alpha[i])
                ++cnt;
        }
        cnt > 1 ? cout << size -1 : cout << -1;
    }
}