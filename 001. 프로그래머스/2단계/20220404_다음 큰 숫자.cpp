#include <string>
#include <vector>
#include <bitset>

using namespace std;

// 20221007리뷰 : 자연수n의 다음 큰 숫자는 2진수의 1의 개수가 같으면서 다음으로 큰 숫자이다.
int solution(int n) {
    // 먼저 2진수로 변환하고(백만은 비트로2 0자리)
    int num = bitset<20>(n).count();
    // 자연수n 을 +1시켜서 비트1의 개수를 세면서 num의 카운트와 같으면 다음 큰 숫자이다.
    while (bitset<20>(++n).count() != num);
    return n;
}