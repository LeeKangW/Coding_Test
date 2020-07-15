#include <string>
#include <vector>
#include<algorithm>
// ¸µÅ© : https://programmers.co.kr/learn/courses/30/lessons/12935

using namespace std;

vector<int> solution(vector<int> arr) {
    
    arr.erase(min_element(arr.begin(), arr.end()));
    if (arr.empty())
        arr.push_back(-1);
    return arr;
}