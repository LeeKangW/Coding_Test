#include <string>
#include <vector>

// 링크 : https://programmers.co.kr/learn/courses/30/lessons/12940
// 최대공약수 : 유클리드 호제법
// 최소공배수 : 두 자연수의 곱 / 최대공약수

using namespace std;

int find_CommonFactor(int n,int m) {
    int r;
    if (n >= m) {
        while (m != 0) {
            r = n % m;
            n = m;
            m = r;
        }
        return n;
    }
    else {
        while (n != 0) {
            r = m % n;
            m = n;
            n = r;
        }
        return m;
    }
}
int find_CommonMultiple(int n, int m) {
    return n * m / find_CommonFactor(n, m);
}
vector<int> solution(int n, int m) {
    vector<int> answer;
    answer.push_back(find_CommonFactor(n, m));
    answer.push_back(find_CommonMultiple(n, m));
    return answer;
}