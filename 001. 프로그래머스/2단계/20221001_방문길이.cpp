#include <string>
#include <map>
#include <iostream>
using namespace std;

int solution(string dirs) {
    map<string, int> m;
    int x = 0;
    int y = 0;
    for (int i = 0; i < dirs.length(); ++i) {
        // 시작 위치 만들기
        string from = to_string(y) + "," + to_string(x);
        switch(dirs[i]) {            
            case 'U':
                y--;
                break;
            case 'D':
                y++;
                break;
            case 'R':
                x++;
                break;
            case 'L':
                x--;
                break;
         }
        
        //범위를 벗어나면 최대값으로 셋팅
        if (y < -5) {
            y = -5;
            continue;
        }
        if (x < -5) {
            x = -5;
            continue;
        }
        if (y > 5) {
            y = 5;
            continue;
        }
        if (x > 5) {
            x = 5;
            continue;
        }
        
        // 도착 위치 만들고, 맵에 넣으면 중복된 값의 경우 추가가 안된다.
        string to = to_string(y) + "," + to_string(x);
        m.insert(make_pair("(" + from + ")->(" + to + ")", 1));
        m.insert(make_pair("(" + to + ")->(" + from + ")", 1));
    }
    
    return m.size() / 2;
}