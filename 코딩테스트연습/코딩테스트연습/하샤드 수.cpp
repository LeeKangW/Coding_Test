#include <string>
#include <vector>

// ¸µÅ© : https://programmers.co.kr/learn/courses/30/lessons/12947

using namespace std;

bool solution(int x) {
    bool answer = true;
    int n = x;
    int sum = 0;
    while (n !=0) {
        sum += n % 10;
        n /= 10;
    }
    x % sum == 0 ? answer = true : answer = false;
    return answer;
}