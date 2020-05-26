#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
using namespace std;

// ���� ��ũ - https://programmers.co.kr/learn/courses/30/lessons/42889


vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    map<int, double> m;
    int total_user = stages.size();

    for (int i = 1; i < N + 1; ++i) // map �� N ��ŭ �ʱ�ȭ
        m[i] = 0;

    for (int i : stages) {   //  �� ���������� �ο��� üũ
        if(i!=N+1)
            m[i]++;
    }

    for (int i = 1; i < N + 1; ++i) { // Map�� second�� �������� ��ü
        if (total_user == 0)
            total_user = 1;
        int temp = m[i];
        m[i] = m[i] / total_user;
        total_user -= temp;
    }

    vector<double> save;
    save.reserve(m.size());

    for (auto& p : m) // �������� �־��ֱ�
        save.push_back(p.second);

    sort(save.begin(), save.end(), [](double& a, double& b) { // �������� ���������� ����
        return a > b;
        });


    for (int i = 0; i < save.size(); ++i) { // �������� �ش��ϴ� ���������� answer�� ����.
        auto it = find_if(m.begin(), m.end(), [&](pair<int,double> a) {
                return a.second == save[i];
            });
        if (it != m.end()) {
                answer.push_back(it->first);
                m.erase(it);
        }
    }
    
    return answer;
}

int main() {
    vector<int> v{ 2,1,2,6,2,4,3,3 };

    solution(5, v);
}