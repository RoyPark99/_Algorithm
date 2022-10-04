#include <string>
#include <vector>
#include <queue>
//#include <functional>

using namespace std;

int solution(vector<int> s, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, std::greater<int>> 
    q(s.begin(), s.end());
    
    while (!q.empty()) {
        // 스코빌 지수가 K이상이면 중단
        if (q.top() >= K)
            break;
        
        // 두개를 합쳐서 하나의 새로운 음식을 만든다.
        // 이렇게 반복하면 결국 한개만 남는다.
        if (q.size() >= 2) {
            int min1 = q.top();
            q.pop();
            
            int sco = min1 + q.top() * 2;
            q.pop();
            
            q.push(sco);
            answer++;
        }
        else
            return -1;
    }
    
    return answer;
}