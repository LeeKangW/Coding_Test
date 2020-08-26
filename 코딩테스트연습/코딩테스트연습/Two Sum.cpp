#include <vector>
#include <iostream>

using namespace std;

// ¸µÅ© : https://leetcode.com/problems/two-sum/

class Solution
{
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        vector<int> answer(2,0);
        for (size_t i = 0; i < nums.size()-1; ++i)
        {
            int n1 = nums[i];
            for (size_t j = i+1; j < nums.size(); ++j)
            {
                int n2 = nums[j];
                if (n1 + n2 == target)
                {
                    answer[0] = i;
                    answer[1] = j;
                    return answer;
                }
            }
        }
        return answer;
    }
};
