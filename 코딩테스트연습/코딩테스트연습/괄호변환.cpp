#include <string>
#include <vector>
#include <stack>
#include <iostream>
// 링크 : https://programmers.co.kr/learn/courses/30/lessons/60058
// 다시 풀어봐야 함.
using namespace std;
bool Correct(string& str) {
    string s = "";
    stack<char> st;
    for (int i = 0; i < str.size(); ++i) {
        if (st.empty())st.push(str[i]);
        else{
            if (str[i] == '(') {
                if (st.top() == ')')
                    return false;
                st.push(str[i]);
            }
            else {
                if (st.top() == '(')
                {
                    st.pop();
                }
                else
                {
                    return false;
                }
            }
        }
    }
    return true;
}

string change_u(string& u) {
    string temp = u;
    stack<char> st;
    temp.erase(temp.begin());
    temp.erase(--temp.end());

    for (char& c : temp) {
        switch (c)
        {
        case '(':
            c = ')';
            break;
        case ')':
            c = '(';
            break;
        }
    }
    return temp;
}
string check_u(string& s) {
    // 1
    if (s.empty()) return s;
    
    // 2
    int left = 0, right = 0;
    auto i = s.begin();
    for (; i != s.end(); ++i) {
        char c = *i;
        switch (c)
        {
        case '(':
            ++left;
            break;
        case ')':
            ++right;
            break;
        }
        if (left == right)break;
    }
    string u = { s.begin(),++i };
    string v = { i,s.end() };

    // 3
    if (Correct(u)) return u + check_u(v);
    else {
    // 4
        // 4-1
        string temp = "(";
        // 4-2
        temp += check_u(v);
        // 4-3
        temp += ")";
        // 4-4
        temp += change_u(u);
        return temp;
    }

}

string solution(string p) {
    string answer = "";
    if (Correct(p)) return p;
    else
        answer=check_u(p);

    return answer;
}

int main() {
    cout << solution(")()()()(") << endl;
}