#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    bool visit[m][n];
    int cnt;
    do{
        cnt = 0;
        for (int i = 0 ; i < m ; ++i)
        {
            for (int j = 0 ; j < n ; ++j)
            {
                   visit[i][j] = false;
            }
        }
        for (int i = 0 ; i < m - 1 ; ++i)
        {
            for (int j = 0 ; j < n - 1 ; ++j)
            {
                if ( board[i][j] !='0' && board[i][j] == board[i][j + 1] &&  board[i][j + 1] == board[i + 1][j] &&  board[i + 1][j] == board[i + 1][j + 1]){
                    visit[i][j] = true;
                    visit[i + 1][j] = true;
                    visit[i][j + 1] = true;
                    visit[i + 1][j + 1] = true;
                    cnt ++;
                }

            }
        }
        for (int i = 0 ; i < m; ++i)
        {
            for (int j = 0 ; j < n; ++j)
            {
                if (visit[i][j] == true){
                    board[i][j] = '0';
                    answer++;
                    for (int k = i - 1 ; k >= 0 ; --k)
                    {
                        board[k + 1][j] = board[k][j];
                    }
                    board[0][j] = '0';
                }
            }
        }
    }while (cnt > 0);
    return answer;
    
}