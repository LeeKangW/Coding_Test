#include <string>
#include <vector>
#include <math.h>
// ��ũ : https://programmers.co.kr/learn/courses/30/lessons/12921
// �����佺�׳׽��� ü ����ؾ� ��.
// �Ҽ� ���ϱ� ���� ���� ����.
using namespace std;

int solution(int n) {
    int answer = 0;

    // 0�� 1�� �Ҽ��� �ƴϴ� 0���� ����
    // 0 -> �Ҽ��ƴ�
    // 0 �� �ƴϸ� �Ҽ�

    vector<int> num = { 0,0 };

    // 2 �̻���� �ε����� ���缭 ����
    for (int i = 2; i <= n; ++i) {
        num.push_back(i);
    }

    // �����佺�׳׽��� ä ���
    for (int i = 2; i <= n; ++i) {
        if (num[i] == 0)continue;

        for (int j = 2 * i; j <= n; j += i) {
            num[j] = 0;
        }
    }

    // 0�� �ƴ� ���� �Ҽ��̱⿡ 0�� �ƴ� ���� ã��.
    for (int i = 0; i < num.size(); ++i) {
        if (num[i] != 0)
            ++answer;
    }

    return answer;
}