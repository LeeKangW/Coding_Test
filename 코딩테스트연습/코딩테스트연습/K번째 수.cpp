#include <string>
#include <vector>
#include <algorithm>
#include<iostream>

// ¸µÅ© : https://programmers.co.kr/learn/courses/30/lessons/42748

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    vector<vector<int>> save_data;
    int i = 0;
    auto it = array.begin();
    for (vector<int>& v : commands) {
        save_data.resize(i + 1);
        save_data[i].insert(save_data[i].begin(), (it + v.at(0)-1), (it + v.at(1)));
        ++i;
    }
    i = 0;
    for (vector<int>& v : save_data) {
        sort(v.begin(), v.end());
        answer.push_back(v.at(commands[i].at(2)-1));
        ++i;
    }
    
    return answer;
}

int main() {
    vector<int> b = { 1,5,2,6,3,7,4 };
    vector<vector<int>> e = { {2,5,3},{4,4,1},{1,7,3} };
    vector<int> exam;

    exam = solution(b, e);

    for (auto v : exam)
        cout << v << endl;
}


