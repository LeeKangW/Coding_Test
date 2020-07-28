#include<string>
#include<stack>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    stack<char> st;
    for (const char& c : s) {
        if (st.empty())
        {
            if (c == ')')
                return false;
            st.push(c);
        }
        else {
            switch (c)
            {
            case ')':
                if (st.empty()) return false;
                if (st.top() == ')')return false;
                st.pop();
                break;
            case '(':
                st.push(c);
                break;
            }
        }
    }
    if (!st.empty())return false;
    return answer;
}