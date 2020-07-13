#include <string>
#include <vector>
#include<iostream>

// ¸µÅ© : https://programmers.co.kr/learn/courses/30/lessons/12903

using namespace std;

string solution(string s) {
    string answer = "";
    if (s.size() & 1) {
        answer = s[(s.size() / 2)];
    }
    else {
        answer = s[(s.size() / 2)-1];
        answer.push_back(s[(s.size() / 2)]);
    }
    return answer;
}

int main() {
    cout << solution("qwer") << endl;
}