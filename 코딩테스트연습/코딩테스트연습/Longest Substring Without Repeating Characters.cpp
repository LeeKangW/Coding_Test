#include<string>
#include<vector>
#include<set>
#include<queue>

using namespace std;

/**
* 
* @ See : https://leetcode.com/problems/longest-substring-without-repeating-characters/
*/

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        string strTemp = "";
        set<char> setTemp;
        priority_queue<pair<int,string>> pq;
        
        for (size_t i = 0; i < s.size(); i++)
        {
            char c = s[i];
            if (setTemp.find(c) != setTemp.end())
            {
                pq.push(make_pair(strTemp.size(), strTemp));

                auto it = find(strTemp.begin(), strTemp.end(), c);
                size_t idx = distance(strTemp.begin(), it);

                for (size_t i = 0; i < idx + 1; i++)
                {
                    setTemp.erase(strTemp.at(i));
                }
                strTemp.erase(strTemp.begin(), it + 1);
            }
            strTemp += c;
            setTemp.insert(c);
        }
        if (!strTemp.empty())
            pq.push(make_pair(strTemp.size(), strTemp));

        if (pq.empty())
            return 0;

        return pq.top().first;
    }
};

int main()
{
    Solution s;
    s.lengthOfLongestSubstring("abcabcbb");
}