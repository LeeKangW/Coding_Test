#include <string>
#include <vector>
#include <queue>
#include <math.h>
using namespace std;

/**
* works�� �ִ��� ã�Ƽ� n�� 0�� �� ������ -1�� ���ָ� �ȴ�.
* 
* �ִ��� ������ ã�� ���� priority_queue �� ���
* 
* @ Link : https://programmers.co.kr/learn/courses/30/lessons/12927
*/

long long solution(int n, vector<int> works)
{
	long long answer = 0;

	int tmp = 0;
	priority_queue<int> pq;

	// �ʱ� ����
	for (int i = 0; i < works.size(); ++i)
	{
		pq.push(works[i]);
		tmp += works[i];
	}
	if (tmp <= n) return 0; // ���� ó��

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