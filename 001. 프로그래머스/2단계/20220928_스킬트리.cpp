#include <string>
#include <vector>
#include <iostream>

using namespace std;
// deny리스트에 있으면 true
bool isDeny(string &s, char c){
    for (auto s2 : s)        {
        if (s2 == c)
            return true;
    }
    
    return false;
}

int solution(string skill, vector<string> skill_trees) {
    string denysk = skill;
    int answer = 0;
    for (auto vec : skill_trees)    {
        bool succ = true;
        for (auto str : vec)        {
            // 불가 리스트에 없으면 계속진행...
            if (!isDeny(denysk, str)) {
                continue;
            }
            else {
                // 불가 리스트 매치, 첫 스킬트리면 계속진행...
                if (!skill.empty()) {
                    if (skill.front() == str) {
                        //cout << skill << " ";
                        skill.erase(skill.begin());
                        
                        if (skill.empty())
                            break;
                        
                        continue;
                    }
                    else {
                        //cout << skill.front() << " " << str << ", \n";
                        // 매치됐는데 첫번째가 아니면 불가한 스킬트리
                        succ = false;
                        break;
                    }
                }
            }
        }
        
        skill = denysk;
        if (succ)
            answer++;
    }
    
    return answer;
}