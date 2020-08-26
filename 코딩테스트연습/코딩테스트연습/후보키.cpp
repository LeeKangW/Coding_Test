#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

// 어려워서 일단 중지....

void find_one_atrribute(vector<vector<string>>& v, vector<int>& what_is_one_atrribute,int& answer) {
    for (size_t i = 0; i < v.size(); ++i) {
        bool is_exist = false;
        for (size_t j = 0; j < v[i].size(); ++j) {
            string str = v[i][j];
            size_t k = 0;
            while (!is_exist) {
                if (k == j) {
                    ++k;
                    continue;
                }

                if (k >= v[i].size()) break;

                if (str == v[i][k])
                    is_exist = true;
                else
                    ++k;
            }   
        }
        if (!is_exist) {
            what_is_one_atrribute.push_back(i);
            ++answer;
        }
        
    }
}

void combine_atrribute(vector<vector<string>>& atrribute, vector<int>& what_is_one_atrribute, int& answer,size_t combine_num) {
    map<string, int> m;

    for (size_t i = 0; i < atrribute.size()-(combine_num - 1); ++i) {
       if(binary_search(what_is_one_atrribute.cbegin(), what_is_one_atrribute.cend(), i)) continue;

       size_t k = i;
       if (k + combine_num - 1 >= atrribute.size()) break;

       for (size_t j = 0; j < atrribute[0].size(); ++j) {
           string str = "";
          
           for (; k < i + combine_num; ++k) {
               str+=atrribute[k][j];
           }
           m[str]++;
           k = i;
       }
        bool is_exist = false;
        for (auto it = m.begin(); it != m.end(); ++it) {
            if (it->second > 1)
            {
                is_exist = true;
                break;
            }
        }
        if (!is_exist) {
            ++answer;
            return;
        }
        m.clear();
    }
    if (combine_num + 1 > atrribute.size()) return;
    combine_atrribute(atrribute, what_is_one_atrribute, answer, combine_num+1);
}
int solution(vector<vector<string>> relation) {
    int answer = 0;

#pragma region 각 애트리뷰트마다 구분
    vector<vector<string>> temp;
    vector<int> what_is_one_atrribute;
    temp.resize(relation[0].size());

    for (size_t i = 0; i < relation.size(); ++i) {
        vector<string> v = relation[i];

        for (size_t j = 0; j < v.size(); ++j) {
            temp[j].push_back(v[j]);
        }
    }
#pragma endregion
    find_one_atrribute(temp, what_is_one_atrribute,answer);
    combine_atrribute(temp, what_is_one_atrribute, answer, 2);
    return answer;
}
int main() {
    vector<vector<string>> v = { {"100", "ryan", "music", "2"} ,{"200", "apeach", "math", "2"},{"300", "tube", "computer", "3"},{"400", "con", "computer", "4"},{"500", "muzi", "music", "3"},{"600", "apeach", "music", "2" } };
    vector<vector<string>> v2 = { {"a", "b", "c"} ,{"1", "b", "c"},{"a", "b", "4"},{"a", "5", "c"} };

    solution(v2);
}
