#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <set>

using namespace std;

// 20221015 : 문제의 의도가 이중우선순위큐로 푸는것이지만 추가적으로 array를 이용한 방법도 추가한다.
vector<int> solution(vector<string> o) {
    vector<int> answer {0, 0};

    // 최대힙q1, 최소힙q2
    priority_queue<int> q_max;
    priority_queue<int, vector<int>, greater<int>> q_min;
    // 인풋과 아웃풋을 이용하여 실제 큐의 카운트를 관리한다.
    int cnt = 0;
    for (int i = 0; i < o.size(); i++) {
        // 토큰 분리
        const char *pNum = o[i].c_str();
        int n = atoi(&pNum[2]);
        //cout << o[i].front() << ", " << n << endl;
        
        // 카운트가 0이면 큐의 데이터를 제거해준다.
        if (!cnt) {
            while (!q_max.empty()) q_max.pop();
            while (!q_min.empty()) q_min.pop();
        }
        
        // 인풋 : 각 큐에 데이터를 넣고 카운트를 올려준다.
        if (o[i].front() == 'I') {
            q_max.push(n);
            q_min.push(n);
            cnt++;
        }
        else {
            // 빈큐에 삭제이면 무시한다.
            if (!cnt)
                continue;
                
            // 최대값 제거
            if (n == 1) {
                q_max.pop();
                cnt--;
            }
            else {
                // 최소값 제거
                q_min.pop();
                cnt--;
            }
        }
    }
    
    if (cnt) {
         answer[0] = q_max.top();
         answer[1] = q_min.top();
    }
    
    return answer;
}

/*
// 멀티셋 : 멀티셋은 들어가면 자동 정렬된다.
vector<int> solution(vector<string> o) {
    vector<int> answer;
    multiset<int> que;
    string sub;

    for (auto s : o) 
    {
        // 넣고 빼고 한다.
        sub = s.substr(0, 2);
        if (sub == "I ") 
            que.insert(stoi(s.substr(2, s.length() - 2))); 
        else if (s.substr(2,1) == "1" && que.size() > 0) 
        { 
            // 최대값 제거
            que.erase(--que.end()); 
        }
        else if (que.size()>0) 
        { 
            // 최소값 제거
            que.erase(que.begin()); 
        }
    }

    if (que.size() == 0) 
    { 
        answer.push_back(0); 
        answer.push_back(0); 
    }
    else { 
        auto iter = --que.end(); 
        answer.push_back(*iter); 
        
        iter = que.begin(); 
        answer.push_back(*iter);
    }

    return answer;
}
*/