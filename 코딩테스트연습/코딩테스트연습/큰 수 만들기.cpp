#include <string>
#include <vector>
#include <stack>
#include<algorithm>
// ¸µÅ© : https://programmers.co.kr/learn/courses/30/lessons/42883

using namespace std;

string solution(string number, int k) {
    string answer = "";
    stack<char> st;
    int size = number.size() - k;
    for (int i = 0; i < number.size(); ++i) {
        char c = number[i];

        for (; (!st.empty()) && k > 0; k--) {
            char top = st.top();
            if (top >= c) break;
            st.pop();
        }
        st.push(c);
    }

    while (st.size() != size) st.pop();

    while (!st.empty()) {
        char c = st.top();
        answer = c + answer;
        st.pop();
    }
    return answer;
}

int main() {
    solution("4177252841", 4);
}