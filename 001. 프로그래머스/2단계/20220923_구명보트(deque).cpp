#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    // 오름차순으로 정렬
    sort(people.begin(), people.end());
    // 무거워서 혼자 타야하는 사람부터 제거하면서 카운트한다.
    while (1) {   
        if (people.back() / 2 > limit) {
            answer++;
            people.pop_back();
        }
        else
            break;
    }
    // 나머지 사람들 덱에 넣는다.
    deque<int> dq;
    for (auto vec : people) 
        dq.push_back(vec);
    
    while (!dq.empty()) {
        // 마지막 혼자면 혼자타야하므로 카운트하고 중단한다.
        if (dq.size() == 1) {
            answer++;
            break;
        }
            
        // 맨앞, 맨뒤 사람이 제한보다 많으면 뒷사람 한명만 태운다.
        if (dq.front() + dq.back() > limit) 
            dq.pop_back();
        // 제한 이하면 둘다 태운다.
        else {
            dq.pop_back();
            dq.pop_front();
        }
        
        // 두명이든 한명이든 한상 타니깐 카운트한다.
        answer++;
    }
    
    return answer;
}
