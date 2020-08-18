#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void add_time(vector<pair<string, size_t>>& v) {
    for (size_t i = 0; i < v.size(); ++i) {
        v[i].second += 1;
    }
}
int solution(int cacheSize, vector<string> cities) {
    int answer = 0;

    if (cacheSize == 0) {
        return 5 * cities.size();
    }
    vector<pair<string, size_t>> cash;
    for (size_t i = 1; i <= cacheSize; ++i) {
        cash.push_back(make_pair(" ", cacheSize-i));
    }

    for (size_t i = 0; i < cities.size(); ++i) {
        string s = cities[i];
        for (size_t j = 0; j < s.size(); ++j) {
            s[j] = tolower(s[j]);
        }
        cities[i] = s;
    }

    for (size_t i = 0; i < cities.size(); ++i) {
        string str_temp = cities[i];
        add_time(cash);
            bool is_exist = false;
            for (size_t k = 0; k < cash.size(); ++k) {
                if (cash[k].first == str_temp)
                {
                    cash[k].second = 0;
                    is_exist = true;
                    answer += 1;
                    break;
                }
            }

            if (!is_exist) {
                auto it = max_element(cash.begin(), cash.end(), [](const pair<string, size_t> a, const pair<string, size_t> b) {
                    return a.second < b.second;
                    });
                it->first = str_temp;
                it->second = 0;
                answer += 5;
            }
        }
    return answer;
    }

int main() {
    vector<string> v = { "Jeju", "Pangyo", "Seoul", "NewYork", "LA", "Jeju", "Pangyo", "Seoul", "NewYork", "LA" };
    solution(3,v);
}