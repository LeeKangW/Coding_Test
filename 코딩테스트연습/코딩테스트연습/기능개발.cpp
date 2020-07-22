#include <string>
#include <vector>
// 링크 : https://programmers.co.kr/learn/courses/30/lessons/42586
// 순서대로 잘 생각해보면 쉬운 문제.
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;

    vector<int> temp;
    int count = 0,num =0;
    for (int i = 0; i < progresses.size(); ++i) {
        num = progresses[i];
        while (num < 100) {
            num += speeds[i];
            ++count;
        }
        temp.push_back(count);
        count = 0;
    }
    count = 0;
    num = temp[0];
    for (int i = 0; i < temp.size(); ++i) {
        if (num < temp[i]) {
            answer.push_back(count);
            num = temp[i];
            count = 1;
        }
        else {
            ++count;
        }
        if (temp.size() - i == 1)
            answer.push_back(count);
    }
    return answer;
}
int main() {
    vector<int> v = {5,5,5};
    vector<int> v2 = {21,25,20};
    solution(v, v2);
}