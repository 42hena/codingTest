#include <stdio.h>

void printTable(int n)
{
    for (int i = 1 ; i <= 10 ; ++i)
    {
        printf("%d * %d = %d\n", n, i, (n * i));
    }
}

void gugudan(int n)
{
    if (n == 10)
        return ;
    printTable(n);
    gugudan(n + 1);   
}
int main()
{
    gugudan(2);
}