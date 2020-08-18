#include <string>
#include <vector>
#include <utility>

using namespace std;

bool searching(int& answer,vector<string>& v) {
    bool is_find = false;
    vector<vector<bool>> check; check.resize(v.size());
    
    for (int i = 0; i < v.size(); ++i) {
        string s = v[i];
        for (int j = 0; j < s.size(); ++j) {
            check[i].push_back(false);
        }
    }
    for (size_t i = 0; i < v.size()-1; ++i) {
        string str_temp = v[i];
        string str_next = v[i + 1];
        for (size_t j = 0; j < str_temp.size()-1; j++)
        {
            char c = str_temp[j]; 

            if (c == '0') continue;

            if (c == str_temp[j + 1])
                if (c == str_next[j])
                    if (c == str_next[j + 1]) {
                        check[i][j] = true;
                        check[i][j + 1] = true;
                        check[i + 1][j] = true;
                        check[i + 1][j + 1] = true;
                        is_find = true;
                    }
        }
    }
    if (!is_find) return false;

    for (int i = 0; i < v.size(); ++i) {
        string s = v[i];
        string save_s = "";
        for (int j = 0; j < s.size(); ++j) {
            if (check[i][j]) {
                ++answer;
                save_s += '0';
            }
            else
                save_s += s[j];
        }
        v[i] = save_s;
    }
    return is_find;
}

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    while (searching(answer, board)) {
        for (int i = board.size() - 1; i >= 0; --i) {
            string s = board[i];

            for (size_t j = 0; j < s.size(); ++j) {
                char c = s[j];
                if (c != '0') continue;
                for (int k = i-1; k >= 0; --k) {
                    if (k < 0) continue;

                    if (board[k][j] != '0') {
                        board[i][j] = board[k][j];
                        board[k][j] = '0';
                        break;
                    }
                }
            }
        }
    }
    return answer;
}
int main() {
    vector<string> v = { "TTTANT", "RRFACC", "RRRFCC", "TRRRAA", "TTMMMF", "TMMTTJ" };
    solution(6, 6, v);
}