#include <string>
#include <vector>
#include <queue>
#include <map>
#include <tuple>
#include <algorithm>
/**
* 
* @ See : https://programmers.co.kr/learn/courses/30/lessons/42579
*/
using namespace std;

struct Comp
{
    bool operator()(pair<string, int> a, pair<string, int> b)
    {
        return a.second < b.second;
    }
};
vector<int> solution(vector<string> genres, vector<int> plays)
{
    vector<int> answer;
    
    vector<tuple<string, int,int>> songs; songs.reserve(genres.size());
    priority_queue<pair<string, int>,vector<pair<string,int>>,Comp> pq;

    map<string, int> tmp_PlayTime;
    
    for (size_t i = 0; i < genres.size(); i++)
    {
        tmp_PlayTime[genres[i]] += plays[i];

        songs.push_back(make_tuple(genres[i], plays[i],i));
    }
    for (auto it = tmp_PlayTime.begin(); it != tmp_PlayTime.end(); ++it)
    {
        pq.push(make_pair(it->first, it->second));
    }

    // 위에서 장르에 맞춰 최대 개수를 정리.

    sort(songs.begin(), songs.end(), [](tuple<string, int, int>& a, tuple<string, int, int>& b)
        {
            return get<1>(a) > get<1>(b);
        });
    while (!pq.empty())
    {
        string str = pq.top().first;
        size_t count = 0;
        for (size_t i = 0; i < songs.size(); i++)
        {
            if (count == 2)
                break;
            if (get<0>(songs[i]) == str)
            {
                answer.push_back(get<2>(songs[i]));
                count += 1;
            }
        }
        pq.pop();
    }

    return answer;
}
int main()
{
    vector<string> genres = { "classic", "pop", "classic", "classic", "pop" };
    vector<int> plays = { 500, 600, 150, 800, 2500 };
    solution(genres, plays);
}