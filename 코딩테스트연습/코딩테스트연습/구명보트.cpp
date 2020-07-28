#include <string>
#include <vector>
#include <algorithm>
// 링크 :https://programmers.co.kr/learn/courses/30/lessons/42885

// 조심해야할 것.
// 문제에서 최대 2명만 태울 수 있다고 함...
// 제일 작은 것과 큰 것을 비교해서 최소 횟수를 구하면 됨.
using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    int left_idx = 0, right_idx = people.size() - 1;
    sort(people.begin(), people.end());

    while (left_idx < right_idx) {
        if (people[left_idx] < 40) {
            left_idx += 1;
            continue;
        }
        if (people[right_idx] > 240) {
            right_idx -= 1;
            continue;
        }

        if (people[left_idx] + people[right_idx] <= limit) {
            left_idx += 1;
            right_idx -= 1;
            ++answer;
        }
        else {
            right_idx -= 1;
            ++answer;
        }
    }
    if (left_idx == right_idx)
        ++answer;

    return answer;
}

int main() {
    vector<int> v = { 70,50,80,50 };
    solution(v, 100);
}