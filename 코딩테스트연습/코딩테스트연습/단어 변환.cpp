#include<queue>
#include<algorithm>
#include<iostream>
/**
* @ See : https://programmers.co.kr/learn/courses/30/lessons/43163
*/
using namespace std;

priority_queue<int, vector<int>,greater<int>> pq;
bool IsLast(string& begin, string& target)
{
    size_t same = 0;
    for (size_t i = 0; i < target.size(); i++)
    {
        if (begin[i] == target[i])
            same += 1;
    }
    if (same == target.size() - 1)
        return true;
    return false;
}
void Find(string begin, string& target, vector<string>& words, int count)
{

    if (IsLast(begin, target))
    {
        pq.push(++count);
        return;
    }

    for (size_t i = 0; i < words.size(); ++i)
    {
        string strTmp = words[i];
        size_t differ = 0;
        for (size_t j = 0; j < strTmp.size(); j++)
        {
            if (strTmp[j] != begin[j])
                differ += 1;
        }
        if (differ == 1)
        {
            vector<string> s = words;
            s.erase(s.begin() + i);
            Find(strTmp, target, s, ++count);
        }
    }
}
int solution(string begin, string target, vector<string> words)
{
    int answer = 0;

    if (find(words.cbegin(), words.cend(), target) == words.cend())
        return 0;
    Find(begin, target, words, 0);

    if (pq.empty())
        return 0;
    answer = pq.top();
    return answer;
}
int main()
{
    vector<string> words = { "hot", "dot", "dog", "lot", "log", "cog" };
    vector<string> words2 = { "hot", "dot", "dog", "lot", "log", "cog" };
    vector<string> words3 = { "hhh","hht" };

    cout << solution("hit", "cog", { "hot", "dot", "dog", "lot", "log", "cog" }) << endl;
    cout << solution("hit", "cog", { "hot", "dot", "dog", "lot", "log" }) << endl;
    cout << solution("hot", "lot", { "dot", "dog", "lot", "log" }) << endl;
    cout << solution("hit", "wow", { "hot", "dot", "dog", "lot", "log", "cog", "wow" }) << endl;

}