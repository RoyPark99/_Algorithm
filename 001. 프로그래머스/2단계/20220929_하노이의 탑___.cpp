#include string
#include vector

using namespace std;

void HanoiTower(vectorvectorint& answer, int n, int start, int dest) {
     원판이 하나이면 바로 이동하고 끝
    if (n == 1) {
        answer.push_back({ start, dest });
        return;
    }
    
     원판을 시작에서 
    HanoiTower(answer, n - 1, start, 6 - start - dest);
    answer.push_back({ start, dest });
    HanoiTower(answer, n - 1, 6 - start - dest, dest);
}

vectorvectorint solution(int n) {
    vectorvectorint answer;
    HanoiTower(answer, n, 1, 3);
    return answer;
}