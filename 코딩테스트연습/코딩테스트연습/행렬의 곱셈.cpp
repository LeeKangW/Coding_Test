#include <string>
#include <vector>

// ¸µÅ© : https://programmers.co.kr/learn/courses/30/lessons/12949

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    int arr2_row_size = arr2[0].size();
    for (int i = 0; i < arr1.size(); ++i) {
        vector<int> temp;
        for (int k = 0; k < arr2_row_size; k++) {
            int sum = 0;
            for (int j = 0; j < arr1[i].size(); ++j) {
                sum += arr1[i][j] * arr2[j][k];
            }
            temp.push_back(sum);
        }
        answer.push_back(temp);
    }
    return answer;
}