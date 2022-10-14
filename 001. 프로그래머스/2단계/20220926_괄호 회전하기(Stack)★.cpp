#include <string>
#include <vector>
#include <iostream>
#include <stack>

using namespace std;
bool isRight(string &s){
    stack<int> st;
    int push = 0;
    int pop = 0;
    for (int i = 0; i < s.size(); i++) {
        // 시작괄호를 넣는다.
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
            st.push(s[i]);
            push++;
        }
        if (s[i] == ')' || s[i] == ']' || s[i] == '}') {
            // 홀수일때 해당 괄호의 끝이 아니면 비정상 괄호
            if (st.size() % 2) {
                if (st.top() == '(' && s[i] != ')')
                    return false;
                else if (st.top() == '[' && s[i] != ']')
                    return false;
                else if (st.top() == '{' && s[i] != '}')
                    return false;
            }
            // 시작괄호만큼 빼준 카운트 올린다.
            pop++;
            if (!st.empty())
                st.pop();
        }
    }
    // 스택이 비었고 들어가고 나간 사이즈가 같으면 정상 괄호임
    if (st.empty() && push && pop && (push == pop)) {
        return true;
    }
    
    return false;
}

int solution(string s) {
    int answer = 0;
    for (int i = 0; i < s.size(); i++) {
        s.push_back(s.front());
        s.erase(0, 1);
        bool ret = isRight(s);
        if (ret)
            answer++;
        //cout << s << " " << ret << " " << endl;
    }
    
    return answer;
}