#include <string>
#include <vector>
#include <queue>
#include <algorithm>
// ¸µÅ© : https://programmers.co.kr/learn/courses/30/lessons/60057

using namespace std;

int solution(string s) {
    int answer = 0,mod=1;
    string str="";
    string total = "";
    queue<string> temp;
    vector<int> sum;

    if (s.size() == 1)
        return 1;

    while (true) {
        string s_temp = "";
        for (int i = 0; i < s.size(); ++i) {
            
            if ((i+1) % mod == 0) {
                s_temp += s[i];
                temp.push(s_temp);
                s_temp.clear();
            }
            else {
                s_temp += s[i];
            }

        }
        if (!s_temp.empty()) temp.push(s_temp);

        int count = 1;
        while (!temp.empty()) {
            if (str == temp.front()) {
                ++count;
               // str = to_string(count) + str;
            }
            else {
                if (!str.empty())
                    count > 1 ? total = total + to_string(count) + str : total = total + str;

                str.clear();
                count = 1;
                str = temp.front();
            }
            temp.pop();
        }
        count > 1 ? total = total + to_string(count) + str : total = total + str;

        sum.push_back(total.size());

        total.clear();
        str.clear();
        s_temp.clear();

        if (mod == s.size() / 2) {
            break;
        }
        else {
            ++mod;
        }
        
    }
    answer = *(min_element(sum.begin(), sum.end()));
    return answer;
}

int main() {
    solution("abcabcdede");
}