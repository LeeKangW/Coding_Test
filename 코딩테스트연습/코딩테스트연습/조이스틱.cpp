#include <string>
#include <vector>
#include <utility>
// 링크 : https://programmers.co.kr/learn/courses/30/lessons/42860

// 문제가 이상함.

#define MIN 65
#define MAX 90

using namespace std;

pair<int,int> check_greedy(int cur,int target) {
    int left_count = 0, right_count = 0;
    int num = cur;
    // 처음은 왼쪽
    while (num != target) {
        if (num == MIN)
            num = MAX;        
        else
            --num;
        ++left_count;
    }
    num = cur;
    while (num != target) {
        if (num == MAX)
            num = MIN;
        else
            ++num;
        ++right_count;
    }
    
    pair<int, int> p;
    left_count > right_count ? p= make_pair(target, right_count) : p=make_pair(target, left_count);
    return p;

}
int solution(string name) {
    int answer = 0;
    int start = MIN;
    pair<int, int> p;
    for (const char& c : name) {
        int n = c;
        p = check_greedy(start, n);
        start = p.first;
        answer += p.second;
    }
    
    return answer;
}

int main() {
    solution("JEROEN");
}