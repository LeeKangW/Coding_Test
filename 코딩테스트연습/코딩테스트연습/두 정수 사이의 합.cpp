#include <string>
#include <vector>

// ¸µÅ© : https://programmers.co.kr/learn/courses/30/lessons/12912
using namespace std;

long long solution(int a, int b) {
    long long answer = 0;

    if (a <= b) {
        for (int i = a; i < b + 1; ++i)
            answer += i;
    }
    else
    {
        for (int i = a; i > b-1; --i)
            answer += i;
    }
    return answer;
}

int main() {
    solution(5, 3);
}