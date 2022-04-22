#include <bits/stdc++.h>

using namespace std;
bool compare(string a, string b)
{
    string tmp1 = a;
    string tmp2 = b;
    for (int i = 0 ; i < 4 ; ++i)
    {
        a += tmp1;
        b += tmp2;
    }
    return a.substr(0, 4) > b.substr(0, 4);
}
string solution(vector<int> numbers) {
    string answer = "";
    vector<string> convert;

    for (auto str : numbers)
        convert.push_back(to_string(str));
    sort(convert.begin(), convert.end(), compare);
    for (auto str : convert)
        answer += str;
    if (answer[0] == '0')
        answer = "0";
    return answer;
}