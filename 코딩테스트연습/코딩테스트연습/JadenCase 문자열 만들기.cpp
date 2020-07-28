#include <string>
#include <vector>

// ¸µÅ© : https://programmers.co.kr/learn/courses/30/lessons/12951

using namespace std;

string solution(string s) {
    string answer = "";
    vector<string> temp;
    string str = "";
    for (int i = 0; i <= s.size(); ++i) {
        if (s[i] == ' ')
        {
            temp.push_back(str);
            str.clear();
        }
        else if (i == s.size())
            temp.push_back(str);
        else {
            str += s[i];
        }
    }

    for (int i = 0; i < temp.size(); ++i) {
        if (isalpha(temp[i][0]))
            temp[i][0] = toupper(temp[i][0]);
        for (int j = 1; j < temp[i].size(); ++j) {
            temp[i][j] = tolower(temp[i][j]);
        }

        answer += temp[i];
        if(i!=temp.size()-1)
            answer += ' ';
    }
    

    return answer;
}
int main() {
    solution("3people unFollowed me");
}