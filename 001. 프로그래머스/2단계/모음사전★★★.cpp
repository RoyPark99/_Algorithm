/*
#include <string>
#include <vector>
#include <map>

using namespace std;

int count = 1;
vector<string> alpha = {"A", "E", "I", "O", "U"};
map<string, int> voca;

void dfs(string w)
{
    if (w.length() > 5)
        return;

    // 맵에 넣거나 카운트 올린다.
    voca[w] = count++;
    
    for (auto s : alpha)
        dfs(w + s);
}

int solution(string word) {
    // 모든 경우의 수 계산
    for (auto s : alpha)
        dfs(s);
        
    return voca[word];
}
*/


#include <string>
using namespace std;
int solution(string word) {
    string v = string("AEIOU");
    int a = word.size();

    for(int i = 0, b = 1; i < word.size(); i++, b *= 5)
        a += v.rfind(word[i]) * 781 / b;

    return a;
}


/*
class Solution {
    public int solution(String word) {
        int answer = 0;
        // 종 문자열 길이 
        int length = word.length();
        // 종류의 수
        int numberOfWords = 5;
        // 경우의 수 총합 
        int max = 0;
        for(int i = 1; i <= numberOfWords; i++) {
            max += Math.pow(numberOfWords, i);
        }
        //  ['A', 'E', 'I', 'O', 'U'] 순서 [0, 1, 2, 3, 4]
        for (int i = 1; i <= length; i++) {
            if (word.charAt(i-1) == 'A') {
                answer += 1;
            } else if (word.charAt(i-1) == 'E') {
                answer += ((max / Math.pow(numberOfWords, i)) * 1) + 1;
            } else if (word.charAt(i-1) == 'I') {
                answer += ((max / Math.pow(numberOfWords, i)) * 2) + 1;
            } else if (word.charAt(i-1) == 'O') {
                answer += ((max / Math.pow(numberOfWords, i)) * 3) + 1;
            } else {
                answer += ((max / Math.pow(numberOfWords, i)) * 4) + 1;
            }
        }

        return answer;
    }
}
*/