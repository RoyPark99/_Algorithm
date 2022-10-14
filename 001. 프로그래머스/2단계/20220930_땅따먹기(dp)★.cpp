#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> land)
{
    // 현재 행의 이전행에서 같은 열이 아닌 값중에 최대값을 찾고 누적시킨다.
    int answer = 0;
    vector<vector<int>> dp(land.size(), vector<int>(4));
    
    // dp에 첫 행 저장
    for(int i = 0; i < 4; i++)
        dp[0][i] = land[0][i];
    
    // -> 방향으로 순회
    for(int i = 1; i < land.size(); i++)
    {
        for(int j = 0; j < 4; j++)
        {
            int max = 0;
            for(int k = 0; k < 4; k++)
            {
                // 이전열과 연속은 불가
                if (k == j) 
                    continue;
                // dp에 저장된 이전행에서 큰값을 찾는다.
                if (max < dp[i - 1][k])
                    max = dp[i - 1][k]; 
            }   
            
            // 이전 행의 max와 현재 행의 값을 더해서 dp에 저장한다.
            dp[i][j] = land[i][j] + max;
            printf("dp[%d][%d]=[%d], %d\n", i, j, dp[i][j], max);
        }
        
        cout << endl;
    }
    
    // dp의 마지막 행에서 가장 큰값을 찾는다.
    answer = *max_element(dp.back().begin(), dp.back().end());
    return answer;
}
