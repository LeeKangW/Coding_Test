#include <string>
#include <vector>

/**
* @Tip : 피보나치 수열 문제
* @See : https://programmers.co.kr/learn/courses/30/lessons/12914?language=cpp
*/

using namespace std;

long long solution(int n)
{
    long long answer = 0;

    int num[2000] = { 0, };
    num[0] = 1;
    num[1] = 2;

    for (size_t i = 2; i < n; ++i)
        num[i] = (num[i - 1] + num[i - 2])%1234567;

    answer = num[n - 1];
    return answer;
}

int main()
{
    solution(4);
}