#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

// 소수 구하기
bool isPrimenum(int n)
{
    for (int i = 2; i <= n / 2; i++)
        if (n % i == 0)
            return false;
    
    return true;
}

int solution(string numbers) {
    int answer = 0;
    set<int> set;
    
    // next_permutation 사용하려고 오름차순 정렬
    sort(numbers.begin(), numbers.end());
    
    // nPr 구하려고 루프돌림
    for (int r = 1; r <= numbers.size(); r++)
    {
        do
        {
            // 셋에 저장해서 중복 제거
			string temp = "";
			for (int i = 0; i < r; i++)
			{
				temp += numbers[i];
				//cout << numbers[i] << " ";            
			}
			
			set.insert(stoi(temp));

            // nPr형식으로 구하려고 reverse
            reverse(numbers.begin() + r, numbers.end());
        } 
        while (next_permutation(numbers.begin(), numbers.end()));
    }
    
    // set 순회해서 소수인것만 카운트 
    for (auto s : set)
    {
        if (s > 1)
        {
            if (isPrimenum(s))
            answer++;   
        }
    }
    
    return answer;
}