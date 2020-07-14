#include <string>
#include <vector>
#include <algorithm>

// ¸µÅ© : https://programmers.co.kr/learn/courses/30/lessons/12917

using namespace std;

string solution(string s) {
    string answer = "";
    sort(s.rbegin(), s.rend());
    answer = s;
    return answer;
}