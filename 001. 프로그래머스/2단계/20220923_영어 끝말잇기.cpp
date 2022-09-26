#include <string>
#include <vector>
#include <iostream>
#include <set>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    set<string> saidword;
    int veccnt = words.size();
    int round = (veccnt % n) == 0 ? veccnt / n : veccnt / n + 1;   
    string preword = "";
    int wordcnt = 0;
    for (int i = 0; i < round; i++) {
        for (int j = 0; j < n; j++) {  
            if (words.size() <= wordcnt) break;
            if (i == 0 && j == 0) {
                preword = words[wordcnt];
                saidword.insert(words[wordcnt]);
                wordcnt++;
                continue;
            }
            // 이전에 말했던 단어이거나, 끝말이식 규칙에 어긋나면 중단...
            if (saidword.find(words[wordcnt]) != saidword.end() || preword.back() != words[wordcnt].front())
                return vector<int>{j + 1, i + 1};
            else {
                preword = words[wordcnt];
                saidword.insert(words[wordcnt]);
            }
            
            wordcnt++;
        }
    }

    return vector<int>{0,0};
}