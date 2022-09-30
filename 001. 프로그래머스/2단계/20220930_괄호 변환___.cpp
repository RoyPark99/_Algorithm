#include <string>
#include <vector>
#include <stack>

using namespace std;

bool check(const string &a) {
    int r = 0;
    for (char ch : a) {
        if (ch == '(') ++r;
        else --r;
        if (r < 0) return false;
    }
    return r == 0;
}
string solution(string p) {
    if (p == "") return "";
    if (check(p)) return p;

    int i, t = 0;
    for (i = 0; i < p.size(); ++i) {
        if (p[i] == '(') ++t;
        else --t;
        if (t == 0) break;
    }

    string u = p.substr(0, i + 1);
    string v = p.substr(i + 1);

    if (check(u)) return u + solution(v);

    for (char &ch : u) ch = ch == '(' ? ')' : '(';
    return string("(") + solution(v) + ")" + u.substr(1, u.size() - 2);
}

/*
// "올바른 괄호 문자열"인지 판별
bool isProper(string s){
    stack<int> st;
    for(int i = 0; i < s.length(); i++)    {
        if (s[i] == '(')
            st.push(s[i]);
        
        if (s[i] == ')')
            if (!st.empty())
                st.pop();
    }
    
    if (st.empty()) return true;
    else return false;
}

string removeAndReverse(string u)  // 4-4 의 과정
{
    u.erase(u.begin());   // u의 첫번쨰 문자 제거
    u.erase(u.end() - 1); // u의 마지막 문자 제거
    
    for(int i = 0; i < u.length(); i++) // 괄호 방향 뒤집기
    {
        if (u[i] == '(') u[i] = ')'; 
        else if (u[i] == ')') u[i] = '(';
    }
    
    return u;
}

string convert(string w)
{
    if (w == "") return w;  // 1. 빈 문자열인 경우 검사
    
    // 2. w = u, v 로 분리. "균형잡힌 괄호 문자열" 찾자마자 break하면 그게 바로 u, 나머지는 v
    int openCount = 0; int closeCount = 0;
    int index = 0;
    for(int i = 0; i < w.length(); i++)
    {
        if (w[i] == '(') openCount++;
        if (w[i] == ')') closeCount++;
        
        if (openCount == closeCount) 
        {
            index = i + 1;
            break;
        }
    }
    string u = w.substr(0, index);
    string v = w.substr(index);
    
    string result = "";
    if (isProper(u)) // 3. 문자열 u가 "올바른 괄호 문자열"이라면
        result = u + convert(v); 
    else // 4. 문자열 u가 "올바른 괄호 문자열"이 아니라면
        result =  "(" + convert(v) + ")" + removeAndReverse(u);

    return result; 
}

string solution(string p) {
    string answer = convert(p);
    return answer;
}
*/