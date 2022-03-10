#include<bits/stdc++.h>
using namespace std;
 
int arr[100];
int fib(int n)
{
    if (arr[n] != -1)
        return arr[n];
    cout << n <<'\n';
    if (n <= 1)
        return n;
    return arr[n] = fib(n-1) + fib(n-2);
}
 
int main ()
{
    
    for (int i = 0 ; i < 100 ; ++i)
        arr[i] = -1;
    int n = 9;
    cout << fib(n);
    return 0;
}