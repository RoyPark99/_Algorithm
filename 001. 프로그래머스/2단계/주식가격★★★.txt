#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) 
{
    int n = prices.size();
    vector<int> answer(n);
    stack<int> s; // 주식 가격의 인덱스 보관
    
    for(int i = 0; i < n; ++i)
    {
        while(!s.empty() && prices[i] < prices[s.top()])
        {
            answer[s.top()] = i - s.top();
            s.pop();
        }
        
        s.push(i);
    }
    
    // 한번도 주식 가격이 떨어진적이 없는 가격들 (여전히 스택 안에 존재)
    while(!s.empty())
    {
        answer[s.top()] = n - s.top() - 1;
        s.pop();
    }
    
    return answer;
}

/*
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    
    for (int i = 0; i < prices.size(); i++)
    {
        int sec = 0;
        
        // 
        for (int j = i + 1; j < prices.size(); j++)
        {
            sec++;
            if (prices[i] > prices[j])
            {
                break;
            }
        }
        
        answer.push_back(sec);
    }
    
    return answer;
}
*/