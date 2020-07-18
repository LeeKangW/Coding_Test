#include <string>
#include <vector>

// ¸µÅ© : https://programmers.co.kr/learn/courses/30/lessons/12943

using namespace std;


int solution(int num) {
    int answer = 0;
    unsigned long long n = num;
    while (n != 1) {
        if (answer > 500)
            return -1;
        n & 1 ? n = (n * 3) + 1 : n /= 2;
        ++answer;
    }
    return answer;
}