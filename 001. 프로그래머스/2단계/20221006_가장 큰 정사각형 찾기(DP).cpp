#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print(vector<vector<int>> &board) {
 cout << endl;
    int h = board.size();
    int w = board[0].size();
     for(int i=0; i < h; i++) {
         for(int j=0; j < w; j++)
             cout << board[i][j] << " ";
         cout << endl;
     }
 cout << endl;
}

int solution(vector<vector<int>> board)
{
    int answer = 1;
    int maxt = 0;
    int h = board.size();
    int w = board[0].size();
    print(board);
    for(int i = 1; i < h; i++)
    {
        for(int j = 1; j < w; j++)
        {
            // i, j 기준으로 -방향 좌, 우, 대각 방향의 값이 0이면 skip
            if (board[i][j] == 0 || board[i-1][j-1] == 0 || board[i-1][j] == 0 || board[i][j-1] == 0)
                continue;
            
            // 기준위치에서 -방향 대각, 상, 좌 중에서 제일 작은값 pick
            int t = board[i-1][j-1];
            t = min(t, board[i][j-1]);
            t = min(t, board[i-1][j]);
            // 기준위치 = 작은값 + 1
            board[i][j] = t + 1;
            
            // maxt와 비교해서 높은값 keep
            maxt = max(maxt, board[i][j]);
        }
        
        print(board);
    }
    
    cout << maxt << endl;
    
    // [[0, 1, 1, 0],[0, 0, 0, 0],[0, 0, 0, 0],[0, 0, 0, 0]]
    // [[0, 0, 0, 0],[1, 0, 0, 0],[1, 0, 0, 0],[0, 0, 0, 0]]
    // 0행, 0열에만 값이 있는 경우 예외처리
    for(int i=0; i<h; i++)
    {
        maxt = max(maxt, board[i][0]);
        //cout << board[i][0] << endl ;
    }
    //cout << endl << "===" << endl;
    for(int j=0; j<w; j++)
    {
        maxt = max(maxt, board[0][j]);
        //cout << board[0][j] << " " ;
    }
    
    //print(board);
    return maxt * maxt;
}