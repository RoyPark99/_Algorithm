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


/* 다른사람 풀이 참고
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int solution(vector<int> citations) {

    sort(citations.begin(), citations.end(), greater<int>()); // 내림차순 정렬
    
    for(int i = citations[0]; i > 0; i--)
    {
        int count = 0;
        for(auto & elem : citations)
        {
            if (elem >= i)
            {
                count++;
                if (i == count)
                    return count;
            }
        }
    }
}
*/