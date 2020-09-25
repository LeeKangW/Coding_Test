#include <string>
#include <vector>
#include <queue>
#include <algorithm>

/**
* @See : https://programmers.co.kr/learn/courses/30/lessons/43164
*/
using namespace std;

struct Compare
{
    bool operator()(pair<string, int>& a, pair<string, int>& b)
    {
        if (a.first == b.first)
            return false;
        return a.first > b.first;
    }
};
void Find(vector<vector<string>> tickets, string curAirPort, vector<string>& answer)
{
    answer.push_back(curAirPort);
    if (tickets.empty())
        return;

    priority_queue<pair<string, int>, vector< pair<string, int>>, Compare> pq;

    for (size_t i = 0; i < tickets.size(); i++)
    {
        vector<string> vTmp = tickets[i];
        if (vTmp[0] == curAirPort)
        {
            pq.push(make_pair(vTmp[1], i));
        }
    }

    while (!pq.empty())
    {
        if (tickets.size() <= 1)
            break;

        string tmpStr = pq.top().first;
        bool isExist = false;
        for (size_t i = 0; i < tickets.size(); i++)
        {
            vector<string> vTmp = tickets[i];
            if (vTmp[0] == tmpStr)
            {
                isExist = true;
                break;
            }
        }
        if (isExist)
            break;
        pq.pop();
    }
    tickets.erase(tickets.begin() + pq.top().second);
    Find(tickets, pq.top().first, answer);
}
vector<string> solution(vector<vector<string>> tickets)
{
    vector<string> answer;

    Find(tickets, "ICN", answer);
    return answer;
}