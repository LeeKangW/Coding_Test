#include <string>
#include <vector>
#include <algorithm>

/**
* 문제가 이상함.... 테스트케이스 1은 모든 티켓을 사용하지 않는 테스트케이스로 구성되어 있음.
* @ Link : https://programmers.co.kr/learn/courses/30/lessons/43164
*/
using namespace std;

bool isFind = false;
vector<int> idx;
int failedCount = 0;
void FindRoute(string nextName, int CurIdx, const vector<vector<string>>& tickets, vector<bool>& check, vector<string>& answer)
{
    if (all_of(check.begin(), check.end(), [](const bool& b) { return b == true; }))
    {
        isFind = true;
        answer.push_back(nextName);
        while (!idx.empty())
        {
            for (int i = 0; i < idx.size(); ++i)
            {
                if (tickets[idx[i]][0] == nextName)
                {
                    answer.push_back(tickets[idx[i]][1]);
                    nextName = tickets[idx[i]][1];
                    idx.erase(idx.begin() + i);
                    break;
                }
            }
        }
        return;
    }
    bool isExist = false;
    for (int i = 0; i < tickets.size(); ++i)
    {
        if ((tickets[i][0] == nextName) && (!check[i]))
        {
            isExist = true;
            check[i] = true;
            answer.push_back(nextName);
            FindRoute(tickets[i][1], i, tickets, check, answer);
            break;
        }
    }
    if (!isExist)
    {
        for (int i = 0; i < check.size(); ++i)
        {
            check[i] = false;
        }

        check[CurIdx] = true;
        idx.push_back(CurIdx);
        if (failedCount < tickets.size()-1)
        {
            answer.clear();
            failedCount += 1;
        }
        else
        {
            failedCount += 1;
        }
        return;
    }
}

vector<string> solution(vector<vector<string>> tickets)
{
    vector<string> answer;
    sort(tickets.begin(), tickets.end(), [](const vector<string>& a, const vector<string>& b)
        {
            return a[1] < b[1];
        });
    vector<bool> check(tickets.size(), false);

    while (!isFind && failedCount < tickets.size())
    {
        for (int i = 0; i < tickets.size(); ++i)
        {
            if (tickets[i][0] == "ICN" && !check[i])
            {
                check[i] = true;
                answer.push_back(tickets[i][0]);
                FindRoute(tickets[i][1], i, tickets, check, answer);
                break;
            }
        }
    }
    return answer;
}