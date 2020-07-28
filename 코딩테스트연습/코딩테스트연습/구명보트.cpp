#include <string>
#include <vector>
#include <algorithm>
// ��ũ :https://programmers.co.kr/learn/courses/30/lessons/42885

// �����ؾ��� ��.
// �������� �ִ� 2�� �¿� �� �ִٰ� ��...
// ���� ���� �Ͱ� ū ���� ���ؼ� �ּ� Ƚ���� ���ϸ� ��.
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