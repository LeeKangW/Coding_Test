#include <string>
#include <vector>

using namespace std;
// 링크 : https://programmers.co.kr/learn/courses/30/lessons/42895
// 조금만 생각하면 풀 수 있다.
// 재귀에 대한 센스가 필요.

int answer = 9;

void find_answer(int N, int number,int count,int cur_num)
{
    if (count >= 9) return;

    if (cur_num == number)
    {
        answer = min(count, answer);
        return;
    }

    int temp = 0;
    for (size_t i = 0; i < 9; ++i)
    {
        temp = temp * 10 + N;
        find_answer(N, number, count + 1 + i, cur_num + temp);
        find_answer(N, number, count + 1 + i, cur_num - temp);
        find_answer(N, number, count + 1 + i, cur_num * temp);
        find_answer(N, number, count + 1 + i, cur_num / temp);
    }


}
int solution(int N, int number)
{

    find_answer(N, number,0,0);
    if (answer == 9) return -1;
    return answer;
}