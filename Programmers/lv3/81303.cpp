#include <bits/stdc++.h>

using namespace std;

string solution(int n, int k, vector<string> cmd) {
    string answer(n, 'X');
    
    set<int> table;
    stack<int> record;
    for (int i = 0 ; i < n ; ++i) table.insert(i);
    auto cur = table.find(k);
    
    for (string s : cmd)
    {
        cout << "cur" << *cur << '\n';
        if (s[0] == 'U' || s[0] == 'D')
        {
            int x = stoi(s.substr(2));
            if (s[0] == 'U') cur = prev(cur, x);
            else cur = next(cur, x);
        }
        else if (s[0] == 'C')
        {
            record.push(*cur);
            cur = table.erase(cur);
            if (cur == table.end()) cur = prev(cur);
        }
        else if (s[0] == 'Z')
        {
            table.insert(record.top());
            record.pop();
        }
    }
    for (int i : table) answer[i] = 'O';
    return answer;
}