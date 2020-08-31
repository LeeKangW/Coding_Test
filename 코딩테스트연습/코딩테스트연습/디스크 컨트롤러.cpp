#include <string>
#include <vector>
#include <queue>
#include<algorithm>
using namespace std;

/**
* ���� ����� �Ȱ�������, �켱���� ť �� ����� struct�� ����� �ִ� ���� ���� ���� �ɷȴ�.
* 
* struct�� �� ��� ������ �ϴ� ���� �� Ȱ���ؾ� ���� Ǯ �� �ִ� ����.
* 
* @ ����ũ : https://greenapple16.tistory.com/124?category=811354
* @ ���α׷��ӽ� : https://programmers.co.kr/learn/courses/30/lessons/42627
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