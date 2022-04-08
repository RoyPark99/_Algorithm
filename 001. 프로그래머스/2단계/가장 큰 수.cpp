#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare (int a, int b)
{ 
    // 앞 뒤 숫자를 서로 반대로 합친 문자로 비교하여 정렬한다.
    //a: 30 b : 3
	//str_a : 303 str_b : 330
	//a : 30 b : 3
	//str_a : 303 str_b : 330
	//a : 34 b : 3
	//str_a : 343 str_b : 334
	//a : 5 b : 34
	//str_a : 534 str_b : 345
	//a : 9 b : 5
	//str_a : 95 str_b : 59
    string str_a = to_string(a) + to_string(b);
    string str_b = to_string(b) + to_string(a);
    
    return str_a > str_b;
}

string solution(vector<int> numbers) {
    string answer = "";
    
    sort(numbers.begin(), numbers.end(), compare);
    
    if (numbers[0] == 0)
        return "0";
    
    // 정렬된 숫자를 그대로 이어 붙인다.
    for(auto & elem : numbers)
    {
        answer += to_string(elem);
    }
    
    return answer;
}