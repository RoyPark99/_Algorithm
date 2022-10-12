#include <string>
#include <vector>
#include <bitset>

using namespace std;

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;

    for (int i = 0; i < numbers.size(); ++i) 
    {
        // 짝수이면 마지막 비트가 0이기 때문에 + 시키면 비트수가 반드시 1개차이로 통과한다.
        if (numbers[i] % 2 == 0)
            answer.push_back(numbers[i] + 1);
        else 
        {
            // 홀수이면 가장 오른쪽 비트가 무조건 1이라서 올림을 고려해야한다.
            // 오른쪽에서부터 연속된 1의 비트의 개수가 f값과 연관이 있다.
            // 101111d의 f값은? -> 101111 -> 110111(f값)
            // 연속된 비트의 개수가 n개라고 할때 n-1자리의 비트 수만큼 더해진게 f값이다.
            long long bit = 1;
            while (true) 
            {
                // 128 64 32 16 84 2 1
                // 1 2 4 8...로 &하면서 연속된 1의 마지막 값을 찾는다.
                if ((numbers[i] & bit) == 0)
                    break;
                
                bit *= 2;
            }
            
            bit = bit / 2;
            answer.push_back(numbers[i] + bit);
        }
    }
    
    return answer;
}

/*
https://programmers.co.kr/learn/courses/30/lessons/77885/solution_groups?language=cpp
홀수를 비트로 표현하면 가장 오른쪽 비트가 무조건 1 이다!
 그렇기 떄문에 홀수는 더했을 때의 ‘올림’을 생각해야 한다.
   1 만 더해주어도 올림이 되어 “최소 2 개의 비트”가 달라지기 때문이다. 가장 오른쪽 비트는 0 이 되며 올림을 통해 왼쪽 비트들의 수가 바뀌기 때    문에 그렇다. 01 👉 10

홀수는 오른쪽에서부터 연속된 1 의 비트의 개수가 f 값과 연관이 있다.
  101111 이렇게 연속된 4 개의 1 비트를 가진 수의 f 값을 찾고자 한다면, 101111 👉 110111 이 되어야 한다. (후자가 f 값)
 
  즉! 연속된 1 비트의 개수가 n 개라고 할 때, n - 1 자리의 비트 수만큼 더해진게 f 값이 된다고 할 수 있겠다. 101111 의 f 값은 000111 를 더   한값이 된다는 것이다.
*/