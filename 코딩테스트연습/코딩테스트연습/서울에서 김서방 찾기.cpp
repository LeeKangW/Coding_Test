#include <string>
#include <vector>
#include <algorithm>
// ��ũ : https://programmers.co.kr/learn/courses/30/lessons/12919

using namespace std;

string solution(vector<string> seoul) {
    string answer = "";

    auto it =find(seoul.begin(), seoul.end(), "Kim");

    answer = "�輭���� " + to_string(distance(seoul.begin(), it)) + "�� �ִ�";
    return answer;
}