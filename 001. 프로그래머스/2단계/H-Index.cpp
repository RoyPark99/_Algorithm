#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> c) {
    // 내림차순
    sort(c.begin(), c.end(), greater<int>());
    
    for (int i = 0; i < c.size(); i++)
    {
        // 개수가 인용개수보다 커지면 h-index
        if (i + 1 > c[i])
            return i;
    }
    
    // 커지는 시점이 없으면 전체 사이즈
    return c.size();
}