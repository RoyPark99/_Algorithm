#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int red) {
    int len = brown / 2 + 2;
    int w = len - 3;
    int h = 3;
    while(w >= h) {
        if(w * h == (brown + red)) 
            break;
        w--;
        h++;
    }
    return vector<int>{w, h};
}

/*
vector<int> solution(int brown, int yellow) {
    
    vector<int> answer;
    // 가로 + 세로 길이
    int WidthHeight = (brown + 4)/2;
    // 최소 가로 길이
    int MinWidth = WidthHeight / 2;
    // 최대 가로 길이
    int MaxWidth = WidthHeight - 3;
    
    // 최대 가로 길이부터 최소 가로 길이까지의 카펫에 대해서 노란색 격자의 수와 일치 여부 확인.
    for (int width = MaxWidth; width >= MinWidth; width--) {
        // 가로+세로길이 - 가로 = 세로길이
        int height = WidthHeight - width;
        // 노란색 개수
        int innerCnt = (width - 2) * (height - 2);
        if (yellow == innerCnt) {
            answer.push_back(width);
            answer.push_back(height);
            break;
        }
    }
    
    return answer;
}
*/