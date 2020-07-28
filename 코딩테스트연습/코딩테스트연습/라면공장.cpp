#include <string>
#include <vector>
#include <algorithm>
// ¸µÅ© : https://programmers.co.kr/learn/courses/30/lessons/42629

using namespace std;

int solution(int stock, vector<int> dates, vector<int> supplies, int k) {
    int answer = 0;
    int date = 0;
    int idx = 0;
    while (date < k) {
        if (stock == 0) {
            auto it = find_if_not(dates.begin(), dates.end(), [&date](const int& a) {
                return a < date;
                });
            if (it != dates.end())
                idx = distance(dates.begin(), it);
            else
                idx = dates.size();
            
            it = max_element(supplies.begin(), supplies.begin() + idx);
            int num = distance(supplies.begin(), it);
            stock += *it;
            supplies.erase(it);
            dates.erase(dates.begin() + num);
            ++answer;
        }
        --stock;
        ++date;

    }
    return answer;
}

int main() {
    vector<int> v = { 4,10,15 };
    vector<int> v2 = { 20,5,10 };
    solution(4, v, v2, 30);
}