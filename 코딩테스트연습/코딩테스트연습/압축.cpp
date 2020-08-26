#include <string>
#include <vector>
#include <map>
using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;

    map<string, size_t> LZW;

    size_t LZW_idx = 1;
    for (; LZW_idx < 27; ++LZW_idx) {
        string s = "";
        s = (char)64 + LZW_idx;
        LZW[s] = LZW_idx;
    }
    string str = "";
    map<string, size_t>::const_iterator it;
    for (size_t i = 0; i < msg.size(); ++i) {
        str += msg[i];
        
        it = LZW.find(str);
        if (it == LZW.end()) {
            string temp = str;
            temp.erase(temp.end() - 1);
            LZW[str] = LZW_idx++;
            answer.push_back(LZW.find(temp)->second);
            str.clear();
            --i;
        }
    }
    if (it!= LZW.cend()) {
        answer.push_back(it->second);
    }
    return answer;
}
int main() {
    solution("KAKAO");
}