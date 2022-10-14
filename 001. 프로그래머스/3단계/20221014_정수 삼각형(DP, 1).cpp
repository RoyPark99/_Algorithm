#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

// 기준 위치이 값을 매번 갱신하면서 다음번에도 사용하도록 하는게 핵심이다.
int solution(vector<vector<int>> t) {
    int answer = 0;
    // 최상단을 제외한 아래부터 계산한다.
    for (int i = 1; i < t.size(); i++) {
        for (int j = 0; j < t[i].size(); j++) {
            // j기준 0이면 -1값이 없으므로 우측값만 더해서 갱신한다. 7 + 3 = 10
            if (j == 0)
                t[i][j] = t[i][j] + t[i - 1][j];
            // j기준 우측값이 max크기를 넘으므로 좌측값만 더해서 갱신한다.
            else if (j == (t[i - 1].size()))
                t[i][j] = t[i][j] + t[i - 1][j - 1];
            // 중간 위치의 j값은 우측값, 좌측값 중에서 더 큰 값으로 갱신한다.
            else
                t[i][j] = max(t[i][j] + t[i - 1][j - 1], t[i][j] + t[i - 1][j]);
            //cout << t[i][j] << " ";
        }
        //cout << endl;
    }
    answer = *max_element(t[t.size() - 1].begin(), t[t.size() - 1].end());
    return answer;
}