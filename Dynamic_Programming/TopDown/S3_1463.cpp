#include <bits/stdc++.h>
using namespace std;
// n값의 범위 1 ~ 1e6
int cache[1000001];
int recursive(int num)
{
    // 원하고자 하는 값이 1이므로 종료 조건이 1일 경우이다.
    if (num == 1)
        return cache[1] = 0;
    
    // cache 값을 넣음
    int &ret = cache[num];
    
    // cache값이 있다면 더 보지 않고 return
    if (ret != -1)
        return ret;
    
    // -1 일 경우 
    ret = recursive(num - 1) + 1;

    // 3으로 나누어 질 경우
    if (num % 3 == 0)
        ret = min(recursive(num / 3) + 1, ret);
    // 2로 나누어 질 경우
    if (num % 2 == 0)
        ret = min(recursive(num / 2) + 1, ret);
    
    // 값 리턴
    return ret;
}

int main()
{
    int n;
    cin >> n;
    memset(cache, -1, sizeof(cache));
    cout << recursive(n);
}