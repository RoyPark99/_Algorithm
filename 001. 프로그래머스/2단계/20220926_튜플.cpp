#include <string>
#include <vector>
#include <sstream>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
    return a.second > b.second;
}

vector<string> split(string s, string divid) {
	vector<string> v;
	char* c = strtok((char*)s.c_str(), divid.c_str());
	while (c) {
		v.push_back(c);
        //cout << (string)c << " ";
		c = strtok(NULL, divid.c_str());
	}
    //cout << s;
	return v;
}

// 전체 스플릿을 하고 원소 개수가 많은것 부터 가장 왼쪽에 넣는다.
vector<int> solution(string s) {
    vector<int> answer;
    vector<string> s1, s2;
    // 각 원소별로 분리
    s1 = split(s, "},{");
    s2 = s1;
    // s2에 카운트할 원소 분리
    sort(s2.begin(), s2.end());
    s2.erase(unique(s2.begin(), s2.end()), s2.end());
    
    // s2기반으로 카운트 세고 정렬하기 위한 s3 생성
    vector<pair<int, int>> s3;
    for (auto vec : s2)    {
        int cnt = count(s1.begin(), s1.end(), vec);
        s3.push_back(make_pair(stoi(vec), cnt));
        //cout << vec << " , " << cnt << " " << endl;        
    }
    // 개수대로 정렬된 값 넣기
    sort(s3.begin(), s3.end(), cmp);
    for (auto vec : s3)    {
        answer.push_back(vec.first);
        cout << vec.first << " , " << vec.second << " " << endl;        
    }
    
    return answer;
}