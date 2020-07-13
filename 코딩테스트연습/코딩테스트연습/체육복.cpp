#include <string>
#include <vector>
#include <iostream>

// ¸µÅ© : https://programmers.co.kr/learn/courses/30/lessons/42862

using namespace std;

void calcu_reserve(vector<int>& stu, vector<int>& cal,bool Is_reser) {
    if (Is_reser)
        for (int n : cal)
            ++stu[n-1];
    else
        for (int n : cal)
            --stu[n-1];
}
void greedy_check(vector<int>& stu,bool IsFrontCheck) {
    if (IsFrontCheck) {
        for (int i = 0; i < stu.size() - 1; ++i) {
            if (stu[i] > 1) {
                if (stu[i + 1] == 0)
                {
                    --stu[i];
                    ++stu[i + 1];
                }
            }
        }
    }
    else {
        for (int i = 1; i < stu.size(); ++i) {
            if (stu[i] > 1) {
                if (stu[i - 1] == 0)
                {
                    --stu[i];
                    ++stu[i - 1];
                }
            }
        }
    }
}
int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<int> student(n, 1);

    calcu_reserve(student, reserve,true);
    calcu_reserve(student, lost,false);
    greedy_check(student, false);
    greedy_check(student,true);
    

    for (int n : student) {
        if (n >= 1) {
            ++answer;
        }
    }

    return answer;
}

int main() {
    vector<int> res{ 2,4 };
    vector<int> lost{1,3 };
    cout << solution(5, lost, res) << endl;
}