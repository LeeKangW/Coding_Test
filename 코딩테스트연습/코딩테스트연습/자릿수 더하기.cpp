#include <iostream>
// ��ũ : https://programmers.co.kr/learn/courses/30/lessons/12931

using namespace std;

int solution(int n)
{
    int answer = 0;
    
    while (true) {
        if (n < 10) {
            answer += n;
            break;
        }
        else {
            answer += n % 10;
            n /= 10;
        }
    }
    // [����] ��ư�� ������ ��� ���� �� �� �ֽ��ϴ�.
    cout << "Hello Cpp" << endl;

    return answer;
}