#include <string>
#include <vector>
#include <iostream>
#include <set>

using namespace std;
set<pair<int, int>> s;

void markBlock(vector<string> &b, int r, int c) {
    if (b.size() - 2 < r || b[0].size() - 2 < c) return;
    if (b[r][c] != '0' && b[r][c] == b[r][c + 1] && b[r + 1][c] == b[r + 1][c + 1] && b[r][c] == b[r + 1][c]) {
        s.insert({r, c});
        s.insert({r, c + 1});
        s.insert({r + 1, c});
        s.insert({r + 1, c + 1});
        //cout << b[r][c] << b[r][c + 1] << "\n" << b[r + 1][c] << b[r + 1][c + 1] << endl; 
    }
}

void reArrange(int m, int n, vector<string> &b) {
    // 제거한 블럭 반영
    for (auto it : s)
        b[it.first][it.second] = '0';

    for (int i = 1; i < m; i++) {
        for (int j = 0; j < n; j++) {
            // 아래쪽이 0이면
            if (b[i][j] == '0') {
                // 1번행부터 -> 방향으로, 1번행 위에 0이 있으면 현재 값이랑 위치 변경하고, 위에는 0으로 채워 넣는다.
                for (int k = i; k > 0; k--) {
                    // 위쪽 값이 0이면 다음 열 검사
                    if (b[k - 1][j] == '0') break;
                    // 위쪽 값이 0이 아니면 아래쪽으로 이동하고 위쪽은 0으로 처리한다.(한칸씩 내린다.)
                    b[k][j] = b[k - 1][j];
                    b[k - 1][j] = '0';
                }
            }
        }
    }
    
    //cout << endl;
    /*
    for (int i = 0; i < b.size(); i++)    {
        for (int j = 0; j < b[i].size(); j++)
            cout << b[i][j] << " ";
        cout << endl;
    }
    */
}

int solution(int m, int n, vector<string> b) {
    int answer = 0;
    while (1) {
        // 좌표 순회하면서 제거 가능한 블럭 좌표를 저장
        for (int i = 0; i < b.size(); i++)
            for (int j = 0; j < b[i].size(); j++)
                markBlock(b, i, j);   
        
        // 제거 가능한 좌표가 없으면 끝
        if (s.empty()) break;
        
        // 퍼즐 갱신
        reArrange(m, n, b);
        
        // 제거한 퍼즐 갱신
        answer += s.size();
        s.clear();
        //for (auto it : s)  cout << it.first << " " << it.second << endl;
    }

    return answer;
}