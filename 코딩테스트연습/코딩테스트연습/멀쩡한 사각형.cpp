// 링크 : https://programmers.co.kr/learn/courses/30/lessons/62048
// 전체를 보는 것이 아닌
// 선이 지나가는 곳이 최대공약수로 나눈 w,h 의 크기로 구분 가능
// 분할해서 볼 줄 알아야 풀 수 있음.
using namespace std;

long long get_gcd(long long w, long long h) {
    // 유클리드 호제법 사용
    // 나머지를 통해 계속해서 계산.
    // 마지막으로 나누어 떨어지는 것이 최대공약수
    while (h != 0) {
        int r = w % h;
        w = h;
        h = r;
    }
    return w;
}
long long solution(int w, int h) {
    long long answer = 1;
    long long total = static_cast<long long>(w) * static_cast<long long>(h);
    
    long long gcd = get_gcd(w, h);

    w /= gcd; h /= gcd;

    answer = total - (w + h - 1) * gcd;
    return answer;
}