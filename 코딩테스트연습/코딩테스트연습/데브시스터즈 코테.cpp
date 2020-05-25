#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>

using namespace std;

string solution(string input) {

    string answer = "";
    vector<char> oper;
    vector<char> num;
    oper.reserve(100);
    num.reserve(100);

    for (const char& c : input) {
        if (c == '+' || c == '-') {
            if (oper.size() != 0)
            {
                num.push_back(oper.back());
                oper.pop_back();
                oper.push_back(c);
            }
            else {
                oper.push_back(c);
            }
        }
        else if(c=='*' || c=='/'){
            if(oper.size()!=0)
            {
                if (oper.back() == '+' || oper.back() == '-') {
                    oper.push_back(c);
                }
                else {
                    num.push_back(oper.back());
                    oper.pop_back();
                    oper.push_back(c);
                }
            }
            else {
                oper.push_back(c);
            }
        }
        else {
            num.push_back(c);
        }
    }

    for (auto it = oper.crbegin(); it != oper.crend(); ++it)
        num.push_back(*it);

    vector<char> save;
    save.reserve(100);
    
    for (auto c : num)
        cout << c;
    cout << endl << endl;


    for (const char& c : num) {

        cout << "üũ" << endl;
        for (auto c : save)
            cout << c;
        cout << endl << endl;

        if (c == '+' || c == '-' || c == '*' || c == '/') {

            int n1 = save.back() - '0';
            save.pop_back();
            int n2 = save.back() - '0';
            save.pop_back();

            switch (c)
            {
            case '+':
                    save.push_back((n2 + n1) + '0');
                break;
            case '-':
                save.push_back((n2 - n1) + '0');
                break;
            case '*':
                    save.push_back((n2 * n1) + '0');
            case '/':
                if(n1!=0)
                    save.push_back((n2 / n1) + '0');
                break;
            default:
                break;
            }
        }
        else {
            save.push_back(c);
        }

    }
    answer = to_string(save.back()-'0');
    if (answer == "0")
        answer = "Impossible";
    return answer;
}

int main() {
    char k = '2';
    char n = '3';
    int a = k-'0';
    int b = n-'0';
    char c = (a * b) + '0';
    cout << c << endl;
    cout << solution("2+3*2") << endl;
}