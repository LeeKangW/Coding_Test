// ��ũ : https://programmers.co.kr/learn/courses/30/lessons/62048
// ��ü�� ���� ���� �ƴ�
// ���� �������� ���� �ִ������� ���� w,h �� ũ��� ���� ����
// �����ؼ� �� �� �˾ƾ� Ǯ �� ����.
using namespace std;

long long get_gcd(long long w, long long h) {
    // ��Ŭ���� ȣ���� ���
    // �������� ���� ����ؼ� ���.
    // ���������� ������ �������� ���� �ִ�����
    while (h != 0) {
        int r = w % h;
        w = h;
        h = r;
    }
    return w;
}
long long solution(int w, int h) {
    long long answer = 1;
    long long total = static_cast<long long>(w) * static_cast<long long>(h);
    
    long long gcd = get_gcd(w, h);

    w /= gcd; h /= gcd;

    answer = total - (w + h - 1) * gcd;
    return answer;
}