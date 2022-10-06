#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

vector<int> solution(long long begin, long long end) {
    int count = 0;
    vector<int> answer;
    // 주어진 범위내에서
    for (int i = begin; i <= end; i++)
    {
        // 1인 경우만 0 추가
        if (i == 1) {
            answer.push_back(0);
            continue;
        }
        
        count = 0;
            
        // 2, 4, 9, 16, 25 ~ bgein
        for(int j = 2; j <= sqrt(i); j++) 
        {
            // j로 나눠지는 첫번째에서, i / j한 값이
            // 블록번호 % j로 떨어지면 첫번째 약수, 블록번호 / 약수 <= 블록제한 이면 나눠지는 가장 작은 약수이다.
            if(i % j == 0 && i / j <= 10000000) 
            {
                answer.push_back(i / j);
                count++;
                break;
            }
        }
    
       // 약수가 없으면 소수이므로 1추가
       if(count == 0)
            answer.push_back(1);
    }
    

    return answer;
}
