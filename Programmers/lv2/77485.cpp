// 행렬 테두리 회전하기
#include <bits/stdc++.h>

using namespace std;
int board[101][101];
vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    int cnt = 1;
    for (int i = 1 ; i < rows + 1 ; ++i)
        for (int j = 1 ; j < columns + 1 ; ++j)
            board[i][j] = cnt++;
    
    vector<int> answer;
    for (auto v : queries)
    {
        int ans = 1e9;
        int x1 = v[0];
        int y1 = v[1];
        int x2 = v[2];
        int y2 = v[3];
        int tmp = board[x1][y1];
        for (int i = x1 ; i < x2 ; ++i)
        {
            board[i][y1] = board[i + 1][y1];
            ans = min(ans, board[i][y1]);
        }
        for (int j = y1 ; j < y2 ; ++j)
        {
            board[x2][j] = board[x2][j + 1];
            ans = min(ans, board[x2][j]);
        }
        for (int i = x2 ; i > x1 ; --i)
        {
            board[i][y2] = board[i - 1][y2];
            ans = min(ans, board[i][y2]);
        }
        for (int j = y2 ; j > y1 ; --j)
        {
            board[x1][j] = board[x1][j - 1];
            ans = min(ans, board[x1][j]);
        }
        board[x1][y1 + 1] = tmp;
        ans = min(ans, tmp);
        
        answer.push_back(ans);
    }
    
    return answer;
}