#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    for (long long i = left; i <= right; i++)    {
        int r = i / n;//행
        int c = i % n;//열
        // 행과 열 중에 더 큰값에 +1해서 넣는다.
        answer.push_back((r > c ? r : c) + 1);
        //answer.push_back(max(i / n, i % n) + 1);
    }
    
    return answer;
}