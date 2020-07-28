#include <string>
#include <vector>
#include <algorithm>
// ¸µÅ© : https://programmers.co.kr/learn/courses/30/lessons/64065

using namespace std;

vector<int> solution(string s) {
    vector<vector<int>> save;
    vector<int> answer;
    vector<int>temp;
    string save_num = "";
    bool is_check = false;
    for (const char& c : s) {
        if (c == '}' && is_check) {
            is_check = false;
            temp.push_back(stoi(save_num));
            save.push_back(temp);
            temp.clear();
            save_num.clear();
        }
        else{
            if (isdigit(c)) {
                is_check = true;
                save_num += c;
            }
            else {
                if (c == ',') {
                    if (is_check) {
                        temp.push_back(stoi(save_num));
                        save_num.clear();
                    }
                }
            }
        }
    }
    sort(save.begin(), save.end(), [](const vector<int>& a, const vector<int>& b) {
        return a.size() < b.size();
        });

    for (vector<int>& v : save) {
        for (int i = 0; i < v.size(); ++i) {
            auto it = find(answer.begin(), answer.end(), v[i]);
            if (it==answer.end())
                answer.push_back(v[i]);
        }
    }
    return answer;
}
int main() {
    //solution("{{2},{2,1},{2,1,3},{2,1,3,4}}");
    solution("{{20,111},{111}}");
    //solution("{{2},{2,1,7,8,9,8},{2,1,3,5},{2,4}}");
}