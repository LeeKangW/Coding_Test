#include <string>
#include <vector>

// ¸µÅ© : https://programmers.co.kr/learn/courses/30/lessons/12926

using namespace std;

string solution(string s, int n) {
    string answer = "";
    for (int i = 0; i < s.size(); ++i) {
        if (isalpha(s[i])) {
            for (int j = 0; j < n; ++j) {
                if (isupper(s[i]) && s[i] == 90)
                    s[i] = 65;
                else if (islower(s[i]) && s[i] == 122)
                    s[i] = 97;
                else
                    ++s[i];
            }
        }
    }
    answer = s;
    return answer;
}