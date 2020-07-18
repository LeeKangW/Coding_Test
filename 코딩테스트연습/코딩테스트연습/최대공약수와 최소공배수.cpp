#include <string>
#include <vector>

// ��ũ : https://programmers.co.kr/learn/courses/30/lessons/12940
// �ִ����� : ��Ŭ���� ȣ����
// �ּҰ���� : �� �ڿ����� �� / �ִ�����

using namespace std;

int find_CommonFactor(int n,int m) {
    int r;
    if (n >= m) {
        while (m != 0) {
            r = n % m;
            n = m;
            m = r;
        }
        return n;
    }
    else {
        while (n != 0) {
            r = m % n;
            m = n;
            n = r;
        }
        return m;
    }
}
int find_CommonMultiple(int n, int m) {
    return n * m / find_CommonFactor(n, m);
}
vector<int> solution(int n, int m) {
    vector<int> answer;
    answer.push_back(find_CommonFactor(n, m));
    answer.push_back(find_CommonMultiple(n, m));
    return answer;
}