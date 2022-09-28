#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

// 자신과 1로만 나눠지는 수
bool isPrime(long long num) {
    if(num < 2)
        return false;
    for(int i = 2; i <= sqrt(num); ++i) {
        if(num % i == 0)
            return false;
    }
    return true;
}

int solution(int n, int k) {
    int answer = 0;
    // 해당 진수로 변환
    string s = "";
    while(n > 0) {
       s += to_string(n % k);
       n /= k;
    }
    reverse(s.begin(), s.end());
    
    //cout << s;
    // 
    string tmp = "";
    for (char c : s) { 
        if (c == '0') { 
            if (!tmp.empty() && isPrime(stoll(tmp))) {
                answer++; 
            } 
            tmp = ""; 
        } 
        else tmp += c; 
    }
    
    if (!tmp.empty() && isPrime(stoll(tmp))) {  //마지막꺼 
        answer++;
    } 
    
    return answer;
}