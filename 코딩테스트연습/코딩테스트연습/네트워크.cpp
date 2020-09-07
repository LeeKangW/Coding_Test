#include <string>
#include <vector>
using namespace std;
/**
* @see : https://programmers.co.kr/learn/courses/30/lessons/43162
*/
// 생각만 잘하면 쉽게 풀 수 있었다.

void find_network(int n, int start, vector<vector<int>>& computers, vector<bool>& visits)
{
	visits[start] = true;

	for (size_t i = 0; i < n; ++i)
	{
		if (!visits[i] && computers[start][i])
			find_network(n, i, computers, visits);
	}
}
int solution(int n, vector<vector<int>> computers)
{
	int answer = 0;
	vector<bool> visits(n, false);

	for (size_t i = 0; i < n; ++i)
	{
		if (!visits[i])
		{
			find_network(n, i, computers, visits);
			++answer;
		}
	}

	return answer;
}