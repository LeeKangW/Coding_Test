#include <string>
#include <vector>
#include <utility>

// 링크 : https://programmers.co.kr/learn/courses/30/lessons/42583

using namespace std;

int get_sum(vector<pair<int, int>>& v) {
    int sum = 0;
    for (int i = 0; i < v.size(); ++i) {
        sum += v[i].first;
    }
    return sum;
}
void time_run(vector<pair<int, int>>& v,int length) {
    for (pair<int, int>& p : v) {
        ++p.second;
    }
    for (auto it = v.begin(); it != v.end(); ++it) {
        if (it->second > length)
        {
            v.erase(it);
            break;
        }
    }
}
int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int timer = 0, on_bridge_timer = 1;
    vector<pair<int,int>> bridge; // first : 무게 , sescond : 시간

    for (int i = 0; i < truck_weights.size();) {
        ++timer;
        time_run(bridge, bridge_length);
        if (get_sum(bridge) + truck_weights[i] <= weight) {
            bridge.push_back(make_pair(truck_weights[i], on_bridge_timer));
            ++i;
        }
   }
    while (!bridge.empty()) {
        ++timer;
        time_run(bridge, bridge_length);
    }
    answer = timer;
    return answer;
}

int main() {
    vector<int> v = { 7,4,5,6 };
    solution(2, 10, v);
}