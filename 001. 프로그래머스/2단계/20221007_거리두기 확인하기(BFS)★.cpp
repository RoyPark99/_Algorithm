#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

// 차이를 한번 생각해볼 필요가 있다.
// https://wadekang.tistory.com/34 dfs
// https://ggjjdiary.tistory.com/90

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

// 좌표를 탐색하면서 P가 있는 경우 상하좌우 bfs탐색을 한다.
// 탐색범위는 2개 범위 내이며, 
bool bfs(vector<string> &v, int j, int k) {
    vector<vector<bool>> visit(5, vector<bool>(5, false));
    queue<pair<pair<int, int>, int>> q;
    
    // P가 위치한 좌표를 넣고 방문처리한다.
    q.push({{j, k}, 0});
    visit[j][k] = true;
    
    while (!q.empty())
    {
        int tj = q.front().first.first;
        int tk = q.front().first.second;
        int tcnt = q.front().second;
        q.pop();
        
        if (tcnt >= 2)
            continue;
            
        // 요약 : 상하좌우 좌표계 내이면, 방문하지 않은 좌표이면, 빈자리이면 다음에 검사하도록 넣고 +1, 기준좌표 근처에 P가 있으면 실패 처리
        for (int i = 0; i < 4; i++)
        {
            // 기준 좌표에서 상하좌우
            int dj = tj + dx[i];
            int dk = tk + dy[i];
            
            // 상하좌우가 좌표계 내이면, 아니면 다음 좌표 검사
            if (dj >= 0 && dj < 5 && dk >= 0 && dk < 5)
            {
                // 검사좌표 j, k 기준에서 상하좌우가 방문하지 않은 좌표이면...
                if (!visit[dj][dk])
                {
                    // 빈자리이면 빈자리 기준 주변 좌표 탐색을 위에서 큐에 넣는다. 대신 2번 이상 안하기 위해서 카운트도 넣는다.
                    if (v[dj][dk] == 'O')
                    {
                        // 방문했던 곳이면 또 할 필요가 없으므로 방문처리...
                        visit[dj][dk] = true;
                        q.push({{dj, dk}, tcnt + 1});
                    }
                    // 기준좌표 근처에 사람이 있으면 무조건 실패 처리...
                    else if (v[dj][dk] == 'P')
                        return false;
                }
            }
        }
    }
    
    return true;
}

vector<int> solution(vector<vector<string>> p) {
    vector<int> answer;
    // 방단위 루프
    for (int i = 0; i < p.size(); i++)
    {
        // 해당 방에서 y축 방향
        bool fail = false;
        for (int j = 0; j < p[i].size(); j++)
        {
            // 해당 방에서 x축 방향
            for (int k = 0; k < p[i].size(); k++)
            {
                cout << p[i][j][k] << " ";
                // P좌표에서 bfs 탐색, false면 거리두기 안지키니 중단.
                if (p[i][j][k] == 'P')
                    if (!bfs(p[i], j, k))
                    {
                        fail = true;
                        break;
                    }
            }
            
            cout << endl;
        }
        
        // 방 단위 확인 결과 반영
        if (fail)
            answer.push_back(0);
        else
            answer.push_back(1);
        
        cout << endl;
    }
    
    return answer;
}









// 칭찬 받은 정답 첨부
/*
#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool is_valid_place(const vector<string>& place)
{
    constexpr size_t N = 5;
    vector<vector<int>> is_in_use(N, vector<int>(N, false) );

    int di[] = {1,-1,0,0};
    int dj[] = {0,0,1,-1};

    for(size_t i=0; i!=N; ++i)
        for(size_t j=0; j!=N; ++j)
            if(place[i][j] == 'P')
            {
                for(size_t k=0; k!=4; ++k)
                {
                    size_t moved_i = i + di[k];
                    size_t moved_j = j + dj[k];

                    if(moved_i >= N || moved_j >= N)
                        continue;

                    switch(place[moved_i][moved_j])
                    {
                        case 'P':
                            return false;
                        case 'O':
                            if(is_in_use[moved_i][moved_j])
                                return false;

                            is_in_use[moved_i][moved_j] = true;
                            break;
                        case 'X':
                            break;
                    }
                }
            }

    return true;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer(5);
    for(size_t i=0; i!=5; ++i)
        answer[i] = is_valid_place(places[i]);
    return answer;
}
*/