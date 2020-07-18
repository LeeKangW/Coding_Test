#include <string>
#include <vector>
#include <bitset>
#include <algorithm>
// 링크 : https://programmers.co.kr/learn/courses/30/lessons/17681
// bitset 을 통해 간단하게 해결 가능

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    answer.reserve(n);
    string str;

    int count = 0;

    for (int i = 0; i < arr1.size(); ++i) {
        bitset<16> bits = arr1[i];
        bitset<16> bits2 = arr2[i];
       
        for (int i = 0; i < n; ++i) {
            bits[count] == 0 ? str.push_back(' ') : str.push_back('#');
            ++count;
        }
        count = 0;
        for (int i = 0; i < n; ++i) {
            bits2[count] == 0 ? true : str[i] = '#';
            ++count;
        }
        reverse(str.begin(), str.end());
        answer.push_back(str);
        str.clear();
        count = 0;
    }
    return answer;
}
int main() {
    vector<int> a = { 9, 20, 28, 18, 11 };
    vector<int> b = { 30,1,21,17,28 };
    solution(5, a, b);
}