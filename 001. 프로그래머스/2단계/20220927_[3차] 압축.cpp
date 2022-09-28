#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

map<string, int> dic;
void initDic(){
    for (int i = 'A'; i <= 'Z'; i++)    {
        dic.insert(make_pair(string {(char)i}, i - (char)'A' + 1));
    }
    //for (auto m : dic)        cout << m.first << m.second << " ";
}

vector<int> solution(string msg) {
    initDic();
    vector<int> answer;
    string tmp = "";
    for (int i = 0; i < msg.length(); )    {
        tmp += msg[i];
        //cout << tmp << endl;
        // 사전에 없으면 현재값 인덱스 넣어주고, 이전 문자열로 찾기해서 답에 넣어주고 초기화.
        if (dic.find(tmp) == dic.end())        {
            dic.insert(make_pair(tmp, dic.size() + 1));
            tmp.pop_back();
            answer.push_back(dic[tmp]);
            tmp = "";
        }
        else
            // 사전에 있으면 인덱스만 올려주고 다음 문자열과 합쳐서 사전검색한다. 
            //이때 없으면 사전에 추가하고 이전 문자값으로 사전 찾아서 답에 넣는다.
            i++;
    }
    answer.push_back(dic[tmp]);
    return answer;
}