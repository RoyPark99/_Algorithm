#include <string>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

// LRU 알고리즘을 알아야한다.
deque<string> dq;
bool GetCache(string &str, int cnt){
    // 캐시 크기가 없으면 리턴한다.(저장 불가한 상태)
    if (!cnt) 
        return false;
    
    // hit 되면 가장 뛰쪽으로 보낸다.
    bool hit = false;
    for (auto it = dq.begin(); it != dq.end(); it++){
        if (*it == str) {
            hit = true;
            dq.erase(it);
            dq.push_back(str);
            break;
        }
    }
    
    if (!hit) {
         // 캐시에 없으면 값을 넣어야 하니 캐시랑 같거나 크면 하나를 삭제해야 한다.
        if (dq.size() >= cnt) {
            dq.pop_front();
        }   

        // 캐시를 뒤쪽에 추가한다.
        dq.push_back(str);   
    }
    return hit;
}

int solution(int cacheSize, vector<string> ci) {
    int answer = 0;
    for (int i = 0; i < ci.size(); i++) {
        // 도시이름의 레퍼런스를 받는다.
        string &s = ci[i];
        // 소문자로 변환한다.
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        // 캐시가 있으면 1, 없으면 5의 실행시간을 리턴한다.
        bool ret = GetCache(s, cacheSize);
        if (ret)
            answer += 1;
        else
            answer += 5;
    }
        
    return answer;
}