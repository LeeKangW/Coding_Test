#include <string>
#include <vector>
#include <algorithm>
// ¸µÅ© :https://programmers.co.kr/learn/courses/30/lessons/42746

using namespace std;

bool compare(int a, int b) {
    string s = to_string(a) + to_string(b);
    string s2 = to_string(b) + to_string(a);

    if (s > s2)
        return true;
    else
        return false;
}

string solution(vector<int> numbers) {
    string answer = "";

    if (all_of(numbers.begin(), numbers.end(), [](const int& a) {
        return a == 0;
        })) {
        answer = "0";
        return answer;
    }
    sort(numbers.begin(), numbers.end(),compare);
    
    for (int i : numbers)
        answer += to_string(i);
   
    return answer;
}
int main() {
    vector<int>v = { 0,0,0,0,0,0 };
    solution(v);
}