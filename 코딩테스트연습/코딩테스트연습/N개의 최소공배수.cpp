#include <string>
#include <vector>
#include<algorithm>
// ¸µÅ© : https://programmers.co.kr/learn/courses/30/lessons/12953

using namespace std;

int solution(vector<int> arr) {
    int answer = 0;
    sort(arr.begin(), arr.end());
    auto it = max_element(arr.begin(), arr.end());
    bool is_right = true;
    int n = *it;
    for (int i = 1;; ++i) {
        int temp = n * i;
        for (auto j = arr.begin(); j != it; ++j) {
            if (temp % *j != 0)
            {
                is_right = false;
                break;
            }
        }
        if (is_right) {
            answer = temp;
            break;
        }
        else
            is_right = true;
    }

    return answer;
}