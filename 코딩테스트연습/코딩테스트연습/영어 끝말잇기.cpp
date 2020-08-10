#include <string>
#include <vector>
#include<map>
#include<algorithm>
#include <iostream>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer(2,0);


    map<string, int> m;
    string str_temp = "";
    for (const string& s : words)
        m[s]++;

    for (const pair<string, int>& p : m) {
        if (p.second > 1) {
            str_temp = p.first;
            break;
        }
    }

    auto it = find(words.crbegin(), words.crend(), str_temp);
    if (it != words.crend()) {
        int idx = (words.size() - 1) - distance(words.crbegin(), it);
        int temp = (idx % n) + 1;
        answer[0] = temp;
        temp = (idx / n) + 1;
        answer[1] = temp;
        return answer;
    }


    int save_idx = -1;

    for (int i = 0; i < words.size(); ++i) {
        if (i != words.size() - 1) {
            string str1 = words[i];
            string str2 = words[i + 1];

            if (str1[str1.size() - 1] != str2[0]) {
                save_idx = i+1;
                break;
            }
        }
    }
    if (save_idx != -1) {
        int temp = (save_idx % n) + 1;
        answer[0] = temp;
        temp = (save_idx / n) + 1;
        answer[1] = temp;
   }
    return answer;
}

int main() {
   // vector<string> s = { "land", "dream", "mom", "mom", "ror" };
    vector<string> s = { "hello", "one", "even", "never", "now", "world", "draw" };
    solution(2, s);
}