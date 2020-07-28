#include <string>
#include <vector>
#include<algorithm>

// 링크 : https://programmers.co.kr/learn/courses/30/lessons/1835

using namespace std;

// 조건 구하기.
bool Check(vector<string>& data,vector<char>& members) {
    
    for (const string& s : data) {
        char c1 = s[0];
        char c2 = s[2];
        char oper = s[3];
        int num = s[4] - '0'; num += 1;

        int c1_idx = distance(members.begin(), find(members.begin(), members.end(), c1));
        int c2_idx = distance(members.begin(), find(members.begin(), members.end(), c2));

        if (oper == '=' && abs(c1_idx - c2_idx) != 1)
            return false;
        if (oper == '>' && abs(c1_idx - c2_idx) <= num)
            return false;
        if (oper == '<' && abs(c1_idx - c2_idx) >= num)
            return false;
    }

    return true;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<string> data) {
    int answer = 0;
    vector<char> members1 = { 'A','C','F','J','M','N','R','T' };
    do {
        if (Check(data, members1)) {
            ++answer;
        }
    } while (next_permutation(members1.begin(), members1.end()));

    return answer;
}

int main() {
    vector<string> s = {"N~F=0","R~T>2"};
    solution(2, s);
}