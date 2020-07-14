#include <string>
#include <vector>

// ¸µÅ© : https://programmers.co.kr/learn/courses/30/lessons/12928

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<int> num;
    num.reserve(1500);
    for (int i = 1; i < n; ++i) {
        if (n % i == 0)
            num.push_back(i);
    }
    num.push_back(n);

    for (int i : num)
        answer += i;

    return answer;
}