#include <iostream>
#include <vector>
#include <algorithm>
// ��ũ : https://programmers.co.kr/learn/courses/30/lessons/12913
// DP�� �̿��ؼ� ǰ...
// �� �ٿ��� �ڱ� �ڽ��� �ε����� ������ �ִ밪�� �ڱ�� ���ذ��鼭
// ���� ������ �ε����� �ִ��� ã�� Ǯ��

using namespace std;

int solution(vector<vector<int> > land)
{
    int answer = 0;
    int row = 1;

    for (int i = 1; i < land.size(); ++i) {
        for (int j = 0; j < land[i].size(); ++j) {
            int temp = i - 1;
            int max = 0;
            for (int k = 0; k < land[temp].size(); ++k) {
                if (k == j)continue;
                if (max < land[temp][k])
                    max = land[temp][k];
            }
            land[i][j] += max;
        }
    }
    int max_idx = land.size() - 1;
    answer = *(max_element(land[max_idx].begin(), land[max_idx].end()));
    return answer;
}

int main() {
    vector<vector<int>> v = { {1,2,3,5},{5,6,7,8},{4,3,2,1} };
    solution(v);
}