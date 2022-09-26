#include <string>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

deque<string> dq;
bool GetCache(string &str, int cnt){
    if (!cnt) return false;
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

        dq.push_back(str);   
    }
    return hit;
}

int solution(int cacheSize, vector<string> ci) {
    int answer = 0;
    for (int i = 0; i < ci.size(); i++) {
        string &s = ci[i];
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        bool ret = GetCache(s, cacheSize);
        if (ret)
            answer += 1;
        else
            answer += 5;
    }
        
    return answer;
}