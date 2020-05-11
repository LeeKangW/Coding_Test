#include <string>
#include <vector>
#include<algorithm>


// https://programmers.co.kr/learn/courses/30/lessons/42576

using namespace std;

string solution(vector<string> participant, vector<string> completion) {

    string answer = "";
    for (const auto& c : completion) {
        if (completion.size() == 0)
        {
            break;
        }
        for (const auto& p : participant) {
           
            if (c==p) {
                participant.erase(remove(participant.begin(), participant.end(), c));
                break;
            }
        }
    }
    answer = participant[0];

    return answer;
}
