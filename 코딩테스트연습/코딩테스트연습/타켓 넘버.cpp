#include <string>
#include <vector>

// 링크 : https://programmers.co.kr/learn/courses/30/lessons/43165
// 재귀에 대해 잘 이해해야 하는데 공부가 필요.

using namespace std;


int answer = 0;

void dfs(vector<int>& numbers, int target, int sum, int count) {
    if (count == numbers.size()) {
        if (sum == target) ++answer;
        return;
    }
    dfs(numbers, target, sum + numbers[count], count + 1);
    dfs(numbers, target, sum - numbers[count], count + 1);

}
int solution(vector<int> numbers, int target) {
    dfs(numbers, target, 0, 0);
    return answer;
}
int main() {
    vector<int> v = { 1,1,1,1,1 };
    solution(v, 3);
}