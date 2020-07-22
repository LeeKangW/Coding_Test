#include <string>
#include <vector>
#include <map>
#include<iostream>
// ¸µÅ© : https://programmers.co.kr/learn/courses/30/lessons/49993

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    map<char, int> temp;
    bool is_correct = true;

    for (const string& str : skill_trees) {
        is_correct = true;
        for (const char& c : skill)
            temp[c] = -1;
        for (int i = 0; i < str.size(); ++i) {
            for (const char& c : skill) {
                if (str[i] == c)
                    temp[c] = i;
            }
        }

        for (int i = 0; i < skill.size(); ++i) {
            int num = temp[skill[i]];
            for (int j = i+1; j < skill.size(); ++j) {
                if (i == 0) {
                    if (num == -1) {
                        if (temp[skill[j]] != -1) {
                            is_correct = false;
                            break;
                        }
                    }
                }
                if (temp[skill[j]] > -1) {
                    if (num != -1) {
                        if (temp[skill[j]] < num) {
                            is_correct = false;
                            break;
                        }
                    }
                    else {
                        is_correct = false;
                        break;
                    }
                }
            }
            if (!is_correct)break;
        }

        if (is_correct) ++answer;
    }
    return answer;

}
int main() {
    vector<string> str = { "BACDE","CBADF","AECB","BDA" };
    cout << solution("CBD", str) << endl;
}