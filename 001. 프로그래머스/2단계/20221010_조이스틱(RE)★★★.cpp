#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string name)
{
    // "AAABBAB"
    int answer = 0;
     //커서를 좌 또는 우 한 쪽 방향만으로 이동했을 때 최대 횟수
    int shift = name.length() - 1;
    for(int i = 0; i < name.length(); i++)
    {
        if(name[i] == 'A')
        {
            int target = i;
            while(target < name.length() && name[target] == 'A') 
                target += 1; //A로만 이루어진 문자열 찾기
            
            int left = i == 0 ? 0 : i - 1; //찾은 문자열 왼쪽에서의 이동횟수
            int right = name.length() - target;  //찾은 문자열 오른쪽에서의 이동횟수
            shift = min(shift, left + right + min(left, right)); //가장 작은값 찾기
        }
    }
    
    answer += shift;
    // 상하 이동횟수 구하기
    for(auto c : name) 
        answer += min(c - 'A', 'Z' - c + 1);
    return answer;
}

/*
int getCount(char c) {
    int n = c - 'A';
    int n2 = 'Z' - c + 1;
    cout << n << " " << n2 << " a= ";
    if (n >= n2)        return n2;
    else        return n;
    return 0;
}

int solution(string name) {
    int answer = 0;
    string s(name.size(), 'A');
    int len = name.size();
    int pos = 0;
    while (len > 0)
    {       
        //if (len == 0)            break;
        // 현재 포지션에서 문자가 다르면 카운트를 구하고 문자를 설정한다.
        if (name[pos] != s[pos])        {
            answer += getCount(name[pos]);
            //cout << answer << endl;
            s[pos] = name[pos];
        }
        
        // 다음에 바꿔야할 위치로 이동
        // 0 ~ max - 1 사이면
        if (pos > 0 && pos < name.size() - 1)
        {
            if (name[pos + 1] != s[pos + 1])
            {
                pos++;
                answer++;
            }
            else if (name[pos - 1] != s[pos - 1])
            {
                pos--;
                answer++;
            }
            else
                len--;
        }
        else if (pos == 0)
        {
            if (name[pos + 1] != s[pos + 1])
            {
                pos++;
                answer++;
            }
            else if (name[name.size() - 1] != s[name.size() - 1])
            {
                pos = name.size() - 1;
                answer++;
            }
            else
                len--;
        }
        else if (pos == name.size() - 1)
        {
            if (name[pos - 1] != s[pos - 1])
            {
                pos--;
                answer++;
            }
            else if (name[0] != s[0])
            {
                pos = 0;
                answer++;
            }
            else
                len--;
        }
              
        cout << name << " " << s << " " << len << " " << answer << endl;
        
        len--;
    }
    
    return answer;
}
*/