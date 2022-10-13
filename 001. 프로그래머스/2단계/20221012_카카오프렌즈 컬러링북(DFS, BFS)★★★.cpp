#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

/*
전체 좌표를 방문하면서 방문처리 하고, 상하좌우의 좌표에 대해서 조건이 충족하면 재귀적으로 탐색한다.
이때 인접 정점 중에서 값이 같으면 adj_point_cnt가 카운트된다.
좌표에 대해서 dfs탐색을 실시하고 나면 각 연결된 정점의 덩어리들 개수가 리턴되며 이것이 push되면서 덩어리 카운트도 리턴된다.
*/

bool visited[101][101];
int dr[4] = {0, 0, 1, -1};
int dc[4] = {1, -1, 0, 0};
int ROW, COL;
int adj_point_cnt = 0; // dfs only

//--- BFS
void bfs(int &m, int &n, vector<vector<int>> &p, int &areaCount, int &sizeOfArea) {
    // 기준 좌표를 기준으로 방문한적이 있으면 리턴된다.
    if (visited[m][n])
        return;

    // bfs로 넘어 왔다는 것은 일단 영역이 있다는 의미이므로 카운트한다.(1개 일지라도)
    areaCount++;
    
    queue<pair<int, int>> q;
    // 기준좌표(최초 시작좌표)를 시작으로 탐색한다.
    q.push({m, n});
    
    // 기준좌표에 연결된 좌표 카운트
    int areaSize = 0;
    
    while (!q.empty())
    {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();
        
        // 첫째 : 기준 좌표가 방문한적이 없으면
        // 둘째 : 인접 좌표에 방문한적이 없으면
        if (!visited[row][col])
        {
            visited[row][col] = true;
            areaSize++;

            // 상하좌우 좌표가 좌표계 내이면서 && 기준 좌표와 값이 같으면 다음 탐색 대상에 넣는다.
            for (int i = 0; i < 4; i++)
            {
                int nextRow = row + dr[i];
                int nextCol = col + dc[i];

                if ((nextRow >= 0) && (nextRow < ROW) &&
                   (nextCol >= 0) && (nextCol < COL) &&
                   (p[row][col] == p[nextRow][nextCol]))
                {
                    q.push({nextRow, nextCol});
                }
            }
        }
    }
    
    // 기준 좌표로 부터 조건에 부합하는 인접 좌표들의 카운트가 Max이면 갱신하도록 한다.
    if (sizeOfArea < areaSize)
        sizeOfArea = areaSize;
}

vector<int> solution(int m, int n, vector<vector<int>> p) {
    vector<int> answer(2);
    answer[0] = 0;
    answer[1] = 0;
    fill(&visited[0][0], &visited[100][100], 0);
    ROW = m;
    COL = n;
    // 연결된 좌표들 그룹 카운트
    int areaCount = 0;
    // 좌표 구성 카운트
    int sizeOfArea = 0;
    
    // 각 좌표를 기준으로 모두 bfs 탐색
    for (int row = 0; row < m; row++) {
        for (int col = 0; col < n; col++) {
            // row, col 기준으로 0이 아니면 bfs 탐색하고, bfs 첫 부분에서 방문한적이 있으면 리턴된다.
            if (p[row][col]) {
                bfs(row, col, p, areaCount, sizeOfArea);
            }
        }
    }
    answer[0] = areaCount;
    answer[1] = sizeOfArea;
    return answer;
}

//--- DFS
/*
void dfs(const int &m, const int &n, const vector<vector<int>> &p) {
    visited[m][n] = true;
    adj_point_cnt++;
    // 현재 좌표 기준으로 상하좌우 방향에 대해서 탐색한다.
    for (int i = 0; i < 4; i++) {
        int nextRow = m + dr[i];
        int nextCol = n + dc[i];
        // 상하좌우 좌표가 좌표계 내이면서&& 방문하지 않은 좌표이고 && 최초 좌표와 같은 값이면 dfs 탐색한다.
        if ((nextRow >= 0) && (nextRow < ROW) && 
            (nextCol >= 0) && (nextCol < COL) &&
            !visited[nextRow][nextCol] &&
            (p[m][n] == p[nextRow][nextCol])) {
            dfs(nextRow, nextCol, p);
        }
    }
}

vector<int> solution(int m, int n, vector<vector<int>> p) {
    ROW = m;
    COL = n;
    fill(&visited[0][0], &visited[ROW][COL], 0);
    vector<int> answer(2);
    answer[0] = 0;
    answer[1] = 0;
    vector<int> adj_point_return;
    
    // 방문하지 않은 모든 좌표에 대해서 dfs로 완전탐색한다.
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            // 0이 아니면서 && 방문하지 않은 노드에 대해서 dfs탐색한다.
            if (p[i][j] && !visited[i][j]) {
                // 현재 좌표 기준으로 인접한 정점의 카운트 리턴
                adj_point_cnt = 0;
                dfs(i, j, p);
                adj_point_return.push_back(adj_point_cnt);
            }
        }
    }
    
    answer[0] = adj_point_return.size();
    answer[1] = *max_element(adj_point_return.begin(), adj_point_return.end()); 
    return answer;
}
*/