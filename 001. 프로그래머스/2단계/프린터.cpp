#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

bool isPrior(int n, vector<pair<int, int>> &v)
{
    for (auto vec : v)
    {
        if (n < vec.second)
            return true;
    }
    
    return false;
}

int solution(vector<int> p, int l) {
    int answer = 0;

    vector<int> print;
    vector<pair<int, int>> wait;
    
    // 인덱스와 선호도를 벡터에 넣고
    for (int i = 0; i < p.size(); i++)
        wait.push_back(make_pair(i, p[i]));
    
    // 루프를 돌면서 첫번째 선호도보다 높은 선호도가 뒤에 있으면 push_back, 없으면 print한다.
    while (1)
    {
        if (wait.empty())
            break;
        
        bool ret = isPrior(wait.front().second, wait);
        if (ret)
        {
            wait.push_back(wait.front());
            wait.erase(wait.begin());
        }
        else
        {
            print.push_back(wait.front().first);
            wait.erase(wait.begin());
        }
    }
    
    // 반복하면서 print에 순서대로 들어가면 원하는 인덱스를 찾아서 리턴한다.
    for (int i = 0; i < print.size(); i++)
    {
        if (l == print[i])
        {
            answer = i + 1;
            break;
        }
    }
    
    return answer;
}