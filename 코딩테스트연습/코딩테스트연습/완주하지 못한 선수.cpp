#include <string>
#include <vector>
#include <map>
#include <iostream>

// ��ũ : https://programmers.co.kr/learn/courses/30/lessons/42576
// map ���� �ؼ� ������ Ž��
// ������ �̿��ؼ� �ص� ��.
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    map<string, int> map_part;

    for (string& str : participant) {
        map_part[str]++;
    }
    for (string& str : completion) {
        map_part[str]--;
    }

    for (pair<string, int> p : map_part) {
        if (p.second > 0) {
            answer = p.first;
            break;
        }
    }

    return answer;
    
}
int main() {
    vector<string> v1;
    vector<string> v2;
    v1.push_back("leo");
    v1.push_back("kiki");
    v1.push_back("eden");
    v2.push_back("leo");
    v2.push_back("kiki");
    
    cout << solution(v1, v2) << endl;
}