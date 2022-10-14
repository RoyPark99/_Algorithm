#include <string>
#include <vector>
#include <bitset>
#include <cstdio>

using namespace std;

char IntToChar(int num) {
    switch (num) {
        case 0: case 1: case 2: case 3: case 4:
        case 5: case 6: case 7: case 8: case 9:
            return '0' + num;
        case 10:
            return 'A';
        case 11:
            return 'B';
        case 12:
            return 'C';
        case 13:
            return 'D';
        case 14:
            return 'E';
        case 15:
            return 'F';
    }
}

int CharToInt(char num) {
    switch (num) {
    case '0': case '1': case '2': case '3': case '4':
    case '5': case '6': case '7': case '8': case '9':
        return num - '0';
    case 'A':
        return 10;
    case 'B':
        return 11;
    case 'C':
        return 12;
    case 'D':
        return 13;
    case 'E':
        return 14;
    case 'F':
        return 15;
    }
}

string solution(int n, int t, int m, int p) {
    string answer = "";

    string prevNum = "0";
    string totalStr = "0";
    while (totalStr.length() < t * m) {
        for (int i = prevNum.length() - 1; i >= -1; --i) {
            if (i == -1) {
                prevNum = "1" + prevNum;
                break;
            }

            int num = CharToInt(prevNum[i]);
            if (num + 1 == n) 
                prevNum[i] = '0';
            else {
                prevNum[i] = IntToChar(num + 1);
                break;
            }
        }
        totalStr += prevNum;
    }

    int count = 0;
    for (int i = 0, count = 0; count < t; i++) {
        if (i % m == p - 1){
            count++;
            answer += totalStr[i];
        }
    }

    return answer;
}

/*
string solution(int n, int t, int m, int p) {
    string answer = "";
    
    vector<pair<int, string>> num;
    for (int i = 0; i < t; i++)
    {
        // 2진법 일때 미리 구하고
        if (n == 2)
        {
            bitset<20> b(n);
            unsigned long temp = b.to_ulong();
            num.push_back(make_pair(i, to_string(temp)));
        }
        else if (n == 16)
        {
            // 16진법 일때 미리 구한다.
            char szBuff[200];
            sprintf(szBuff, "%X", i);
            num.push_back(make_pair(i, szBuff));
        }
    }
    
    int tube = fa
    for (int i = 0; i < num.size(); i++)
    {
        if ()
        {
            
        }
        answer += 
    }
        
    return answer;
}
*/