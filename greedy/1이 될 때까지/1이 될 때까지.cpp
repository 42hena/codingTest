#include <bits/stdc++.h>

using namespace std;

int n, k;
int result;

int main(void){
    cin >> n >> k;
    while (true){
        // N이 K로 나누어 떨어지는 수가 될 때까지 빼기
        int target = (n / k) * k;
        result += (n / k) * k;
        n = target
        // N이 K보다 작을 때 (더 이상 나눌 수 없을 때) 반복문 탈출
        if (n < k) break;
        // K로 나누기
        result++;
        n /= k
    }
    // 마지막으로 남은 수에 대하여 1씩 빼기
    result += (n - 1);
    cout << result << '\n';
}