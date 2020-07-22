#include <string>
#include <vector>
#include <queue>
using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    answer.reserve(100000);

    int save_n = 0, count = 0;
    for (int i = 0; i < prices.size(); ++i) {
        if (i == prices.size() - 1) 
        {
            answer.push_back(0);
            break;
        }
        save_n = prices[i];
        for (int j = i+1; j < prices.size(); ++j) {
            if (save_n > prices[j]) {
                ++count;
                break;
            }
            ++count;
        }
        answer.push_back(count);
        count = 0;
    }

    return answer;
}

int main() {
    vector<int> v = { 1,2,3,2,3 };
    solution(v);
}