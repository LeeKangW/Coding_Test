#include <string>
#include <vector>
#include <bitset>

// ¸µÅ© : https://programmers.co.kr/learn/courses/30/lessons/12911

using namespace std;

int solution(int n) {
    int answer = 0;
    bitset<19> bit_n=n;
    int sum = 0;
    for (int i = 0; i < 19; ++i) {
        if (bit_n[i] == 1)
            ++sum;
    }
    for (int i = n + 1;; ++i) {
        bitset<19> temp = i;
        int sum_temp = 0;
        for (int i = 0; i < 19; ++i) {
            if (temp[i] == 1)
                ++sum_temp;
        }
        if (sum == sum_temp) {
            answer = i;
            break;
        }
    }
    return answer;
}