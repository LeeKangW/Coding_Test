#include <string>
#include <vector>

// ¸µÅ© : https://programmers.co.kr/learn/courses/30/lessons/12937

using namespace std;

string solution(int num) {
    string answer = "";
    num & 1 ? answer = "Odd" : answer = "Even";
    return answer;
}