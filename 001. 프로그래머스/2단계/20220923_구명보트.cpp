#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(), people.end());
    while (1) {   
        if (people.back() / 2 > limit) {
            answer++;
            people.pop_back();
        }
        else
            break;
    }
    
    deque<int> dq;
    for (auto vec : people) dq.push_back(vec);
    
    while (!dq.empty()) {
        if (dq.size() == 1) {
            answer++;
            break;
        }
            
        if (dq.front() + dq.back() > limit) 
            dq.pop_back();
        else {
            dq.pop_back();
            dq.pop_front();
        }
        
        answer++;
    }
    
    return answer;
}
