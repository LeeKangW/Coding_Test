#include <string>
#include <vector>
#include <algorithm>
// ¸µÅ© : https://programmers.co.kr/learn/courses/30/lessons/12939

using namespace std;

string solution(string s) {
    string answer = "";
    vector<int> temp;
    string save = "";
    bool is_nagv = false;

    for (const char& c : s) {
        if (c == '-')
            is_nagv = true;
        if (isdigit(c)) {
            save += c;
        }
        if (c == ' ') {
            int n = stoi(save);
            if (is_nagv)
                temp.push_back(-1 * n);
            else
                temp.push_back(n);

            save.clear();
            is_nagv = false;
        }
    }
    int n = stoi(save);
    if (is_nagv)
        temp.push_back(-1 * n);
    else
        temp.push_back(n);

    sort(temp.begin(), temp.end());

    answer += to_string(temp[0]);
    answer += " ";
    answer += to_string(temp[temp.size() - 1]);
    return answer;
}
int main()
{
    solution("-1 -2 3 4");
}