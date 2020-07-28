#include <string>
#include <vector>

// ��ũ : https://programmers.co.kr/learn/courses/30/lessons/42841
// ���� : https://dolphins-it.tistory.com/227

// ���� Ž���̴� ���� �� �ִ� ��� ���� ����صΰ�
// �ϳ��� ���ذ��鼭 ���δ� ������ ���� üũ���ָ� �ȴ�.

using namespace std;


int solution(vector<vector<int>> baseball) {
    int answer = 0;
    for (int i = 123; i <= 987; ++i) {
        int x = i % 10;
        int y = (i / 10) % 10;
        int z = (i / 100);

        if (x == 0 || y == 0 || z == 0)continue;
        if (x == y || y == z || x == z)continue;

        for (int j = 0; j < baseball.size(); ++j) {
            int strike = 0;
            int ball = 0;

            int question = baseball[j][0];
            int question_x = question % 10;
            int question_y = (question / 10 ) % 10;
            int question_z = (question / 100);

            if (question_x == 0 || question_y == 0 || question_z == 0)break;
            if (x == question_x)strike++;
            if (y == question_y)strike++;
            if (z == question_z)strike++;
            if (strike != baseball[j][1])break;

            if ((x == question_y) || (x == question_z)) ball++;
            if ((y == question_x) || (y == question_z)) ball++;
            if ((z == question_x) || (z == question_y)) ball++;
            if (ball != baseball[j][2])break;

            if (j == baseball.size() - 1)++answer;
        }
    }

    return answer;
}