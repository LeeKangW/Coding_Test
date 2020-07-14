#include <string>
#include <vector>
#include <math.h>
// 링크 : https://programmers.co.kr/learn/courses/30/lessons/12921
// 에라토스테네스의 체 사용해야 함.
// 소수 구하기 아주 좋은 문제.
using namespace std;

int solution(int n) {
    int answer = 0;

    // 0과 1은 소수가 아니니 0으로 설정
    // 0 -> 소수아님
    // 0 이 아니면 소수

    vector<int> num = { 0,0 };

    // 2 이상부터 인덱스에 맞춰서 세팅
    for (int i = 2; i <= n; ++i) {
        num.push_back(i);
    }

    // 에라토스테네스의 채 사용
    for (int i = 2; i <= n; ++i) {
        if (num[i] == 0)continue;

        for (int j = 2 * i; j <= n; j += i) {
            num[j] = 0;
        }
    }

    // 0이 아닌 것이 소수이기에 0이 아닌 것을 찾기.
    for (int i = 0; i < num.size(); ++i) {
        if (num[i] != 0)
            ++answer;
    }

    return answer;
}