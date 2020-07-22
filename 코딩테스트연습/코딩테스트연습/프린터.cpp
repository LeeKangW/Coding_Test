#include <string>
#include <vector>
#include <queue>
#include <utility>

// 링크 : https://programmers.co.kr/learn/courses/30/lessons/42587
// 우선순위 큐를 잘 사용하자.
using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    priority_queue<int> pq;
    queue<pair<int, int>> q;

    int size = priorities.size();

    for (int i = 0; i < size; ++i) {
        q.push(make_pair(i, priorities[i]));
        pq.push(priorities[i]);
    }

    while (!q.empty()) {
        int idx = q.front().first;
        int prior = q.front().second;
        q.pop();

        if (prior == pq.top()) {
            pq.pop();
            ++answer;
            if (idx == location)
                break;
        }
        else {
            q.push(make_pair(idx, prior));
        }
    }

    return answer;
}

int main() {
    vector<int> v = { 1,1,9,1,1,1 };
    solution(v, 0);
}