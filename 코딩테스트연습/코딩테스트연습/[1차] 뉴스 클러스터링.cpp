#include <string>
#include <vector>
#include<algorithm>

using namespace std;

void get_vector(vector<string>& v, string str) {
    for (int i = 0; i < str.size() - 1; ++i) {
        string temp = "";
        temp += str[i];
        temp += str[i + 1];
        v.push_back(temp);
    }
}
vector<string> check_alpha(vector<string>& v) {
    
    vector<string> temp;
    for (string& s : v) {
        bool is_alpha = true;
        for (char& c : s) {
            c = tolower(c);
            if (!isalpha(c)) {
                is_alpha = false;
                break;
            }
        }
        if (is_alpha) {
            temp.push_back(s);
        }
    }
    return temp;
}

float GetResult(vector<string>& v1,vector<string>& v2) {
    vector<string> v_inter;
    float union_num = v1.size() + v2.size();
    if (v1.size() <= v2.size()) {
        for (const string& s : v1) {
            auto it = find(v2.cbegin(), v2.cend(), s);
            if (it != v2.end()) {
                v_inter.push_back(*it);
                v2.erase(it);
            }
        }
    }
    else {
        for (const string& s : v2) {
            auto it = find(v1.cbegin(), v1.cend(), s);
            if (it != v1.end()) {
                v_inter.push_back(*it);
                v1.erase(it);
            }
        }
    }

    float inter_num = v_inter.size();
    union_num -= inter_num;

    return inter_num / union_num;
}
int solution(string str1, string str2) {
    int answer = 0;
    vector<string> v1;
    vector<string> v2;

    get_vector(v1, str1);
    get_vector(v2, str2);

    v1=check_alpha(v1);
    v2=check_alpha(v2);
    
    if (v1.empty() && v2.empty())
        return 65536;

    float result = GetResult(v1, v2);

    answer = result * 65536;

    return answer;
}
int main() {
    solution("FRANCE", "french");
}