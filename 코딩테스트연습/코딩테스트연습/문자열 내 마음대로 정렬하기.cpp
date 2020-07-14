#include <string>
#include <vector>
#include <algorithm>
// ¸µÅ© : https://programmers.co.kr/learn/courses/30/lessons/12915

using namespace std;

vector<string> solution(vector<string> strings, int n) {
    vector<string> answer;
    
    sort(strings.begin(), strings.end(), [&n](const string& a, const string& b) {
        if (a[n] == b[n])
            return a < b;
        else
            return a[n] < b[n];
        });
    answer = strings;
    return answer;
}