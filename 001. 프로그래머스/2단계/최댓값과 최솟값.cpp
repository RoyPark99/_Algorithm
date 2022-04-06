#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

string solution(string s) {
    string answer = "";
    vector<int> v;
    
    istringstream iss(s);
    string buffer;
 
    // istringstream은 istream을 상속받으므로 getline을 사용할 수 있다.
    while (getline(iss, buffer, ' ')) 
    {
        v.push_back(stoi(buffer));
    }
    
    answer += to_string(*min_element(v.begin(), v.end()));
    answer += " ";
    answer += to_string(*max_element(v.begin(), v.end()));
    
    return answer;
}