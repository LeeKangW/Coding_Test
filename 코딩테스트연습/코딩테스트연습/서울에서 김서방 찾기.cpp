#include <string>
#include <vector>
#include <algorithm>
// 링크 : https://programmers.co.kr/learn/courses/30/lessons/12919

using namespace std;

string solution(vector<string> seoul) {
    string answer = "";

    auto it =find(seoul.begin(), seoul.end(), "Kim");

    answer = "김서방은 " + to_string(distance(seoul.begin(), it)) + "에 있다";
    return answer;
}