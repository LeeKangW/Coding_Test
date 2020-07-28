#include <string>
#include <vector>
#include <algorithm>
// ¸µÅ©  : https://programmers.co.kr/learn/courses/30/lessons/42747

using namespace std;

int solution(vector<int> citations) {
    sort(citations.begin(), citations.end(), greater<int>());

    for (int i = 0; i < citations.size(); ++i) {
        if (i >= citations[i])
            return i;
    }
}
int main() {
    vector<int> v = { 3,0,6,1,5 };
    solution(v);
}