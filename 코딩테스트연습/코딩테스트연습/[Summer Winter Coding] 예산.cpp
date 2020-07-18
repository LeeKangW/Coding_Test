#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
// ¸µÅ© : https://programmers.co.kr/learn/courses/30/lessons/12982

using namespace std;

int solution(vector<int> d, int budget) {
    int answer = 0;
    sort(d.begin(), d.end());
    for (int n : d) {
        if (budget < n)
            break;
        budget -= n;
        ++answer;
    }
    return answer;
}