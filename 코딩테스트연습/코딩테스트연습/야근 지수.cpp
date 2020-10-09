#include <string>
#include <vector>
#include <queue>
#include <math.h>
using namespace std;

/**
* works의 최댓값을 찾아서 n이 0이 될 때까지 -1씩 해주면 된다.
* 
* 최댓값을 빠르게 찾기 위해 priority_queue 를 사용
* 
* @ Link : https://programmers.co.kr/learn/courses/30/lessons/12927
*/

long long solution(int n, vector<int> works)
{
	long long answer = 0;

	int tmp = 0;
	priority_queue<int> pq;

	// 초기 세팅
	for (int i = 0; i < works.size(); ++i)
	{
		pq.push(works[i]);
		tmp += works[i];
	}
	if (tmp <= n) return 0; // 예외 처리

	while (n != 0)
	{
		int num = pq.top();
		pq.pop();
		pq.push(num - 1);
		n -= 1;
	}

	while (!pq.empty())
	{
		answer += pow(pq.top(), 2); pq.pop();
	}
	return answer;
}