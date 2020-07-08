#include <string>
#include <vector>
#include <algorithm>
#include <array>
#include<iostream>
using namespace std;

void h_check(vector<int>& h,vector<int>& answers,int& correct) {
    int index = 0;

    for (int num : answers) {
        if (index >= h.size())
            index = 0;

        if (h[index] == num) {
            ++correct;
        }
        ++index;
    }
}
vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> h1 = { 1,2,3,4,5 },
        h2 = { 2,1,2,3,2,4,2,5 },
        h3 = { 3,3,1,1,2,2,4,4,5,5 };

    array<int, 3> cor = { 0, };
    
    h_check(h1, answers, cor.at(0));
    h_check(h2, answers, cor.at(1));
    h_check(h3, answers, cor.at(2));

    auto it = max_element(cor.begin(), cor.end());
    
    int index = distance(cor.begin(), it);
    answer.push_back(index+1);

    for (int i = 0; i < cor.size(); ++i) {
        if (i != index) {
            if (cor[i] == *it) {
                answer.push_back(i + 1);
            }
        }
    }
    sort(answer.begin(), answer.end());
    return answer;
}

int main() {
    
}
