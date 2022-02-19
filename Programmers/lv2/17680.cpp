#include <bits/stdc++.h>
using namespace std;
 
int solution(int cacheSize, vector<string> cities) {
 
    int answer = 0;
    deque<string> cache;
    for (auto city : cities)
    {
        for (int i = 0; i < city.length(); i++)
            city[i] = tolower(city[i]);
        bool flags = false;
        int index = 0;
        for (index = 0; index < cache.size(); index++) {
            if (cache[index] == city) {
                flags = true;
                break;
            }
        }
        cache.push_back(city);
        if (flags) {
            cache.erase(cache.begin() + index);
            answer += 1;
        }
        else {
            if (cache.size() > cacheSize) {
                cache.pop_front();
            }
            answer += 5;
        }
    }
    return answer;
}