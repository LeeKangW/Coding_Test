#include <iostream>
#include<string>
#include<stack>
using namespace std;

// ¸µÅ© : https://programmers.co.kr/learn/courses/30/lessons/12973

int solution(string s)
{
    stack<char> st;
    for (const char& c : s)
    {
        if (st.empty())
            st.push(c);
        else
        {
            if (st.top() == c)
                st.pop();
            else
                st.push(c);
        }
    }
    if (st.empty())
        return 1;
    else
        return 0;

}
int main() {
    solution("baabaa");
}