#include <bits/stdc++.h>
using namespace std;
int cnt_recursive;
void fib_recursive(int n)
{
    cnt_recursive++;
    if (n = 1 or n = 2)
        return 1;
    return (fib(n - 1) + fib(n - 2));
}

int main()
{

}
fib(n) {
    
}
fibonacci(n) {
    f[1] <- f[2] <- 1;
    for i <- 3 to n
        f[i] <- f[i - 1] + f[i - 2];  # 코드2
    return f[n];
}