#include <string>
#include <vector>

// ¸µÅ© : https://programmers.co.kr/learn/courses/30/lessons/12948

using namespace std;

string solution(string phone_number) {
    string answer = "";
    int count = 0;
    for (auto it = phone_number.rbegin(); it != phone_number.rend(); ++it) {
        if (count > 3)
            *it = '*';
        else
            count++;
    }
    answer = phone_number;
    return answer;
}