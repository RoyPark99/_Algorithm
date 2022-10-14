#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iostream>

using namespace std;

// 20221007리뷰 : 이 문제는 문자열을 파싱하여 최소, 최대값을 추출하는데 의의가 있다.
string solution(string s) {
    string answer = "";
    vector<int> v;

    // istringstream은 istream을 상속받으므로 getline을 사용할 수 있다.
    stringstream ss(s);
    string buffer;
    while (getline(ss, buffer, ' ')) 
    {
        v.push_back(stoi(buffer));
        //cout << buffer << endl;
    }
    
    // 최대값, 최소값 뽑아내는 문제, 알고리즘이면 끝
    answer += to_string(*min_element(v.begin(), v.end()));
    answer += " ";
    answer += to_string(*max_element(v.begin(), v.end()));
    return answer;
}