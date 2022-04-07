#include <string>
#include <vector>
#include <algorithm>
#include <bitset>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer{0,0};
    
    while (1)
    {
        if (s == "1")
            break;
        
        // 0제거
        int orgsize = s.size();
        s.erase(remove(s.begin(), s.end(), '0'), s.end());
        int size = s.size();
        
        // 1개수를 2진법으로 변환
        s = bitset<20> (size).to_string();
        long long nn = stoll(s);
        s = to_string(nn);
        
        answer[0]++;
        answer[1] += (orgsize - size);
    }
    
    return answer;
}



/*
#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer(2);
    int count = 0;  // 이진 변환의 횟수
    int sum = 0;    // 제거된 모든 0의 개수
    
    while(s != "1")
	{
        int tempCount = 0;  // 해당 s의 1의 개수

        // s의 1의 개수 세기
        for(int i = 0; i < s.length(); i++)
            if (s[i] == '1')
                tempCount++;
        
        // s의 0의 개수 누적 합산
        sum += s.length() - tempCount;
        
        // 0제거한 x의 길이나 마찬가지인 tempCount를 2진법으로 표현
        s = "";
        while(tempCount > 0)
		{
            if (tempCount % 2 == 0) 
				s += "0";
            else 
				s += "1";
            
			tempCount /= 2;
        }
        
        count++;

        // 사실 제대로 이진법으로 변환하려면 s를 reverse 해줘야하는데 어차피 해당 이진법을 구하는게 아닌 0의 개수, 1의 개수만 따지므로 reverse 하지 않아도 됨.
    }
    
    answer[0] = count;
    answer[1] = sum;
    return answer;
}
*/