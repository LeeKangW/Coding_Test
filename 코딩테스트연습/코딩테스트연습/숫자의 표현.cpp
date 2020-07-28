#include <string>
#include <vector>

// ¸µÅ© : https://programmers.co.kr/learn/courses/30/lessons/12924

using namespace std;
int solution(int n) {
    int answer = 0;
    int start = 1;
    int num = 1;
    int sum = 0;
    while (num <= n) {
        if (sum > n) {
            ++num;
            start = num;
            sum = 0;
        }
        else if (sum == n) {
            ++answer;
            ++num;
            start = num;
            sum = 0;
        }
        else {
            sum += start;
            start += 1;
        }

    }
    return answer;
}