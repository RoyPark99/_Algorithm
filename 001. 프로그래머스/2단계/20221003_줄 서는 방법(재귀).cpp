#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
// n! 구하기
long long perm(int n){
    if (n == 0) return 1;
    return n * perm(n - 1);
}

void func(vector<int>& v, vector<int>& answer, long long& k){
    // 사이즈가 1이면 현재값을 넣는다.
    if (v.size() == 1) {
        answer.push_back(v[0]);
        return;
    }

    // 경우의수 구하기(v에서 첫자리수를 뺀 경우의 수)
    long long p = perm(v.size() - 1); 
    //
    for (int i = 1; i <= v.size(); ++i) {
        // i * p 는 첫자리 뺀 값의 경우의수이고 이게 k보다 크면, 4! -> 6, 12, 18, 24
        if (i * p >= k) {
            // i번째기 때문에 인덱스론 i-1, 첫번째 자리는 그냥 구해지고(인덱스로)
            answer.push_back(v[i - 1]);
            // 넣었으니 나머지 중에서 경우의수 구하기 위해서 첫자리 지워준다.
            v.erase(v.begin() + i - 1);
            // 나머지의 경우의수 * k
            k = k - (i - 1) * p;
            func(v, answer, k);
        }
    }
}

// https://ansohxxn.github.io/programmers/105/
vector<int> solution(int n, long long k){
    // k값으로 앞 자리를 유추하여 해당 경우의 수를 줄인다.
    vector<int> answer;
    vector<int> v(n);
    for (int i = 0; i < n; ++i)
        v[i] = i + 1;
    func(v, answer, k);
    return answer;
}

/*
// 실패, 시간초과
vector<int> solution(int n, long long k) {
    vector<int> v;
    for (int i = 1; i <= n; i++)
        v.push_back(i);
    
    vector<int> answer;
    int cnt = 1;
    do	{
        if (cnt == k) {
            for(int i = 0; i < v.size(); i++)
                answer.push_back(v[i]);
            break;
        }

        cnt++;
	}while(next_permutation(v.begin(),v.end()));
    
    return answer;
}
*/