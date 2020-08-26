#include <string>
#include <vector>
#include <stack>
using namespace std;

string solution(int n, int t, int m, int p) {
    string answer = "";
    vector<string> HAX = { "0","1","2","3","4","5","6","7","8","9","A","B","C","D","E","F" };
    vector<int> numbers;
    vector<string> result;
    for (size_t i = 0; i <= t * m; ++i) {
        numbers.push_back(i);
    }
    
    if (n != 10) {
        for (size_t i = 0; i < numbers.size(); ++i) {
            size_t num = numbers[i];
            string str_temp = "";
            stack<string> st;
            if (n != 16) {
                while (true) {
                    if (num / n != 0)
                        st.push(to_string(num % n));
                    else {
                        st.push(to_string(num % n));
                        break;
                    }
                    num /= n;
                }
                while (!st.empty()) {
                    string s = st.top(); st.pop();
                    for (const char& c : s)
                        result.push_back(to_string(c - '0'));
                }
            }
            else {
                while (true) {
                    if (num / n != 0)
                        st.push(to_string(num % n));
                    else {
                        st.push(to_string(num % n));
                        break;
                    }
                    num /= n;
                }
                while (!st.empty()) {
                    string s = st.top(); st.pop();
                    s = HAX[stoi(s)];
                    result.push_back(s);
                }
            }
        }
    }
    else {
        for (size_t i = 0; i < numbers.size(); ++i) {
            size_t num = numbers[i];
            vector<string> v_str;

            while (true) {
                if (num / n == 0)
                {
                    v_str.push_back(to_string(num % n));
                    break;
                }
                else {
                    v_str.push_back(to_string(num / n));
                    num /= n;
                }
            }
            for (const string& s : v_str)
                result.push_back(s);
        }
    }
    size_t my_pos = p - 1;
    for (size_t i = 0; i < t; ++i) {
        answer += result[my_pos];
        my_pos += m;
    }
    return answer;
}
int main() {
    solution(2, 4, 2, 1);
}