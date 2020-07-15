#include <string>
#include <vector>
#include<algorithm>
// ¸µÅ© : https://programmers.co.kr/learn/courses/30/lessons/12933
using namespace std;

long long solution(long long n) {
    long long answer = 0;
    vector<long long> v;
    int count = 1;
    while (true)
    {
        if (n < 10) {
            v.push_back(n);
            break;
        }
        else {
            v.push_back(n % 10);
            n /= 10;
        }
        count*=10;
    }
    sort(v.rbegin(), v.rend());
    
    for (long long n : v) {
        answer += n * count;
        count /= 10;

    }
    return answer;
}