#include <vector>
#include <iostream>
using namespace std;

void get(vector<int>& v) {
    for (int i = 2; i < v.size(); ++i) {
        for (int j = 2; i * j < 3000; ++j) {
            int n = i * j;
            if (v[n] == 1)
                continue;
            v[n] = 1;

        }
    }
}
int solution(vector<int> nums) {
    int answer = 0;
    vector<int> temp(3000, 0);
    get(temp);

    for (int i = 0; i < nums.size(); ++i) {
        for (int j = i+1; j < nums.size(); ++j) {
            for (int k = j + 1; k < nums.size(); ++k) {
                int n = nums[i] + nums[j] + nums[k];
                if (temp[n] == 0)
                    ++answer;
            }
        }
    }
    return answer;
}

int main() {
    vector<int> v = { 1,2,3,4 };
    solution(v);
}