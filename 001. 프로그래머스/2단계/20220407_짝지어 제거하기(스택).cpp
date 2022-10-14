#include <iostream>
#include <string>
#include <stack>

using namespace std;

// 스택을 이용해서 없으면 넣고, 있으면 현재꺼랑 비교해서 제거하거나 새로 넣고 해서 제거 가능한지 확인한다.
int solution(string s) {
    stack<int> st;
    // 문자열을 순서대로 돌린다.
    for (auto str : s) {
        // 스택이 비었으면 하나 넣는다.
        if (st.empty()) {
            st.push(str);
            continue;
        }
        
        // 하나 꺼내서 지금꺼랑 같으면 이전꺼 제거...
        if (st.top() == str)
            st.pop();
        // 다르면 새로운놈 넣고 반복
        else
            st.push(str);
    }
    
    return st.empty() ? 1 : 0;
}