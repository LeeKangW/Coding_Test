#include <string>
#include <vector>
#include<iostream>
// ¸µÅ© : https://programmers.co.kr/learn/courses/30/lessons/12925

using namespace std;

int solution(string s) {
    int answer = 0;
    bool is_positive = true;

    if (s[0] == '-')
    {
        is_positive = false;

        s.erase(s.begin());
    }
    answer = stoi(s);

    is_positive ? answer : answer *= -1;
    return answer;
}

int main() {
    string str = "-123";

    solution(str);
}