using namespace std;

long long solution(int w,int h) {
    long long answer = 1;
    
    long long width = w;
    long long height = h;
    
    // 직사각형의 대가선이 가로지르는 사각형들은 일저한 패턴이 반복된다.
    // 이패턴이 반복되는 횟수가 가로 세로의 GCD
    //-> GCD(12, 8) = 4
    //- 이 패턴의 가로 세로 길이가 각각 w / gcd, h / gcd 이다.
    //-> 8 / 4 = 2, 12 / 4 = 3
    //- 대각선이 지나는 칸은 한줄에 1칸 ~2칸 존재할 수 있다.
    //- 대각선이므로 세로줄기준 최소 1칸은 차지할수 밖에 없다.
    //->h / gcd = 12 / 4 = 3
    //- 하지만 가로줄기준 2칸을 차지하는 경우는 w / gcd - 1 이다.
    //->w / gcd - 1 = 8 / 4 - 1 = 2 - 1 = 1
    //
    //= > 최종식
    //- w * h - [{ (w / gcd) + (h / gcd) - 1 } *gcd]
    //- w * h - (w + h - gcd)
    if (w == h)
        return width * height - width;
    else
    {
        long long a = width;
        long long b = height;
        long long c;
        
        while (b != 0)
        {
            c = a % b;
            a = b;
            b = c;
        }
        
        long long gcd = a;
        
        answer = (width * height) - (((width / gcd) + (height / gcd) - 1) * gcd);
    }
    
    return answer;
}