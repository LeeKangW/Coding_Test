#include <string>
#include <vector>
#include <stack>
using namespace std;
// ��ũ : https://programmers.co.kr/learn/courses/30/lessons/42585
// ������.. ������� �� �����غ���.
// ������ ��Ƽ� ���� ���� Ű���� �Ѵ�.

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