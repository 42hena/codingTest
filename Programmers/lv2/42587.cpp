#include <bits/stdc++.h>

using namespace std;
struct Data
{
    int index;
    int priority;
    bool operator<(const Data &copy) const
    {
        return priority < copy.priority;
    }
};

int solution(vector<int> priorities, int location) 
{
    deque<Data> dq;
    for (int i = 0 ; i < priorities.size() ; ++i)
        dq.push_back({i, priorities[i]});
    int answer = 0;
    
    while (!dq.empty())
    {
        bool bigFlag = false;
        Data tmp = dq.front();
        dq.pop_front();
        auto ret = max_element(dq.begin(), dq.end());
        if (tmp.priority >= ret->priority)
        {
            answer++;
            if (tmp.index == location)
                break;
        }
        else
            dq.push_back(tmp);    
    }
    return answer;
}