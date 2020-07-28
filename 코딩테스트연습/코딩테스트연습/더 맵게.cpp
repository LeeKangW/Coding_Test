#include <string>
#include <vector>
#include <queue>
#include <algorithm>
// ¸µÅ© : https://programmers.co.kr/learn/courses/30/lessons/42626

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<long long, vector<long long>,greater<long long>> pq;

    if (K == 0) return answer;

    for (const int& i : scoville)
        pq.push(static_cast<long long>(i));

    while (pq.top() < K) {
        if (pq.size() == 1)
            return -1;
        long long n[2];
        n[0] = pq.top(); pq.pop();
        n[1] = pq.top(); pq.pop();

        long long num = n[0] + n[1] * 2;
        pq.push(num);
        ++answer;
    }

    return answer;
}

int main() {
    vector<int> v = { 1,2,3,9,10,12 };
    solution(v, 7);
}