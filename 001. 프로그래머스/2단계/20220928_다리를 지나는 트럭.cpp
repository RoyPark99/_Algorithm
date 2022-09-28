#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(int bridge_length, int weight, vector<int> tw) {
    vector<pair<int, int>> v;
    int remain_weight = weight;
    int sec = 0;
    while (1) {   
        if (sec != 0 && v.empty()) break;
              
        // 지나가는 시간 계산, 0이 되면 건너는 트럭에서 빼준다.
        for (vector<pair<int, int>>::iterator it = v.begin(); it != v.end(); ) {
            it->second--;
            if (it->second == 0) {
                remain_weight += it->first; // 다지나간 트럭 무게를 반영해준다.
                it = v.erase(it);
            }
            else
                it++;
        }

        // 대기트럭 -> 건너는 트럭에 넣는다.
        if (!tw.empty() && tw.front() <= remain_weight) {
            remain_weight -= tw.front();
            v.push_back(make_pair(tw.front(), bridge_length));
            cout << remain_weight << ", " << tw.front() << endl;
            tw.erase(tw.begin());
        }    

        sec++;
    }
    
    return sec;
}