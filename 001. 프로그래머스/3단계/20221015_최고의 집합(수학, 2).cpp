#include <string>
#include <vector>
#include <iostream>

using namespace std;

// 20221015 : 원소의 곱이 최대가 되려면 원소간에 차이가 가장 작아야 최대값이 된다.
vector<int> solution(int n, int s) {
    vector<int> answer;

    // n이 크면 큰 값으로 작은 값을 나눌수 없으니 예외
    if (n > s)
        return {-1};
    
    int quotient = s / n;
    int remainder = s % n;
    cout << quotient << ", " << remainder << endl;
    // n개만큼 몫으로 채운다.
    answer.assign(n, quotient);
    
    for (int i = answer.size() - 1; i >= 0 && remainder > 0; i--)
    {
        answer[i]++;
        remainder--;
    }
    
    return answer;
}