#include <iostream>
#include <algorithm>
int arr[101][101];
#define INF  1000000
int main()
{
    int n;
    std::cin >> n;
    // std::fill(&arr[0][0], &arr[n-1][n], INF);
    for (int i = 1 ; i <= n ; i++)
    {
        for (int j = 1 ; j <= n ; j++){
            int num;
            std::cin >> num;
            // if (i == j)
            //     arr[i][j] = 0;
            
            if (num)
                arr[i][j] = 0;
            else
                arr[i][j] = INF;
        }
    }

    for (int k = 1 ; k <= n ; k++)
    {
        for (int i = 1 ; i <= n ; i++)
        {
            for (int j = 1 ; j <= n ; j++){
                arr[i][j] = std::min(arr[i][j], arr[i][k] + arr[k][j]);            
            }
        }
    }
    
    for (int i = 1 ; i <= n ; i++)
    {
        for (int j = 1 ; j <= n ; j++){
            if (!arr[i][j])
                std::cout << 1 << ' ';
            else
                std::cout << 0 << ' ';
        }
        std::cout << '\n';
    }

}