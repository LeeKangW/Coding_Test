#include <string>
#include <vector>
#include <algorithm>

// ¸µÅ© : https://programmers.co.kr/learn/courses/30/lessons/12910

using namespace std;

vector<int> solution(vector<int> arr, int divisor) {
    vector<int> answer;
    bool ischeck = false;
    for (int n : arr) {
        if (n % divisor == 0) {
            ischeck = true;
            answer.push_back(n);
        }
    }
    if (!ischeck)
        answer.push_back(-1);
    else
        sort(answer.begin(), answer.end());
    return answer;
}

