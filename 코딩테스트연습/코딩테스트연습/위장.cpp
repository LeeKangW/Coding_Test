#include <string>
#include <vector>
#include <map>
// 링크 : https://programmers.co.kr/learn/courses/30/lessons/42578
// 참고 : https://shjz.tistory.com/102
using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    map<string, int> temp;
    vector<int> v;
    for (vector<string>& v : clothes) {
        temp[v[1]]++;
    }
    for (auto p : temp)
    {
        answer = answer * (p.second + 1);
    }
    --answer;
  
    return answer;
}

int main() {
    vector<vector<string>> v = { {"yellow_hat", "headgear"},{"blue_sunglasses","eyewear"},{"green_turban","headgear"} };
    solution(v);
}