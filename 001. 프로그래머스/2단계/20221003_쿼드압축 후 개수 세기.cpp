#include <string>
#include <vector>

using namespace std;

void dfs(vector<vector<int>> &arr, int &zero, int &one, int startRow, int startCol, int n){
    //압축 안되면 각 개수 카운트
    if (n == 1)    {
        if (arr[startRow][startCol] == 0) zero++;
        else one++;
        return;
    }
    
    // 타겟 범위 내에서 0, 1 개수를 카운트해서 압축 여부판단.
    int sum = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            sum += arr[startRow + i][startCol + j];
    
    // 전부 0으로 압축,  1로 압축됐으면 하나만 증가하고, 해당 범위는 압축 완료됨
    if (sum == 0)    {
        zero++;
        return;
    }
    else if (sum == n * n)    {
        one++;
        return;
    }
    else    {
        // (0,0) 에서 반, (0,2)에서 반, (2,0)에서 반, (2,2)에서 반 카운트
        dfs(arr, zero, one, startRow, startCol, n / 2);
        dfs(arr, zero, one, startRow, startCol + n /2, n / 2);
        dfs(arr, zero, one, startRow + n /2, startCol, n / 2);
        dfs(arr, zero, one, startRow + n /2, startCol + n /2, n / 2);
    }
}

vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer(2,0);
    dfs(arr, answer[0], answer[1], 0, 0, arr.size());
    return answer;
}