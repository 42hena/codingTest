//https://www.acmicpc.net/problem/10828
//https://www.acmicpc.net/problem/10828
#include <bits/stdc++.h>
#include <string>
using namespace std;
#define endl '\n'

stack<char> s;
int main(void)
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    string bracket;
    cin >> bracket;
    for (int i = 0 ; i < bracket.size() ; ++i)
    {
        cout << bracket[i];
        if (bracket[i] == '(' || bracket[i] == '['){
            s.push(bracket[i]);
            cout << s.top();
        }
        else
        {
            int sum = 0;
            if (!s.size()){
                cout << 0 << endl;
                exit(0);
            }

            while (s.size())
            {
                char tmp = s.top();
                if ((bracket[i] == ')' && tmp == '[') || (bracket[i] == ']' && tmp == '(')){
                    cout << 0 << endl;
                    exit(0);
                }
                if (tmp == '(' || tmp == '[')
                {
                    if (tmp == '(')
                        sum *= 2;
                    else
                        sum *= 3;
                    break;
                }
                else
                    sum += stringstream(tmp);
                s.pop();
            }
            s.push(to_string(sum));
        }
    }
    int sum = 0;
    while (s.size())
    {
        string tmp = s.top();
        if (tmp == "(" || tmp == "["){
            cout << 0 << endl;
            exit(0);
        }
        sum += stringstream(tmp);
    }   
    cout << sum;
}

/*
#include <bits/stdc++.h>
#include <string>
using namespace std;
#define endl '\n'

stack<string> s;
int main(void)
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    string bracket;
    cin >> bracket;
    for (int i = 0 ; i < bracket.size() ; ++i)
    {
        cout << bracket[i];
        if (bracket[i] == '(' || bracket[i] == '['){
            s.push(""+bracket[i]);
            cout << s.top();
        }
        else
        {
            int sum = 0;
            if (!s.size()){
                cout << 0 << endl;
                exit(0);
            }

            while (s.size())
            {
                string tmp = s.top();
                if ((bracket[i] == ')' && tmp == "[") || (bracket[i] == ']' && tmp == "(")){
                    cout << 0 << endl;
                    exit(0);
                }
                if (tmp == "(" || tmp == "[")
                {
                    if (tmp == "(")
                        sum *= 2;
                    else
                        sum *= 3;
                    break;
                }
                else
                    sum += stringstream(tmp);
                s.pop();
            }
            s.push(to_string(sum));
        }
    }
    int sum = 0;
    while (s.size())
    {
        string tmp = s.top();
        if (tmp == "(" || tmp == "["){
            cout << 0 << endl;
            exit(0);
        }
        sum += stringstream(tmp);
    }   
    cout << sum;
}
*/