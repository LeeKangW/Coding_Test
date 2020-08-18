#include <string>
#include <vector>
#include <map>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    vector<string> temp;
    map<string, string> m;

#pragma region 레코드 구분
    for (size_t i = 0; i < record.size(); ++i) {
        string str = record[i];
        string save_s = "";
        for (size_t j = 0; j < str.size(); ++j) {
            if (str[j] != ' ')
            {
                save_s += str[j];
                continue;
            }
            temp.push_back(save_s);
            save_s = "";
        }
        temp.push_back(save_s);
    }
#pragma endregion
    for (size_t i = 0; i < temp.size();++i) {
        string str = temp[i];
        if (str == "Enter" || str == "Change") {
            string s1 = temp[++i];
            string s2 = temp[++i];
            m[s1] = s2;
        }
        else if (str == "Leave")
            ++i;
    }
    for (size_t i = 0; i < temp.size(); ++i) {
        string str = temp[i];
        if (str == "Enter") {
            string s1 = temp[++i]; ++i;
            string output = m[s1] + "님이 들어왔습니다.";
            answer.push_back(output);
        }
        else if (str == "Change") {
            i += 2;
            continue;
        }
        else if (str == "Leave")
        {
            string s1 = temp[++i];
            string output = m[s1] + "님이 나갔습니다.";
            answer.push_back(output);
        }
    }

    return answer;
}
int main() {
    vector<string> v = { "Enter uid1234 Muzi", "Enter uid4567 Prodo", "Leave uid1234", "Enter uid1234 Prodo", "Change uid4567 Ryan" };
    solution(v);
}