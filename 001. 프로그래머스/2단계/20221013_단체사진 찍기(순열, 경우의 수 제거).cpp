#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstdlib>

using namespace std;

bool isPossible(int &diff, char &opcode, int &operland) {
    if (opcode == '=')        return diff == operland;
    else if (opcode == '>')     return diff > operland;
    return diff < operland;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<string> data) {
    int answer = 0;
    string friends = "ACFJMNRT";
    do {
        // 프렌즈 8명의 경우의 수를 구한다.
        
        bool pass = true;
        for (string &condi : data) {
            // 조건에서 맞지 않은게 나오면 이번 경우의 수는 만족하지 않는 것이다.
            int firstIndex = friends.find(condi[0]);
            int secondIndex = friends.find(condi[2]);
            int diff = abs(firstIndex - secondIndex) - 1;
            int num = condi[4] - '0';
            
            // 가능한 경우의 수인지 보고 불가능하면 해당 루프는 중단하고 다음 경우의 수를 확인한다.
            if (!isPossible(diff, condi[3], num)) {
                pass = false;
                break;
            }
        }
        
        if (pass)
            answer++;
    } while(next_permutation(friends.begin(), friends.end()));
    return answer;
}