#include <iostream>
// 링크 : https://programmers.co.kr/learn/courses/30/lessons/12931

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
    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "Hello Cpp" << endl;

    return answer;
}