#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

bool solution(vector<string> p) {
    bool answer = true;
    
    // 접두가 가능성 있는 것들 최대한 앞으로 정렬
    sort(p.begin(), p.end());
    
    // 첫번째는 미리 넣어준다.
    unordered_set<string> set;
    set.insert(p[0]);
    
    // 폰북 2번째부터 해시에서 찾아본다.
    // 해시에서 찾으면 false다.
    for (int i = 1; i < p.size(); i++)
    {
        string str = "";
        for (int j = 0; j < p[i].size(); j++)
        {
            str += p[i][j];
            if (set.find(str) != set.end())
                return false;
        }
        
        // 없으면 다른 녀석의 접두어가 될수 있으므로 넣어준다.
        set.insert(p[i]);
    }
    
    return answer;
}