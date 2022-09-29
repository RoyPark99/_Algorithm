#include <string>
#include <vector>
#include <iostream>

using namespace std;
//파보나치 수열 응용
int solution(int n) {
    int answer = 0;
    
    vector<int> arr(2);
    arr[0] = 1;
    arr[1] = 1;
    
    for(int i = 2; i <= n; ++i)
    {
        arr.push_back((arr[i - 1] + arr[i - 2]) % 1000000007);
        //cout << arr[i-1] + arr[i-2] << " ";
    }
    
    answer = arr[n];
    
    return answer;
}