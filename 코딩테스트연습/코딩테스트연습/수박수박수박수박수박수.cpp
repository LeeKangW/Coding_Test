#include <string>
#include <vector>

//��ũ : https://programmers.co.kr/learn/courses/30/lessons/12922

using namespace std;

string solution(int n) {
    string answer = "";
    
    for (int i = 0; i < n; ++i)
        i & 1 ? answer += "��" : answer += "��";

    return answer;
}