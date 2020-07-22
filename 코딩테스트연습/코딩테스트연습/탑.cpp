#include <string>
#include <vector>
#include <stack>
#include<iostream>

// ¸µÅ© : https://programmers.co.kr/learn/courses/30/lessons/42588

using namespace std;

vector<int> solution(vector<int> heights) {
    vector<int> answer;
    stack<int> temp;
    stack<int> temp2;

    for (int i : heights) temp.push(i);

    while (!temp.empty()) {
        int n = temp.top();
        temp.pop();
        stack<int> s = temp;

        while (!s.empty()) {
            if (n >= s.top())
                s.pop();
            else
                break;
        }

        temp2.push(s.size());
    }
    while (!temp2.empty())
    {
        answer.push_back(temp2.top());
        temp2.pop();
    }
    return answer;
}

int main() {
    vector<int> v = { 3,9,9,3,5,7,2 };
    solution(v);
}