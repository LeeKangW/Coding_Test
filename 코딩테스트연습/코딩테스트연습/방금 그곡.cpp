#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// 틀리는 부분을 못 찾음...

int calcu_time(string start, string end) {
    size_t start_hour = 0,end_hour=0;
    size_t start_min = 0,end_min=0;

    string start_temp="";
    string end_temp = "";
    for (size_t i = 0; i < start.size(); ++i) {
        char s = start[i];
        char e = end[i];
        if (s == ':')
        {
            start_hour = stoi(start_temp);
            end_hour = stoi(end_temp);
            start_temp.clear();
            end_temp.clear();
        }
        else {
            start_temp += s;
            end_temp += e;
            
        }
    }
    start_min = stoi(start_temp);
    end_min = stoi(end_temp);

    size_t min_calcul = end_min - start_min;
    size_t hour_calcul = end_hour - start_hour;

    if (min_calcul < 0) {
        hour_calcul -= 1;
        min_calcul = (60 + min_calcul);
    }

    return hour_calcul * 60 + min_calcul;
}
string solution(string m, vector<string> musicinfos) {
#pragma region 구분 완료
    string answer = "";
    vector<string> title;
    vector<int> time;
    vector<string> music;
    for (size_t i = 0; i < musicinfos.size(); ++i) {
        string str = musicinfos[i];
        string start_timer = "";
        string end_timer = "";
        string temp = "";
        for (size_t j = 0; j < str.size(); ++j) {
            char c = str[j];
            if (j < 11) {
                if (c != ',') {
                    if (j < 5) {
                        start_timer += c;
                    }
                    else
                        end_timer += c;
                }
            }
            else if (j == 11)
                time.push_back(calcu_time(start_timer, end_timer));
            else {
                if (c != ',')
                    temp += c;
                else {
                    title.push_back(temp);
                    temp.clear();
                }
            }
        }
        music.push_back(temp);
    }
#pragma endregion
#pragma region 특수문자포함 부분을 소문자로 변경 and Time 만큼 멜로디 재정의
    for (size_t i = 0; i < music.size(); ++i) {
        string str_temp = music[i];
        string temp = "";
        for (size_t j = 0; j < str_temp.size()-1; ++j) {
            char c = str_temp[j];
            char c2 = str_temp[j+1];
            if (c2 == '#') {
                c = tolower(c);
                ++j;
            }
            temp += c;
        }
        if (isalpha(str_temp[str_temp.size() - 1]))
            temp += str_temp[str_temp.size() - 1];

        music[i] = temp;

        temp.clear();
        size_t idx = 0;
        for (size_t j = 0; j < time[i]; ++j) {
            if (idx == music[i].size())
                idx = 0;
            temp += music[i][idx];
            idx += 1;
        }
        music[i] = temp;
    }
    string temp = "";
    for (size_t i = 0; i < m.size()-1; ++i) {
        char c = m[i];
        char c2 = m[i + 1];
        if (c2 == '#') {
            c = tolower(c);
            ++i;
        }
        temp += c;
    }
    if (isalpha(m[m.size() - 1]))
        temp += m[m.size() - 1];
    m = temp;

#pragma endregion
#pragma region 멜로디 찾기
    vector<bool> vec(music.size(), false);

    char m_f = m[0];
    for (size_t i = 0; i < music.size(); ++i) {
        string str = music[i];
        auto it = find(str.begin(), str.end(), m_f);
        if (it == str.end())
            continue;
        bool is_exist = true;
        size_t idx = distance(str.begin(), it);
        for (size_t j = 0; j < m.size(); ++j) {
            if (idx + j >= str.size()) {
                is_exist = false;
                break;
            }
            if (m[j] != str[idx+j])
                is_exist = false;
        }
        if (is_exist) vec[i] = true;
    }

    if (find(vec.begin(), vec.end(), true) == vec.end()) return "(None)";

    int max_time = 0;
    size_t save_idx = 0;
    for (size_t i = 0; i < title.size(); ++i) {
        if (vec[i] == true) {
            if (max_time < time[i]) {
                max_time = time[i];
                save_idx = i;
            }
        }
    }
    return title[save_idx];
#pragma endregion

}
int main() {
    vector<string> v = { "12:00,12:14,HELLO,C#DEFGAB", "13:00,13:05,WORLD,ABCDEF" };
    vector<string> v2 = { "13:00,13:02,HAPPY,ABC#","13:00,13:30,WORLD,ABC" };

    solution("ABC", v2);
}