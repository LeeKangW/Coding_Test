#include <string>
#include <vector>

// ¸µÅ© : https://programmers.co.kr/learn/courses/30/lessons/12945

using namespace std;

int fi[100000];

int solution(int n) {
    
    fi[0] = 0; fi[1] = 1;
    for (int i = 2; i <= n; ++i) {
        fi[i] = fi[i - 1] + fi[i - 2];
        fi[i] = fi[i] % 1234567;
    }
    return fi[n];
}