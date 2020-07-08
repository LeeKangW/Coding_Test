#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

// ���� ��ũ : https://programmers.co.kr/learn/courses/30/lessons/64061
// board �� ���η� �����Ѱ� ���� �˾�����
// �˰��� ���η� ���ٺ��� �Ʒ��ٷ� �ۼ��Ǿ� �ִ� ��.

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