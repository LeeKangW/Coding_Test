#include <string>
#include <vector>
#include <algorithm>

/** 
* @See : https://programmers.co.kr/learn/courses/30/lessons/42884
*/
using namespace std;

int solution(vector<vector<int>> routes)
{
    int answer = 1;

    sort(routes.begin(), routes.end(), [](const vector<int>& a, const vector<int>& b)
        {
            return a[0] < b[0];
        });

    int temp = routes[0][1];
    
    for (int i = 1; i < routes.size() - 1; ++i)
    {
        if (temp > routes[i][1]) temp = routes[i][1];

        if (temp < routes[i+1][0])
        {
            answer += 1;
            temp = routes[i+1][1];
        }
    }
    return answer;
}

int main()
{
    solution({ {-20,15},{-14,-5},{-18,-13},{-5,-3} });
}