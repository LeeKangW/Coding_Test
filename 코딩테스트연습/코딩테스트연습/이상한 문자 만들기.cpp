#include <string>
#include <vector>

// ¸µÅ© : https://programmers.co.kr/learn/courses/30/lessons/12930

using namespace std;

string solution(string s) {
    string answer = "";
    vector<string> v;
    string str = "";
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == ' ') {
            v.push_back(str);
            v.push_back(" ");
            str.clear();
        }
        else if (i == s.size() - 1) {
            str += s[i];
            v.push_back(str);
            str.clear();
        }
        else
            str += s[i];
    }

    for (string& s : v) {
        if (s != " ") {
            for (int i = 0; i < s.size(); ++i) {
                i & 1 ? s[i] = tolower(s[i]) : s[i] = toupper(s[i]);
            }
        }
    }
    for (string& s : v)
        answer += s;

    return answer;
}

int main() {
    solution("try hello world");
}