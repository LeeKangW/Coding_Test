#include <vector>
#include <iostream>
#include<algorithm>

// ¸µÅ© : https://programmers.co.kr/learn/courses/30/lessons/12906

using namespace std;

vector<int> solution(vector<int> arr)
{
    arr.erase(unique(arr.begin(), arr.end()), arr.end());
    return arr;
}

int main() {
    vector<int> v = { 1,1,3,3,0,1,1 };
    for (int i : solution(v))
        cout << i << ", ";
}