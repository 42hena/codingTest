#include <bits/stdc++.h>
using namespace std;

vector<int> solution(int n, int s)
{
    vector<int> answer;
    // 모든 값들이 1보다 작을 경우는 예외 처리
    if (n > s)
    {
        answer.push_back(-1);
        return answer; // return [-1]
    }
    int share = s / n;
    int remainder = s % n;
    int index = n - remainder;
    for (int i = 0; i < n; ++i)
    {
        if (i < index)
            answer.push_back(share);
        else
            answer.push_back(share + 1);
    }
    return answer;
}