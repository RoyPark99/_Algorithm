#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 20221007리뷰 : 두 배열의 원소로 최소값을 만드는데 목적이 있다.
int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    
    // 각 배열을 오름차순으로 정렬시킨다.
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    // 앞, 뒤 값의 곱셈의 누적이 최소값이다. (A앞자리 * B뒷자리) = 최소값
    for (int i = 0; i < A.size(); i++)
        answer += (A[i] * B[B.size() - 1 - i]);

    return answer;
}