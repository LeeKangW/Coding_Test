#include <string>
#include <vector>

// ¸µÅ© : https://programmers.co.kr/learn/courses/30/lessons/12954

using namespace std;

vector<long long> solution(int x, int n) {
    vector<long long> answer;
    for (int i = 0; i < n; ++i)
        answer.push_back(x + (i * x));
    return answer;
}