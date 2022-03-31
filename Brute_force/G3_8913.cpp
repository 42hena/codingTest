#include <bits/stdc++.h>
using namespace std;
int isEmpty(string str)
{
    int i = 0;
    int ans = 0;

    // 문자열 str이 ""라면 빈것이므로 참(true)
    if (str == "")
        return (1);

    // 문자 처음부터 본다
    while (i < str.size())
    {
        // 만약 지금 보는 문자와 다음 문자가 같다면
        if (str[i] == str[i + 1])
        {
            // 같은 지점의 끝을 j에 담을 예정
            int j = i;
            // 같은 지점의 끝을 구함
            while (str[j] == str[j + 1])
                j++;
            // 첫 지점 부터 i - 1지점 + (j + 1)지점부터 끝을 다음 재귀에 넣음
            ans |= isEmpty(str.substr(0, i) + str.substr(j + 1));
            //------------------------------ 이 부분이 없으면 시간 초과가 남
            if (ans)
                return ans;
            //------------------------------ 
            i = j;
        }
        i++;
    }
    return (ans);
}

int main()
{
    // testcase : t 
    int t;

    // testcase input
    cin >> t;

    // t번 돌기
    for (int i = 0 ; i < t ; ++i)
    {
        // string variable : s
        string s;
        // string input
        cin >> s;
        cout << isEmpty(s) << '\n';
    }
}