// [카카오 인턴] 보석 쇼핑
// 투포인터 문제이나 dq로 마저 풀어보기
#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer(2);
    set<string> s;
    for (auto item : gems)
        s.insert(item);
    int gemsKindNum = s.size();
    
    int i = 0;
    int j = 0;
    // s.clear();
    int minValue = 100000;
    map<string, int> m;
    while (j < gems.size())
    {
        m[gems[j]]++;
        
        while (m.size() == gemsKindNum)
        {
            if (j - i + 1 < minValue){
                minValue = j - i + 1;
                answer[0] = i + 1;
                answer[1] = j + 1;
            }
            m[gems[i]]--;
            if (m[gems[i]] == 0)
                m.erase(gems[i]);
            ++i;
        }
        // cout << i << ' ' << j << '\n';
        j++;
    }
    // cout << answer[0] << answer[1] << '\n';
    return answer;
}