#include <iostream>
#include <string>
#include <stack>

using namespace std;

int solution(string s)
{
    int answer = -1;
    stack<int> st;
    
    for (auto str : s)
    {
        // 비었으면 하나를 넣는다. 그리고 다음 글자로...
        if (st.empty())
        {
            st.push(str);
            continue;
        }
        
        // 하나 꺼내서 지금꺼랑 같으면 이전꺼 제거...
        if (st.top() == str)
        {
            st.pop();
        }
        else
        {
            // 다르면 새로운놈 넣고 반복
            st.push(str);
        }
    }
    
    answer = st.empty() ? 1 : 0;

    return answer;
}