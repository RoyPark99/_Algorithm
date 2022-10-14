#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cctype>
#include <cstdio>
#include <cstring>

using namespace std;

typedef struct _FILE_INFO {
    string Head;
    int Num;
    string Tail;
} FILE_INFO, *PFILE_INFO;

typedef vector<pair<string, FILE_INFO>> FILE_VEC;

void getToken(FILE_INFO &fi, char *pstr, int size){
    for (int i = 0; i < size; i++)    {
        if (isdigit(pstr[i]))        {
            char c = pstr[i];
            pstr[i] = '\0';
            fi.Head = pstr;
            pstr[i] = c;
            fi.Num = stoi(&pstr[i]);
            //cout << fi.Head << " " << fi.Num << " \n";
            break;
        }
    }
    
    char szNum[10];
    sprintf(szNum, "%d", fi.Num);
    char *pToken = strstr(pstr, szNum);
    if (pToken)    {
        pToken += strlen(szNum);
        fi.Tail = pToken;
        //printf("%s ", pToken);
    }
}

bool cmp(const pair<string, FILE_INFO> &t1, const pair<string, FILE_INFO> &t2){
    if (t1.second.Head < t2.second.Head)// 오름차순
        return true;
    else if (t1.second.Head > t2.second.Head) // 오름차순
        return false;
    else
        return t1.second.Num < t2.second.Num;
}

vector<string> solution(vector<string> files) {
    vector<string> answer;
    FILE_VEC v;
    for (auto vec : files)    {
        string tmp = vec;
        transform(tmp.begin(), tmp.end(), tmp.begin(), ::tolower);
        char *pfile = (char*) tmp.c_str();
        FILE_INFO fi;
        getToken(fi, pfile, tmp.length());
        v.push_back(make_pair(vec, fi));
        //cout << vec << ", (" << fi.Head << " " << fi.Num << " " << fi.Tail << ") " << endl;
    }
    
    stable_sort(v.begin(), v.end(), cmp);
    //cout << endl;
    for (auto vec : v)
    {
        //cout << vec.first << ", (" << vec.second.Head << " " << vec.second.Num << " " << vec.second.Tail << ") " << endl;
        answer.push_back(vec.first);
    }
    
    return answer;
}