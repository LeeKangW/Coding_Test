#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

// 문제 링크 : https://programmers.co.kr/learn/courses/30/lessons/64061
// board 가 세로로 나열한거 인줄 알았지만
// 알고보니 가로로 윗줄부터 아래줄로 작성되어 있던 것.

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    vector<int> bucket;
    bucket.reserve(1000);

    for (int num : moves) {
        --num;
        for (vector<int>& v : board) {
            if (bucket.size() > 0) {
                if (v[num] <= 0) {
                    continue;
                }
                else {
                    if (bucket.back() == v[num]) {
                        bucket.pop_back();
                        ++answer;
                    }
                    else {
                        bucket.push_back(v[num]);
                    }
                    v[num] *= -1;
                    break;
                }
            }
            else {
                if (v[num] <= 0) {
                    continue;
                }
                else {
                    bucket.push_back(v[num]);
                    v[num] *= -1;
                    break;
                }
            }
        }
    }

    answer *= 2;
    return answer;
}


int main() {

}