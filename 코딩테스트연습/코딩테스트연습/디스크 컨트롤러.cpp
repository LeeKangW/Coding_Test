#include <string>
#include <vector>
#include <queue>
#include<algorithm>
using namespace std;

/**
* 접근 방법은 똑같았지만, 우선순위 큐 비교 방법을 struct로 만들어 주는 것을 몰라 오래 걸렸다.
* 
* struct로 비교 방법 재정의 하는 것을 잘 활용해야 쉽게 풀 수 있는 문제.
* 
* @ 참고링크 : https://greenapple16.tistory.com/124?category=811354
* @ 프로그래머스 : https://programmers.co.kr/learn/courses/30/lessons/42627
*/
struct comp
{
    bool operator()(vector<int>a, vector<int>b)
    {
        return a[1] > b[1];
    }
};

int solution(vector<vector<int>> jobs)
{
    int answer = 0;
    sort(jobs.begin(), jobs.end());
    priority_queue < vector<int>, vector<vector<int>>,comp> pq;
    vector<int> temp;

    int currentTime = 0;
    int timeSum = 0;
    int index = 0;
    int jobsLeft = jobs.size();

    while (jobsLeft > 0)
    {
        while ((index < jobs.size()) && (jobs[index][0] <= currentTime))
        {
            pq.push(jobs[index]);
            index++;
        }
        if (!pq.empty())
        {
            temp = pq.top();
            if (temp[0] <= currentTime)
            {
                timeSum += (currentTime - temp[0]) + temp[1];
                pq.pop();
                jobsLeft--;
                currentTime += temp[1];
            }
            else
            {
                currentTime = temp[0];
            }
        }
        else
        {
            currentTime++;
        }
    }
    return (timeSum / jobs.size());



    return answer;
}

int main()
{
    vector<vector<int>> v = { {0,3},{1,9},{2,6} };
    vector<vector<int>> v2 = { {0,10},{2,10},{25,10},{25,2} };
    solution(v);
}