#include <string>
#include<vector>
#include<math.h>
// ¸µÅ© : https://programmers.co.kr/learn/courses/30/lessons/17682

using namespace std;

int set_area(int n,char& c) {
    switch (c)
    {
    case 'S':
        return n;
    case 'D':
        return pow(n, 2);
    case 'T':
        return pow(n, 3);
    }
}
void set_option(vector<int>& v,int idx,char& c) {
    switch (c)
    {
    case '*':
        if (v.size() == 1)
            v[0] *= 2;
        else {
            v[idx] *= 2;
            v[--idx] *= 2;
        }
        break;
    case '#':
        v[idx] *= -1;
        break;
    }
}
int solution(string dartResult) {
    int answer = 0;
    string save_str = "";
    vector<int> v;
    v.reserve(dartResult.size());
    bool exist_opt = false;
    for (int i = 0; i < dartResult.size(); ++i) {
        if (isdigit(dartResult[i]))
            save_str += dartResult[i];
        else {
            if (!save_str.empty())
            {
                v.push_back(stoi(save_str));
                save_str.clear();
            }
            switch (dartResult[i])
            {
            case 'S':
            case 'D':
            case 'T':
                v[v.size()-1] = set_area(v.back(), dartResult[i]);
                break;
            case '*':
            case '#':
                set_option(v, v.size()-1, dartResult[i]);
                break;
            }
        }

    }

    for (int n : v)
        answer += n;

    return answer;
}

int main() {
    solution("1D2S#10S");
}