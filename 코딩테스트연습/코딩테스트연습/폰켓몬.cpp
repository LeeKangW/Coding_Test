#include <vector>
#include<algorithm>
// ¸µÅ© : https://programmers.co.kr/learn/courses/30/lessons/1845

using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    int total = nums.size();
    sort(nums.begin(), nums.end());
    nums.erase(unique(nums.begin(), nums.end()), nums.end());

    int num = nums.size();

    if (num > total / 2)
        answer = total / 2;
    else
        answer = num;
    return answer;
}