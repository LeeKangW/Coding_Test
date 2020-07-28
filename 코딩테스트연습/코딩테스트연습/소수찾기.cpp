#include <string>
#include <vector>
#include<algorithm>
#include<iostream>
// 링크 : https://programmers.co.kr/learn/courses/30/lessons/42839
// numbers를 정렬해 최대값을 구한 후, 최대값보다 작은 소수들을 구하고(에라토스테네스의 채)
// 거기서 numbers 안에 숫자가 있는지 하나씩 체크.

using namespace std;

void FindPrime(vector<int>& v) {
    v[0] = 1; v[1] = 1;
    for (int i = 2; i < v.size(); ++i)
        v[i] = 0;

    for (int i = 2; i <= v.size()/2; ++i) {
        for (int j = 2; j*i< v.size(); ++j) {
            int n = i * j;
            if (v[n] == 1)
                continue;
            else
                v[n] = 1;
        }
    }
}

int solution(string numbers) {
    int answer = 0;
    bool is_wrong = false;
    sort(numbers.begin(), numbers.end(), greater<char>());
    vector<int> temp(stoi(numbers) + 1, 0);
    FindPrime(temp);

    for(int i=0;i<temp.size();++i){
        if (temp[i] != 0)continue;
        int n = i;
        string s = numbers;
        while (n != 0) {
            int mod = n % 10;
            char c = mod + '0';
            auto it = find(s.begin(), s.end(), c);
            if (it != s.end()) {
                s.erase(it);
            }
            else {
                is_wrong = true;
                break;
            }
            n /= 10;
        }
        
        if (is_wrong)
            is_wrong = false;
        else
            ++answer;
    }
    return answer;
}

int main() {
    solution("011");
}