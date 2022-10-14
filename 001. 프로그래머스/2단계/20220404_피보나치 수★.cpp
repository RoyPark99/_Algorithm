#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    // 크기만큼 할당하고 최고 수를 설정한다.
    vector<int> fibonacci(n + 1);
    fibonacci[0] = 0;
    fibonacci[1] = 1;
    
    // 0, 1은 값이 있으니 2부터 루프를 돌려서 차례대로 구한다.
    for(int i = 2; i <= n; i++)
        fibonacci[i] = (fibonacci[i - 1] + fibonacci[i - 2]) % 1234567;
    
    return fibonacci[n];
}