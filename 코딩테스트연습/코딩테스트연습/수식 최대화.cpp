#include <string>
#include <vector>
#include <queue>
// 링크 : https://programmers.co.kr/learn/courses/30/lessons/67257
// 무엇이 틀렸는지 확인이 안됨.

using namespace std;

priority_queue<long long, vector<long long>> pq;

long long operation(const char* c,long long left, long long right) {
    switch (*c)
    {
    case'+':
        return left + right;
    case '-':
        return left - right;
    case '*':
        return left * right;
    }
}

void sum(vector<string> v,string oper1,string oper2,string oper3) {
    vector<string> temp;
    // case 1
    for (int i = 0; i < v.size(); ++i) {
        if (v[i] == oper1) {
            long long n1 = stoi(v[i - 1]);
            long long n2 = stoi(v[i + 1]);
            long long oper = operation(v[i].c_str(), n1, n2);
            v.erase(v.begin() + i - 1, v.begin() + i + 2);
            if (i < v.size())
                v.insert(v.begin() + --i, to_string(oper));
            else
                v.insert(v.end(), to_string(oper));
        }
    }
    for (int i = 0; i < v.size(); ++i) {
        if (v[i] == oper2) {
            long long n1 = stoi(v[i - 1]);
            long long n2 = stoi(v[i + 1]);
            long long oper = operation(v[i].c_str(), n1, n2);
            v.erase(v.begin() + i - 1, v.begin() + i + 2);
            
           if(i<v.size())
                v.insert(v.begin() + --i, to_string(oper));
            else
                v.insert(v.end(), to_string(oper));
        }
    }
    for (int i = 0; i < v.size(); ++i) {
        if (v[i] == oper3) {
            long long n1 = stoi(v[i - 1]);
            long long n2 = stoi(v[i + 1]);
            long long oper = operation(v[i].c_str(), n1, n2);
            v.erase(v.begin() + i - 1, v.begin() + i + 2);
            if (i < v.size())
                v.insert(v.begin() + --i, to_string(oper));
            else
                v.insert(v.end(), to_string(oper));
        }
    }
    pq.push(abs(static_cast<long long>(stoi(v[0]))));
}

long long solution(string expression) {
    long long answer = 0;
    vector<string> temp;
    string str = "";
    for (const char& c : expression) {
        if (isdigit(c))
        {
            str += c;
        }
        else {
            temp.push_back(str);
            str.clear();
            str += c;
            temp.push_back(str);
            str.clear();
        }
    }
    temp.push_back(str);

    sum(temp,"*","+","-");
    sum(temp,"*","-","+");
    sum(temp,"+","*","-");
    sum(temp,"+","-","*");
    sum(temp,"-","+","*");
    sum(temp,"-","*","+");

    answer = pq.top();
    return answer;
}
int main() {
   // solution("100-200*300-500+20");
    solution("100+500-600+700");
}