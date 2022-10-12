#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstring>

using namespace std;

string replaceAll(string &m, string from, string to) {
    int pos = 0;
    while((pos = m.find(from)) != -1) // find가 성공이면
        m.replace(pos, from.length(), to);
    return m;
}

void removeSharp(string &m) {
    replaceAll(m, "A#", "a");
    replaceAll(m, "B#", "b");
    replaceAll(m, "C#", "c");
    replaceAll(m, "D#", "d");
    replaceAll(m, "E#", "e");
    replaceAll(m, "F#", "f");
    replaceAll(m, "G#", "g");  
}

vector<string> split(string musicinfos) {
    vector<string> v;
    char *pToken = strtok((char *)musicinfos.c_str(), ",");
    while (pToken) {
        v.push_back(pToken);
        pToken = strtok(NULL, ",");
    }
    return v;
}

int t2m(string s) {
    int h = atoi(s.c_str());
    int m = atoi(s.c_str() + 3);
    return (h * 60) + m;
}

string solution(string m, vector<string> musicinfos) {
    // # 제거
    removeSharp(m);
    
    int maxplaytime = -1;
    string answer = "";
    
    for (int i = 0; i < musicinfos.size(); i++) {
        // 음악 정보 추출 -> 재생시간, 제목, 가사
        vector<string> v = split(musicinfos[i]);
        int playtime = t2m(v[1]) - t2m(v[0]);
        string title = v[2];
        string lyrics = v[3];
        removeSharp(lyrics);
            
        // 실제 재생된 시간만큼 가사 나열
        string runninglyrics = "";
        for(int i = 0; i < playtime / lyrics.size(); i++) runninglyrics += lyrics;
        runninglyrics.append(lyrics.substr(0, playtime % lyrics.size()));
        //cout << playtime << " " << title << " " << lyrics << " " << runninglyrics << endl;
        
        // 가사가 포함 안됐으면 pass=다음 곡 확인
        if (runninglyrics.find(m) == -1)
            continue;
        
        // max가 재생시간보다 같거나 크면 pass=다음 곡 확인
        // 재생된 시간이 긴 것, 같을때는 앞에쪽 음악이
        if (maxplaytime >= playtime)
            continue;

        // 가사가 포함되면서 재생시간이 가장 긴 것으로 갱신
        maxplaytime = playtime;
        answer = title;
    }
    
    if (maxplaytime == -1)
        return "(None)";
    
    return answer;
}