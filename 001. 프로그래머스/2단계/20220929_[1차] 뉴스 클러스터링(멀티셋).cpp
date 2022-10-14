#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;
// 알파벳만 집합으로 만들어준다. 중복허용
multiset<string> getElement(string &s){
    multiset<string> tmp;
    for (int i = 0; i < s.size(); i++)    {
        if (i != s.size() - 1)        {
            if (isalpha(s[i]) && isalpha(s[i + 1]))
                tmp.insert(s.substr(i, 2));          
        }
    }
    for (auto v : tmp)        cout << v << " ";        cout << endl;
    return tmp;
}

// 두 집합에서 공통 요소를 넣는다. 중복허용
multiset<string> getInter(multiset<string> s1, multiset<string> s2){
    multiset<string> settmp;
    for (auto it = s1.begin(); it != s1.end();)    {
        bool hit = false;
        for (auto it2 = s2.begin(); it2 != s2.end();)        {
            if (*it == *it2)            {
                hit = true;
                settmp.insert(*it2);
                it2 = s2.erase(it2);
                break;
            }
            else it2++;
        }
        
        if (hit) it = s1.erase(it);
        else it++;
    }

    //for (auto v : settmp)        cout << v << ", "; cout << endl;
    return settmp;
}

int solution(string str1, string str2) {
    int answer = 0;
    transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
    transform(str2.begin(), str2.end(), str2.begin(), ::tolower);
    // 각각의 원소를 구한다.
    multiset<string> ms1 = getElement(str1);
    multiset<string> ms2 = getElement(str2);
    // 교집합을 구한다.
    multiset<string> s4 = getInter(ms1, ms2);
    // 교집합으로 합집합 개수를 구한다.
    int inter = s4.size();
    int uni = ms1.size() + ms2.size() - inter;
    
    if (uni == 0)        answer = 1 * 65536;
    else    {
        double dj = (double)inter / (double) uni;
        answer = dj * 65536;
    }
    
    return answer;
}