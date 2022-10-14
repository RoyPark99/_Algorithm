#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int INF = 999999999;

void dijkstra(vector<pair<int, int>> *adj, vector<int> &d, int N) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    // 시작 노드 및 거리 설정(거리, 노드)
    pq.push({0, 1});
    d[1] = 0;
    
    while (!pq.empty()) {
        // 최초 : 1번 노드, 거리 가져온다.
        // 이후 : 최소힙으로 정렬된 인접정점을 빼고 아래를 반복한다.
        int current_node = pq.top().second;
        int dist = pq.top().first;
        pq.pop();

        // 최초 : 1 -> 1 거리가 dist보다 작으면 skip, 최초는 9999라서 갱신됨
        if (d[current_node] < dist)
            continue;
        
        // current_node 기준으로 연결된 모든 노드를 탐색
        for (int i = 0; i < adj[current_node].size(); i++) {
            // current_node 기준 인접한 정점
            int next = adj[current_node][i].second;
            // current_node 기준 인접한 정점과의 거리
            int nextDist = dist + adj[current_node][i].first;

            // current_node 에 인접한 next와 거리가 nextDist보다 작으면 갱신해준다.
            // 모든 인접한 정점의 작으면 들어가진다.
            if (nextDist < d[next]) {
                d[next] = nextDist;
                pq.push({nextDist, next});
            }
        }
    }
}

int solution(int N, vector<vector<int>> road, int K) {
    int answer = 0;
    vector<int> d(N + 1, INF);
    
    // road를 그래프로 변환, 0번째 인덱스는 사용 안함.
    vector<pair<int, int>> adj[N + 1];
    for (int i = 0; i < road.size(); i++)    {
        adj[road[i][0]].push_back({road[i][2], road[i][1]});
        adj[road[i][1]].push_back({road[i][2], road[i][0]});
    }
    
    dijkstra(adj, d, N);
    
    //for (auto vec : d) cout << vec << " ";
    for (int i = 1; i < d.size(); i++)    {
        if (d[i] <= K)
            answer++;
    }
    
    return answer;
}

// prim
/*
int prim(vector<pair<int, int>> adj[], int n, int k) {

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({0, 0});
    
    int current_pos = 0;
    int min_dist = 0;
    //while (!q.empty())
    {
        
    }
    
    return 0;
}

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;

    // road를 그래프로 변환, 0번째 인덱스는 사용 안함.
    vector<pair<int, int>> adj[N + 1];
    for (int i = 0; i < road.size(); i++)    {
        adj[road[i][0]].push_back({road[i][2], road[i][1]});
        adj[road[i][1]].push_back({road[i][2], road[i][0]});
    }
    
    // prim으로 k값 이하의 간선의 개수를 구한다.
    answer = prim(adj, N, K);
    
    return answer;
}
*/