#include <string>
#include <vector>

// 링크 : https://programmers.co.kr/learn/courses/30/lessons/42842
// 문제에 정답이 여러개 일수도 있는 에러..?

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;

    int sum = brown + yellow;

    for(int col = 3;; ++col) {
        if (!(sum % col)) {
            int row = sum / col;

            if ((col - 2) * (row - 2) == yellow) {
                answer.push_back(row);
                answer.push_back(col);
                break;
            }
        }
    }
    return answer;
}

int main() {
    solution(24,24);
}