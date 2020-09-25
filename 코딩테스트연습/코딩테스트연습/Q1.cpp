#include <string>
#include <vector>
#include<algorithm>
using namespace std;

vector<int> solution(vector<int> numbers)
{
	vector<int> answer;

	for (size_t i = 0; i < numbers.size() - 1; ++i)
	{
		int n1 = numbers[i];
		for (size_t j = i + 1; j < numbers.size(); ++j)
		{
			int n2 = numbers[j];
			int sum = n1 + n2;
			if (answer.empty())
				answer.push_back(sum);
			else
			{
				if (find(answer.cbegin(), answer.cend(), sum) == answer.cend())
				{
					answer.push_back(sum);
				}
			}
		}
	}

	sort(answer.begin(), answer.end());
	return answer;
}