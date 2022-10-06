#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

long long calculate(long long a, long long b, char op) {
    if (op == '+')        return a + b;
    else if (op == '-')        return a - b;
    else if (op == '*')        return a * b;
}

long long solution(string expression) {
    long long answer = 0;

    vector<long long> record_operand;
    vector<char> record_operator;
    string temp = "";
    for (int i = 0; i < expression.length(); i++) {
        // 숫자이면 누적
        if (expression[i] >= '0' && expression[i] <= '9')
            temp += expression[i];
        // 연산자이면 벡터에 넣고 초기화하면서 모든 값을 넣는다.
        else {
            record_operator.push_back(expression[i]);
            record_operand.push_back(stoll(temp));
            temp = "";
        }
    }
    
    // 마지막 값 추가
    record_operand.push_back(stoll(temp));

    vector<int> perm = { 0, 1, 2 };
    string op = "+-*";
    do {
        // 조합으로 돌린다.
        for(int i = 0; i < perm.size(); i++) 			cout << op[perm[i]] << " ";		cout << '\n';
        
        vector<long long> temp_operand = record_operand;
        vector<char> temp_operator = record_operator;
        
        // 순열로 돌린 연선자 우선순위 대로...
        for (int i = 0; i < perm.size(); i++) 
        {
            // 문제의 연선자 순서대로 계산을 한다.
            for (int j = 0; j < temp_operator.size(); ) 
            {
                // 연선자 우선수위에 해당하는 경우
                if (temp_operator[j] == op[perm[i]]) 
                {
                    // 0 1 2 3 4 << 숫자 인덱스
                    //  0 1 2 3  << 연산자 인덱스
                    // j가 0이면, 왼쪽은 0, 오른쪽은 0 + 1 = 계산값
                    long long res = calculate(temp_operand[j], temp_operand[j + 1], temp_operator[j]);
                    cout << temp_operand[j] << " " << temp_operator[j] << " " << temp_operand[j + 1] << " = " << res << endl;

                    // 연산한 숫자 2개를 지워준다.
                    temp_operand.erase(temp_operand.begin() + j);
                    temp_operand.erase(temp_operand.begin() + j);
                    // 연산한 숫자 2개의 자리에 합쳐진 값을 넣는다.
                    temp_operand.insert(temp_operand.begin() + j, res);
                    // 연산한 연산자는 제거한다.
                    temp_operator.erase(temp_operator.begin() + j);
                }
                else
                    // 매치되는 연산자가 아니면 다음번을 확인한다.
                    // temp_operator는 연산하면 하나씩 제거 되기 때문에 결국 멈춘다.
                    j++;
            }
            
            //cout << endl;
        }
        
        // 위에서 연산이 끝나면 항상 1개의 결과만 남는데 answer와 비교해서 최대값으로만 갱신한다.
        answer = max(answer, abs(temp_operand[0]));
    } while (next_permutation(perm.begin(), perm.end()));

    return answer;
}