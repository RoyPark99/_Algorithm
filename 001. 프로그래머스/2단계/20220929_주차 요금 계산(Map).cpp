#include <string>
#include <vector>
#include <iostream>
#include <cstring>
#include <map>
#include <algorithm>

using namespace std;

typedef struct _INFO {
    string time;
    string status;
    int accumTime;
} INFO;

vector<string> getToken(string str, char *delimit) {
    vector<string> tmp;
    char *pToken = strtok((char*)str.c_str(), delimit);
    while (pToken)    {
        tmp.push_back(pToken);
        pToken = strtok(NULL, delimit);
    }
    return tmp;
}

int time_diff(string in, string out) {
    int h1 = stoi(in.substr(0, 2));
    int m1 = stoi(in.substr(3, 2));
    int h2 = stoi(out.substr(0, 2));
    int m2 = stoi(out.substr(3, 2));
    int diff = (h2-h1)*60 + (m2-m1);
    return diff;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    map<string, INFO> m;
    vector<int> answer;
    for (auto vec : records)    {
        vector<string> tmp = getToken(vec, " ");
        if (tmp.size() == 3) {   
            auto find = m.find(tmp[1]);
            if (find != m.end()) {
                if (find->second.status == "IN" && tmp[2] == "OUT") {
                    find->second.status = tmp[2];
                    find->second.accumTime += time_diff(find->second.time, tmp[0]);
                }
                else if (find->second.status == "OUT") {
                    find->second.status = tmp[2];
                    find->second.time = tmp[0];
                }
            }
            else
                m.insert({tmp[1], (INFO){tmp[0], tmp[2], 0}});                
        }
    }
    // 요금 계산
    for (auto &map : m)    {
        if (map.second.status == "IN") {
            map.second.accumTime += time_diff(map.second.time, "23:59");
            if (map.second.accumTime > fees[0]){
                int overtime = map.second.accumTime - fees[0];
                if (overtime % fees[2])                {
                    overtime -= (overtime % fees[2]);
                    overtime += fees[2];
                }
                overtime /= fees[2];
                answer.push_back(overtime * fees[3] + fees[1]);
            }
            else
                answer.push_back(fees[1]);
        }
        else
        {
            // 기본 요금 초과이면 계산해서 넣는다.
            if (map.second.accumTime > fees[0]){
                int overtime = map.second.accumTime - fees[0];
                if (overtime % fees[2])                {
                    overtime -= (overtime % fees[2]);
                    overtime += fees[2];
                }
                overtime /= fees[2];
                answer.push_back(overtime * fees[3] + fees[1]);
            }
            else
                answer.push_back(fees[1]);
        }
    }
    
 // for (auto map : m) cout << map.first << ", " << map.second.time << ", " << map.second.status << ", " << map.second.accumTime << endl;
    return answer;
}