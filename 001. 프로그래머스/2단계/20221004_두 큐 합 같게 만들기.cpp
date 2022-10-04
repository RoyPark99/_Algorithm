#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <numeric>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    long long s1 = accumulate(queue1.begin(), queue1.end(), 0);
    long long s2 = accumulate(queue2.begin(), queue2.end(), 0);
    int limit = queue1.size() + queue2.size() + 1;
    
    queue<int> q1, q2;
    for (auto v : queue1)        q1.push(v);
    for (auto v : queue2)        q2.push(v);
    //cout << s1 << s2;
    
    // 그리디
    int cnt = 0;
    while (1) {
        if (s1 == s2)
            break;
        
        if (cnt > limit)
            return -1;
        
        if (s1 > s2) {
            int tmp = q1.front();
            q2.push(tmp);
            q1.pop();
            s1 -= tmp;
            s2 += tmp;
        }
        else {
            int tmp = q2.front();
            q1.push(tmp);
            q2.pop();
            s1 += tmp;
            s2 -= tmp;
        }
        
        cnt++;
    }
    
    return cnt;
}