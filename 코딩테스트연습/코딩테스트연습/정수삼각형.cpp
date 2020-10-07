#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> triangle)
{
	int answer = 0;
	int n = triangle.size();

	for (size_t i = 1; i < n; ++i)
	{

		for (size_t j = 0; j < triangle[i].size(); ++j)
		{
			if (j == 0)
			{
				triangle[i][j] += triangle[i - 1][j];
			}
			else if (j == i)
			{
				triangle[i][j] += triangle[i - 1][j - 1];
			}
			else
			{
				triangle[i][j] += max(triangle[i - 1][j - 1], triangle[i - 1][j]);
			}
		}
	}
	answer = *(max_element(triangle[n - 1].begin(), triangle[n - 1].end()));
	return answer;
}