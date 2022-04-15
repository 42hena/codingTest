#include <bits/stdc++.h>
using namespace std;

// pq에 vector 시작점 끝점을 넣어서 미리 생성 가능

int solution(vector<int> scoville, int K) {
    priority_queue<int, vector<int>, greater<int> > pq(scoville.begin(), scoville.end());
    
    int answer = 0;
    while (pq.top() < K)
    {
        if (pq.size() == 1)
            return -1;
        int value = pq.top(); pq.pop();
        pq.push(value + pq.top() * 2);
        pq.pop();
        answer++;
    }
    return answer;
}