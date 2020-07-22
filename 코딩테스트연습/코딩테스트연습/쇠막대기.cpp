#include <string>
#include <vector>
#include <stack>
using namespace std;
// 링크 : https://programmers.co.kr/learn/courses/30/lessons/42585
// 지린다.. 순서대로 잘 생각해보자.
// 기준을 잡아서 보는 눈을 키워야 한다.

int solution(string arrangement) {
    int answer = 0;
    stack<char> c;

    for (int i = 0; i < arrangement.size(); ++i) {
        if (arrangement[i] == '(') c.push(arrangement[i]);
        else {
            c.pop();
            if (arrangement[i - 1] == '(') answer += c.size();
            else answer += 1;
        }
    }

    return answer;
}